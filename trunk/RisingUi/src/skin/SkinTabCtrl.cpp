// SkinTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "SkinTabCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinTabCtrl

CSkinTabCtrl::CSkinTabCtrl()
{
	m_CurMouseOvr = -1;
}

CSkinTabCtrl::~CSkinTabCtrl()
{
}


BEGIN_MESSAGE_MAP(CSkinTabCtrl, CTabCtrl)
	//{{AFX_MSG_MAP(CSkinTabCtrl)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MOUSELEAVE,OnMouseLeave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinTabCtrl message handlers


bool CSkinTabCtrl::LoadSkin(const char * szSkinPath /* = NULL */, const char * szControlName)
{
	if(szSkinPath==NULL)
	{
		CImgSkin::Unload();

		return true;
	}

	if(!CImgSkin::Load(szSkinPath, szControlName))
		return false;

	// ModifyStyleEx(0, WS_EX_TRANSPARENT);

	RECT rc;
	GetWindowRect(&rc);
	this->GetParent()->ScreenToClient(&rc);

	// rc.right = rc.left+GetItemCount()*m_mapRect["Normal"].Width;
	rc.bottom = rc.top+m_mapRect["Normal"].Height;
	MoveWindow(&rc);
	
	CalcItemWidth();

	return true;
}

BOOL CSkinTabCtrl::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
	return CTabCtrl::OnEraseBkgnd(pDC);
}

void CSkinTabCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here

	if(!CImgSkin::IsLoaded())
	{
		CTabCtrl::OnPaint();
		return;
	}

	dc.SetBkMode(TRANSPARENT);
	// dc.SetTextColor(m_mapColor["Font"]);

	int i;
	int NumTab = GetItemCount();
	int CurSel = GetCurSel();

	CXTPFontDC font(&dc, GetFont());
	TCITEM tci;
	char buf[100] = {0};
	tci.mask = TCIF_TEXT;
	tci.cchTextMax = 100;
	tci.pszText = buf;
	CString title;

	Rect rc, rc1;
	CRect rcWindow;

	GetClientRect(&rcWindow);

	Bitmap bmpBuf(rcWindow.Width(), rcWindow.Height());
	Graphics graphics(&bmpBuf);
	Graphics g(dc.GetSafeHdc());

	Font myFont(L"ËÎÌו", 9);
	Color col(255,0,0,0);
	col.SetFromCOLORREF(m_mapColor["Font"]);
	SolidBrush blackBrush(col);
	
	StringFormat format;
	format.SetAlignment(StringAlignmentCenter);

	// background
	rc = m_mapRect["Background"];
	rc1.X = 0;
	rc1.Y = 0;
	rc1.Width = rcWindow.Width();
	rc1.Height = rcWindow.Height();
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);


	rc = m_mapRect["Line"];
	rc1.X = 0;
	rc1.Y = m_mapRect["Align"].Height;
	rc1.Width = rcWindow.Width();
	rc1.Height = m_mapRect["Line"].Height;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

	rc1.X = 0;
	rc1.Y = m_mapRect["Align"].Height+m_mapRect["Line"].Height;
	rc1.Width = m_mapRect["Normal"].Width;
	rc1.Height = m_mapRect["Normal"].Height;

	for(i=0; i<NumTab; i++)
	{
		rc1.Y = m_mapRect["Align"].Height+m_mapRect["Line"].Height;
		rc = m_mapRect["Normal"];
		if(i==CurSel)
		{
			rc1.Y = m_mapRect["Align"].Height+m_mapRect["Line"].Height+m_mapRect["Align"].Width;
			rc = m_mapRect["Selected"];
		}
		else if(i==m_CurMouseOvr)
			rc = m_mapRect["MouseMove"];
		else
			rc = m_mapRect["Disabled"];
	
		graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);

		RectF layoutRect(rc1.X, 8+m_mapRect["Align"].Y+m_mapRect["Line"].Height, rc.Width, rc.Height);

		WCHAR string[MAX_PATH] = {0};
		GetItem(i, &tci);

		MultiByteToWideChar( CP_ACP, 0, tci.pszText, -1, string, MAX_PATH) ;

		graphics.DrawString(string,	-1, &myFont, layoutRect, &format, &blackBrush);

		rc1.X += rc.Width;
	}

	g.DrawImage(&bmpBuf, 0, 0);

	// Do not call CTabCtrl::OnPaint() for painting messages
}

void CSkinTabCtrl::CalcItemWidth()
{
	if(CImgSkin::IsLoaded())
	{
		SetItemSize(CSize(m_mapRect["Normal"].Width, m_mapRect["Normal"].Height));	
	}
}

void CSkinTabCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	TRACKMOUSEEVENT trackmouseevent;
	trackmouseevent.cbSize = sizeof(trackmouseevent);
	trackmouseevent.dwFlags = TME_LEAVE;
	trackmouseevent.hwndTrack = GetSafeHwnd();
	trackmouseevent.dwHoverTime = 0;
	_TrackMouseEvent(&trackmouseevent);

	TCHITTESTINFO thi;
	thi.flags = TCHT_ONITEM;
	thi.pt = point;
	int ht = HitTest(&thi);

	if(m_CurMouseOvr!=ht)
	{
		m_CurMouseOvr = ht;
		Invalidate(TRUE);
	}

	CTabCtrl::OnMouseMove(nFlags, point);
}

LONG CSkinTabCtrl::OnMouseLeave(WPARAM /*wParam*/, LPARAM /*lParam*/) 
{
	m_CurMouseOvr = -1;
	Invalidate(TRUE);
	return 1;
}
