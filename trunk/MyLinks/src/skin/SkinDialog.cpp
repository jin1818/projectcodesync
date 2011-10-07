// SkinDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SkinDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma warning(disable: 4355)

#define ID_MENU_BAR (AFX_IDW_TOOLBAR+105)

/////////////////////////////////////////////////////////////////////////////
// CSkinDialog dialog


//CSkinDialog::CSkinDialog(CWnd* pParent /*=NULL*/)
//{
	//{{AFX_DATA_INIT(CSkinDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//}

CSkinDialog::CSkinDialog(UINT uResourceID, CWnd* pParent, bool bIgnoreCancelKey)
: CXTPDialog(uResourceID, pParent), CXTResize(this)
{
	m_nButtonMove = -1;
	m_nButtonDown = -1;
	m_bIgnoreCancelKey = bIgnoreCancelKey;
}

void CSkinDialog::DoDataExchange(CDataExchange* pDX)
{
	CXTPDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSkinDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSkinDialog, CXTPDialog)
	//{{AFX_MSG_MAP(CSkinDialog)
	ON_WM_PAINT()
	ON_WM_NCPAINT()
	ON_WM_NCACTIVATE()
	ON_WM_SIZE()
	ON_WM_NCCALCSIZE()
	ON_WM_ERASEBKGND()
	ON_WM_GETMINMAXINFO()
	ON_WM_NCMOUSEMOVE()
	ON_WM_NCLBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CTLCOLOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_NCHITTEST()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinDialog message handlers

BOOL CSkinDialog::OnInitDialog() 
{
	CXTPDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_anchor.Init(m_hWnd);
	// ModifyStyle( WS_CAPTION, WS_MINIMIZEBOX, SWP_DRAWFRAME );
	// ModifyStyle(WS_SYSMENU, 0);

	/*
	if(GetExStyle()&WS_EX_TOOLWINDOW)
	{	
		CMenu * pMenu = AfxGetMainWnd()->GetSystemMenu(FALSE);
		if(pMenu)  	
		{  
			pMenu->EnableMenuItem(SC_CLOSE,MF_BYCOMMAND|MF_GRAYED);
		}
	}
	*/

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

bool CSkinDialog::HasStyle(DWORD dwStyle)
{
	return (m_dwStyle&dwStyle)==0?false:true;
}

void CSkinDialog::DrawFrame(Graphics & graphics)
{
	CRect rcWindow;
	GetWindowRect(&rcWindow);

	Rect rc, rc1;

	// Title Left
	rc = m_bActive?m_mapRect["TitleLeftActive"]:m_mapRect["TitleLeft"];
	rc1.X = 0;
	rc1.Y = 0;
	rc1.Width = rc.Width;
	rc1.Height = rc.Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Title Center
	rc = m_bActive?m_mapRect["TitleCenterActive"]:m_mapRect["TitleCenter"];
	rc1.X = m_mapRect["TitleLeftActive"].Width;
	rc1.Y = 0;
	rc1.Width = rcWindow.Width()-m_mapRect["TitleLeftActive"].Width-m_mapRect["TitleRightActive"].Width;
	rc1.Height = rc.Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Title Right
	rc = m_bActive?m_mapRect["TitleRightActive"]:m_mapRect["TitleRight"];
	rc1.X = rc1.GetRight();
	rc1.Y = 0;
	rc1.Width = rc.Width;
	rc1.Height = rc.Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Border Left
	rc = m_bActive?m_mapRect["BorderLeftActive"]:m_mapRect["BorderLeft"];
	rc1.X = 0;
	rc1.Y = m_mapRect["TitleLeft"].Height;
	rc1.Width = rc.Width;
	rc1.Height = rcWindow.Height()-m_mapRect["TitleLeftActive"].Height-m_mapRect["BorderBotActive"].Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Border Bottom
	rc = m_bActive?m_mapRect["BorderBotActive"]:m_mapRect["BorderBot"];
	rc1.X = 0;
	rc1.Y = rcWindow.Height()-rc.Height-1;
	rc1.Width = rcWindow.Width();
	rc1.Height = rc.Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Border Right
	rc = m_bActive?m_mapRect["BorderRightActive"]:m_mapRect["BorderRight"];
	rc1.X = rcWindow.Width()-rc.Width-1;
	rc1.Y = m_mapRect["TitleLeftActive"].Height;
	rc1.Width = rc.Width;
	rc1.Height = rcWindow.Height()-m_mapRect["TitleLeftActive"].Height-m_mapRect["BorderBotActive"].Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Close Button
	rc = m_nButtonDown==HT_CLOSE?m_mapRect["NcBtnCloseDown"]:m_mapRect["NcBtnClose"];
	rc1.X = rcWindow.Width()-m_mapRect["NcBtnClosePos"].X;
	rc1.Y = m_mapRect["NcBtnClosePos"].Y;
	rc1.Width = rc.Width;
	rc1.Height = rc.Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Max Button
	if(GetStyle()&WS_MAXIMIZEBOX)
	{
		rc = IsZoomed()?(m_nButtonDown==HT_MAX?m_mapRect["NcBtnResDown"]:m_mapRect["NcBtnRes"]):(m_nButtonDown==HT_MAX?m_mapRect["NcBtnMaxDown"]:m_mapRect["NcBtnMax"]);
		rc1.X = rcWindow.Width()-m_mapRect["NcBtnMaxPos"].X;
		rc1.Y = m_mapRect["NcBtnMaxPos"].Y;
		rc1.Width = rc.Width;
		rc1.Height = rc.Height;
		graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);
	}

	// Min Button
	if(GetStyle()&WS_MINIMIZEBOX)
	{
		rc = m_nButtonDown==HT_MIN?m_mapRect["NcBtnMinDown"]:m_mapRect["NcBtnMin"];
		rc1.X = rcWindow.Width()-m_mapRect["NcBtnMinPos"].X;
		rc1.Y = m_mapRect["NcBtnMinPos"].Y;
		rc1.Width = rc.Width;
		rc1.Height = rc.Height;
		graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);
	}
	
	Font myFont(L"宋体", 9);
	Color col(255,0,0,0);
	col.SetFromCOLORREF(m_mapColor["Caption"]);
	SolidBrush blackBrush(col);
	
	StringFormat format;
	format.SetAlignment(StringAlignmentNear);	
	
	RectF layoutRect(::GetSystemMetrics(SM_CYICON)+m_mapRect["TitleTextStart"].X, m_mapRect["TitleTextStart"].Y, rcWindow.Width(), rcWindow.Height());
	
	WCHAR string[MAX_PATH] = {0};
	CString str;
	GetWindowText(str);
	
	MultiByteToWideChar( CP_ACP, 0, str, -1, string, MAX_PATH) ;
	
	graphics.DrawString(string,	-1, &myFont, layoutRect, &format, &blackBrush);
}

void CSkinDialog::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here

	if(!CImgSkin::IsLoaded())
	{
		CXTPDialog::OnPaint();
		return;
	}

	Rect rc, rc1;
	CRect rcWindow;
	GetClientRect(&rcWindow);

	Bitmap bmpBuf(rcWindow.Width(), rcWindow.Height());
	Graphics graphics(&bmpBuf);
	Graphics g(dc.GetSafeHdc());

	// dialog frame
	//if(!HasStyle(WS_CHILD))
	//	DrawFrame(g);

	rc = m_mapRect["Background"];

	// Top
	rc1.X = rcWindow.left;
	rc1.Y = rcWindow.top;
	rc1.Width = rc.Width/3;
	rc1.Height = rc.Height/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width/3, rc.Height/3, UnitPixel);

	rc1.X = rcWindow.left+rc.Width/3;
	rc1.Width = rcWindow.Width()-rc.Width/3*2;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft()+rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height/3, UnitPixel);

	rc1.X = rcWindow.right-rc.Width/3;
	rc1.Width = rc.Width/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetRight()-rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height/3, UnitPixel);


	//Center
	rc1.X = rcWindow.left;
	rc1.Y = rcWindow.top+rc.Height/3;
	rc1.Width = rc.Width/3;
	rc1.Height = rcWindow.bottom-rc.Height/3*2;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop()+rc.Height/3, rc.Width/3, rc.Height/3, UnitPixel);

	rc1.X = rcWindow.left+rc.Width/3;
	rc1.Width = rcWindow.Width()-rc.Width/3*2;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft()+rc.Width/3, rc.GetTop()+rc.Height/3, rc.Width/3, rc.Height/3, UnitPixel);

	rc1.X = rcWindow.right-rc.Width/3;
	rc1.Width = rc.Width/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetRight()-rc.Width/3, rc.GetTop()+rc.Height/3, rc.Width/3, rc.Height/3, UnitPixel);

	//Bottom
	rc1.X = rcWindow.left;
	rc1.Y = rcWindow.bottom-rc.Height/3;
	rc1.Width = rc.Width/3;
	rc1.Height = rc.Height/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetBottom()-rc.Height/3, rc.Width/3, rc.Height/3, UnitPixel);

	rc1.X = rcWindow.left+rc.Width/3;
	rc1.Width = rcWindow.right-rc.Width/3*2;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft()+rc.Width/3, rc.GetBottom()-rc.Height/3, rc.Width/3, rc.Height/3, UnitPixel);

	rc1.X = rcWindow.right-rc.Width/3;
	rc1.Width = rc.Width/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetRight()-rc.Width/3, rc.GetBottom()-rc.Height/3, rc.Width/3, rc.Height/3, UnitPixel);

	g.DrawImage(&bmpBuf, 0, 0);
	// Do not call CXTPDialog::OnPaint() for painting messages
}

void CSkinDialog::OnNcPaint() 
{
	// TODO: Add your message handler code here

	if(!CImgSkin::IsLoaded())
	{
		CXTPDialog::OnNcPaint();
		return;
	}

	if(HasStyle(WS_CHILD))
	{
		return;
	}

	/*
	RECT ClientRect;
	GetClientRect(&ClientRect);
	OffsetRect(&ClientRect, 100, 100);
	ExcludeClipRect(GetWindowDC()->GetSafeHdc(), ClientRect.left, ClientRect.top,
		ClientRect.right, ClientRect.bottom);
	*/

	CRect rcWindow;
	GetWindowRect(&rcWindow);
	
	Bitmap bmpBuf(rcWindow.Width(), rcWindow.Height());
	Graphics graphics(&bmpBuf);
	Graphics g(GetWindowDC()->GetSafeHdc());

	Rect rc, rc1;

	// Title Left
	rc = m_bActive?m_mapRect["TitleLeftActive"]:m_mapRect["TitleLeft"];
	rc1.X = 0;
	rc1.Y = 0;
	rc1.Width = rc.Width;
	rc1.Height = rc.Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Title Center
	rc = m_bActive?m_mapRect["TitleCenterActive"]:m_mapRect["TitleCenter"];
	rc1.X = m_mapRect["TitleLeftActive"].Width;
	rc1.Y = 0;
	rc1.Width = rcWindow.Width()-m_mapRect["TitleLeftActive"].Width-m_mapRect["TitleRightActive"].Width;
	rc1.Height = rc.Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Title Right
	rc = m_bActive?m_mapRect["TitleRightActive"]:m_mapRect["TitleRight"];
	rc1.X = rc1.GetRight();
	rc1.Y = 0;
	rc1.Width = rc.Width;
	rc1.Height = rc.Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Border Left
	rc = m_bActive?m_mapRect["BorderLeftActive"]:m_mapRect["BorderLeft"];
	rc1.X = 0;
	rc1.Y = m_mapRect["TitleLeftActive"].Height;
	rc1.Width = rc.Width;
	rc1.Height = rcWindow.Height()-m_mapRect["TitleLeftActive"].Height-m_mapRect["BorderBotActive"].Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Border Bottom
	rc = m_bActive?m_mapRect["BorderBotActive"]:m_mapRect["BorderBot"];
	rc1.X = 0;
	rc1.Y = rcWindow.Height()-rc.Height-1;
	rc1.Width = rcWindow.Width();
	rc1.Height = rc.Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Border Right
	rc = m_bActive?m_mapRect["BorderRightActive"]:m_mapRect["BorderRight"];
	rc1.X = rcWindow.Width()-rc.Width-1;
	rc1.Y = m_mapRect["TitleLeftActive"].Height;
	rc1.Width = rc.Width;
	rc1.Height = rcWindow.Height()-m_mapRect["TitleLeftActive"].Height-m_mapRect["BorderBotActive"].Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Close Button
	rc = m_nButtonDown==HT_CLOSE?m_mapRect["NcBtnCloseDown"]:m_mapRect["NcBtnClose"];
	rc1.X = rcWindow.Width()-m_mapRect["NcBtnClosePos"].X;
	rc1.Y = m_mapRect["NcBtnClosePos"].Y;
	rc1.Width = rc.Width;
	rc1.Height = rc.Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	// Max Button
	if(GetStyle()&WS_MAXIMIZEBOX)
	{
		rc = IsZoomed()?(m_nButtonDown==HT_MAX?m_mapRect["NcBtnResDown"]:m_mapRect["NcBtnRes"]):(m_nButtonDown==HT_MAX?m_mapRect["NcBtnMaxDown"]:m_mapRect["NcBtnMax"]);
		rc1.X = rcWindow.Width()-m_mapRect["NcBtnMaxPos"].X;
		rc1.Y = m_mapRect["NcBtnMaxPos"].Y;
		rc1.Width = rc.Width;
		rc1.Height = rc.Height;
		graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);
	}

	// Min Button
	if(GetStyle()&WS_MINIMIZEBOX)
	{
		rc = m_nButtonDown==HT_MIN?m_mapRect["NcBtnMinDown"]:m_mapRect["NcBtnMin"];
		rc1.X = rcWindow.Width()-m_mapRect["NcBtnMinPos"].X;
		rc1.Y = m_mapRect["NcBtnMinPos"].Y;
		rc1.Width = rc.Width;
		rc1.Height = rc.Height;
		graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);
	}
	
	Font myFont(L"宋体", 9);
	Color col(255,0,0,0);
	col.SetFromCOLORREF(m_mapColor["Caption"]);
	SolidBrush blackBrush(col);
	
	StringFormat format;
	format.SetAlignment(StringAlignmentNear);	
	
	RectF layoutRect(::GetSystemMetrics(SM_CYICON)+m_mapRect["TitleTextStart"].X, m_mapRect["TitleTextStart"].Y, rcWindow.Width(), rcWindow.Height());
	
	WCHAR string[MAX_PATH] = {0};
	CString str;
	GetWindowText(str);
	
	MultiByteToWideChar( CP_ACP, 0, str, -1, string, MAX_PATH) ;
	
	graphics.DrawString(string,	-1, &myFont, layoutRect, &format, &blackBrush);
	
	g.DrawImage(&bmpBuf, 0, 0);
	
	// Do not call CXTPDialog::OnNcPaint() for painting messages
}

bool CSkinDialog::LoadSkin(const char * szSkinPath /* = NULL */, const char * szControlName)
{
	if(szSkinPath==NULL)
	{
		CImgSkin::Unload();
		return true;
	}

	if(!CImgSkin::Load(szSkinPath, szControlName))
		return false;

	m_dwStyle = GetStyle();

	// 去掉标题栏，边框，只留客户区
	// ModifyStyle(WS_CAPTION|WS_THICKFRAME, 0);
	ModifyStyle(WS_CAPTION, 0);
	
	CRect rcWindow;
	CRect rcClient;
	CRect rc;

	GetWindowRect(&rcWindow);
	GetClientRect(&m_rcClient);
	
	// 圆角
	SetWindowRgn(CreateRoundRectRgn(0, 0, rcWindow.Width(), rcWindow.Height(), m_mapRect["RoundCorner"].Width, m_mapRect["RoundCorner"].Height), TRUE);

	if(!HasStyle(WS_CHILD))
	{	
		// 调整窗口自己
		rcWindow.left -= m_mapRect["BorderLeft"].Width;
		rcWindow.right += m_mapRect["BorderRight"].Width;
		rcWindow.top -= m_mapRect["TitleLeft"].Height;
		rcWindow.bottom += m_mapRect["BorderBot"].Height;

		CWnd * pParent = GetParent();
		if(pParent==NULL) pParent = GetDesktopWindow();
		//pParent->ScreenToClient(&rcWindow);
		//MoveWindow(rcWindow, FALSE);

		GetClientRect(&rcClient);

		POINT ptOffset = {0};
		CRect rcChild;
		CWnd* pWndChild;

		// 菜单
		CMenu * pMenu = GetMenu();
		if(pMenu)
		{
			m_wndMenuBar.CreateToolBar(WS_VISIBLE|WS_CHILD|CBRS_TOOLTIPS, this, ID_MENU_BAR);
			m_wndMenuBar.LoadMenu(pMenu);
			m_wndMenuBar.SetFlags(xtpFlagStretched);
			SetMenu(NULL);
			CXTPPaintManager::SetTheme(xtpThemeOffice2003);
			m_wndMenuBar.LoadSkin(szSkinPath);

			RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0, reposDefault, NULL, &rcClient);
			AddAnchor(m_wndMenuBar, ANCHOR_TOPLEFT|ANCHOR_TOPRIGHT);

			m_wndMenuBar.GetWindowRect(&rc);

			ptOffset.y += rc.Height();

			pWndChild = GetWindow(GW_CHILD);
			while (pWndChild)
			{
				if(pWndChild!=&m_wndMenuBar)
				{
					pWndChild->GetWindowRect(rcChild);
					rcChild.OffsetRect(ptOffset);
					ScreenToClient(&rcChild);
					pWndChild->MoveWindow(rcChild, FALSE);
				}
				pWndChild = pWndChild->GetNextWindow();
			}
		}

		// 调整子窗口
		/*
		ptOffset.x = m_mapRect["BorderLeft"].Width;
		ptOffset.y = m_mapRect["TitleLeft"].Height;

		pWndChild = GetWindow(GW_CHILD);
		while (pWndChild)
		{
			pWndChild->GetWindowRect(rcChild);
			rcChild.OffsetRect(ptOffset);
			ScreenToClient(&rcChild);
			pWndChild->MoveWindow(rcChild, FALSE);
			pWndChild = pWndChild->GetNextWindow();
		}


		m_rcClient.left = ptOffset.x;
		m_rcClient.right = m_rcClient.left+rcClient.Width();
		m_rcClient.top += ptOffset.y;
		m_rcClient.bottom = m_rcClient.top+rcClient.Height();
		*/
	}

	return true;
}

BOOL CSkinDialog::OnNcActivate(BOOL bActive) 
{
	// TODO: Add your message handler code here and/or call default
	m_bActive = bActive?true:false;
	OnNcPaint();
	return TRUE;
	// return CXTPDialog::OnNcActivate(bActive);
}

void CSkinDialog::OnSize(UINT nType, int cx, int cy) 
{
	CXTPDialog::OnSize(nType, cx, cy);
	
	if(CImgSkin::IsLoaded())
	{
		CRect Rect;
		GetWindowRect(&Rect);
		SetWindowRgn(CreateRoundRectRgn(0, 0, Rect.Width(), Rect.Height(), m_mapRect["RoundCorner"].Width, m_mapRect["RoundCorner"].Height), TRUE);
		Invalidate(TRUE);
	}

	m_anchor.OnSize();
}

void CSkinDialog::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp) 
{
	// TODO: Add your message handler code here and/or call default

	if(CImgSkin::IsLoaded() && !((GetStyle()&WS_CHILD)))
	{
		int cyFrame = GetSystemMetrics(SM_CYFRAME);
		int cyBorder = GetSystemMetrics(SM_CYBORDER);
		int cxBorder = GetSystemMetrics(SM_CXBORDER);
		
		if(GetExStyle()&WS_EX_TOOLWINDOW)
		{
			NONCLIENTMETRICS   ncm;  
			ncm.cbSize   =   sizeof(NONCLIENTMETRICS);  
			
			SystemParametersInfo(  
				SPI_GETNONCLIENTMETRICS,  
				sizeof(NONCLIENTMETRICS),
				&ncm,  
				0);  
			lpncsp->rgrc[0].top -= cyFrame + cyBorder - m_mapRect["TitleLeftActive"].Height;
		}
		else
			//lpncsp->rgrc[0].top -= cyFrame - m_mapRect["TitleLeftActive"].Height - ((GetStyle()&DS_MODALFRAME)?cyBorder:1);
		lpncsp->rgrc[0].top -= cyFrame - m_mapRect["TitleLeftActive"].Height - cyBorder;
		
		lpncsp->rgrc[0].left -= cyFrame - m_mapRect["BorderLeftActive"].Width- cxBorder;//((GetStyle()&DS_MODALFRAME)?cxBorder:0);
		lpncsp->rgrc[0].right += cyFrame - m_mapRect["BorderRightActive"].Width-cxBorder-cxBorder;//((GetStyle()&DS_MODALFRAME)?cxBorder:0);
		lpncsp->rgrc[0].bottom += m_mapRect["BorderBot"].Height;// -= cyFrame - m_mapRect["BorderBotActive"].Height-cyBorder-cyBorder;//((GetStyle()&DS_MODALFRAME)?cyBorder:0);
	}
	
	CXTPDialog::OnNcCalcSize(bCalcValidRects, lpncsp);
}

bool CSkinDialog::AddAnchor(UINT nID, UINT nFlag)
{
	m_anchor.Remove(nID);
	return m_anchor.Add(nID, nFlag)?true:false;
}

bool CSkinDialog::AddAnchor(HWND hwnd, UINT nFlag)
{
	m_anchor.Remove(hwnd);
	return m_anchor.Add(hwnd, nFlag)?true:false;
}

BOOL CSkinDialog::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return FALSE;
	// return CXTPDialog::OnEraseBkgnd(pDC);
}

void CSkinDialog::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	// TODO: Add your message handler code here and/or call default
	if(CImgSkin::IsLoaded())
	{
		CPoint ptSize;
		ptSize.x = m_mapRect["MinMaxInfo"].X;
		ptSize.y = m_mapRect["MinMaxInfo"].Y;
		if(ptSize.x>0 && ptSize.y>0)
			lpMMI->ptMinTrackSize = ptSize;	

		ptSize.x = m_mapRect["MinMaxInfo"].Width;
		ptSize.y = m_mapRect["MinMaxInfo"].Height;
		if(ptSize.x>0 && ptSize.y>0)
			lpMMI->ptMaxTrackSize = ptSize;	
	}
	
	CXTPDialog::OnGetMinMaxInfo(lpMMI);
}

void CSkinDialog::OnNcMouseMove(UINT nHitTest, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	// CXTPDialog::OnNcMouseMove(nHitTest, point);

	if(nHitTest == HTCAPTION)// || (nHitTest!=HTCAPTION && m_nButtonMove>0))
	{
		int nHit = GetSysButtonsHitTest(point);

		Rect rc, rc1;

		if(m_nButtonMove!=nHit)
		{
			m_nButtonMove = nHit;

			CRect rcWindow;
			GetWindowRect(rcWindow);
					
			Bitmap bmpBuf(rcWindow.Width(), rcWindow.Height());
			Graphics graphics(&bmpBuf);
			Graphics g(GetWindowDC()->GetSafeHdc());

			// x
			rc = nHit==HT_CLOSE?m_mapRect["NcBtnCloseOvr"]:m_mapRect["NcBtnClose"];
			rc1.X = rcWindow.Width()-m_mapRect["NcBtnClosePos"].X;
			rc1.Y = m_mapRect["NcBtnClosePos"].Y;
			rc1.Width = rc.Width;
			rc1.Height = rc.Height;
			graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);	
			
			// 口

			if(GetStyle()&WS_MAXIMIZEBOX)
			{
				rc = nHit==HT_MAX?(IsZoomed()?m_mapRect["NcBtnResOvr"]:m_mapRect["NcBtnMaxOvr"]):(IsZoomed()?m_mapRect["NcBtnRes"]:m_mapRect["NcBtnMax"]);
				rc1.X = rcWindow.Width()-m_mapRect["NcBtnMaxPos"].X;
				rc1.Y = m_mapRect["NcBtnMaxPos"].Y;
				rc1.Width = rc.Width;
				rc1.Height = rc.Height;
				graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);	
			}

			// -
			if(GetStyle()&WS_MINIMIZEBOX)
			{
				rc = nHit==HT_MIN?m_mapRect["NcBtnMinOvr"]:m_mapRect["NcBtnMin"];
				rc1.X = rcWindow.Width()-m_mapRect["NcBtnMinPos"].X;
				rc1.Y = m_mapRect["NcBtnMinPos"].Y;
				rc1.Width = rc.Width;
				rc1.Height = rc.Height;
				graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);
			}
			g.DrawImage(&bmpBuf, 0, 0);
		}
	}

}

int CSkinDialog::GetSysButtonsHitTest(CPoint point)
{
	CRect rcWindow;
	GetWindowRect(&rcWindow);

	CRect rcBtn;

	rcBtn.left = rcWindow.right - m_mapRect["NcBtnClosePos"].X;	
	rcBtn.top = rcWindow.top +  m_mapRect["NcBtnClosePos"].Y;
	rcBtn.right = rcBtn.left + m_mapRect["NcBtnClose"].Width;
	rcBtn.bottom = rcBtn.top + m_mapRect["NcBtnClose"].Height;
	if(rcBtn.PtInRect(point))
		return HT_CLOSE;

	if(GetStyle()&WS_MAXIMIZEBOX)
	{
		rcBtn.left = rcWindow.right - m_mapRect["NcBtnMaxPos"].X;	
		rcBtn.top = rcWindow.top +  m_mapRect["NcBtnMaxPos"].Y;
		rcBtn.right = rcBtn.left + m_mapRect["NcBtnMax"].Width;
		rcBtn.bottom = rcBtn.top + m_mapRect["NcBtnMax"].Height;
		if(rcBtn.PtInRect(point))
			return HT_MAX;
	}

	if(GetStyle()&WS_MINIMIZEBOX)
	{
		rcBtn.left = rcWindow.right - m_mapRect["NcBtnMinPos"].X;	
		rcBtn.top = rcWindow.top +  m_mapRect["NcBtnMinPos"].Y;
		rcBtn.right = rcBtn.left + m_mapRect["NcBtnMin"].Width;
		rcBtn.bottom = rcBtn.top + m_mapRect["NcBtnMin"].Height;
		if(rcBtn.PtInRect(point))
			return HT_MIN;
	}

	return -1;
}

void CSkinDialog::OnNcLButtonDown(UINT nHitTest, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (nHitTest == HTCAPTION)
	{
		m_nButtonDown = GetSysButtonsHitTest(point);
		
		if (m_nButtonDown >= 0)
		{
			SetCapture();
			// RedrawWindow(0, 0, RDW_FRAME|RDW_INVALIDATE );
			OnNcPaint();
		}
	}

	CXTPDialog::OnNcLButtonDown(nHitTest, point);
}

void CSkinDialog::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_nButtonDown >= 0)
	{
		int nButtonDown = m_nButtonDown;

		m_nButtonDown = -1;
		// RedrawWindow(0, 0, RDW_FRAME|RDW_INVALIDATE );
		OnNcPaint();
		
		ReleaseCapture();

		ClientToScreen(&point);

		if (GetSysButtonsHitTest(point) == nButtonDown)
		{
			switch (nButtonDown)
			{
				case HT_CLOSE: 
					PostMessage(WM_SYSCOMMAND, SC_CLOSE); break;
				case HT_MAX:
					PostMessage(WM_SYSCOMMAND, (GetStyle() & WS_MAXIMIZE) != 0? SC_RESTORE: SC_MAXIMIZE ); break;
				case HT_MIN: 
					if(IsIconic())
						PostMessage(WM_SYSCOMMAND, SC_RESTORE);
					else
						PostMessage(WM_SYSCOMMAND, SC_MINIMIZE); 
					break;
			}
		}
		return;
	}	


	CXTPDialog::OnLButtonUp(nFlags, point);
}

HBRUSH CSkinDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CXTPDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(CTLCOLOR_STATIC==nCtlColor || CTLCOLOR_DLG==nCtlColor)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(m_mapColor["Text"]);
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CSkinDialog::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN && m_bIgnoreCancelKey)
	{
		if(pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN)
		{
			OnPressOkCancel();
			return TRUE;
		}
	}

	return CXTPDialog::PreTranslateMessage(pMsg);
}

void CSkinDialog::OnPressOkCancel()
{

}

void CSkinDialog::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	// PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));

	CXTPDialog::OnLButtonDown(nFlags, point);
}

UINT CSkinDialog::OnNcHitTest(CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rcWindow;
	GetWindowRect(&rcWindow);

	CRect rcBtn;

	rcBtn.left = rcWindow.left + m_mapRect["BorderLeft"].Width;	
	rcBtn.top = rcWindow.top + 1;
	rcBtn.right = rcWindow.right - 1;
	rcBtn.bottom = rcWindow.top + m_mapRect["TitleLeft"].Height;	
	if(rcBtn.PtInRect(point))
		return HTCAPTION;
	
	return CXTPDialog::OnNcHitTest(point);
}
