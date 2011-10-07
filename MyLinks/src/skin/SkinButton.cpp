// SkinButton.cpp: implementation of the CSkinButton class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SkinButton.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSkinButton::CSkinButton()
{
	m_bHover = FALSE;
	m_bTracking = FALSE;
	m_nStyle = BS_PUSHBUTTON;
	m_nState = ODS_DEFAULT;
}

CSkinButton::~CSkinButton()
{
}
IMPLEMENT_DYNAMIC(CSkinButton, CBitmapButton)

BEGIN_MESSAGE_MAP(CSkinButton, CBitmapButton)
	//{{AFX_MSG_MAP(CSkinButton)
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////
 //	CSkinButton message handlers
		
void CSkinButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	//	TODO: Add your message handler code here and/or call default

	if (!m_bTracking)
	{
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE|TME_HOVER;
		tme.dwHoverTime = 1;
		m_bTracking = _TrackMouseEvent(&tme);

		m_nState &= ODS_FOCUS;
	}
	CBitmapButton::OnMouseMove(nFlags, point);
}

BOOL CSkinButton::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	InitToolTip();
	m_ToolTip.RelayEvent(pMsg);

	if(pMsg->message==BM_SETCHECK)
	{
		int i=0;
		i++;
	}

	return CButton::PreTranslateMessage(pMsg);
}

// Set the tooltip with a string resource
void CSkinButton::SetToolTipText(int nId, BOOL bActivate)
{
	CString sText;

	// load string resource
	sText.LoadString(nId);
	// If string resource is not empty
	if (sText.IsEmpty() == FALSE) SetToolTipText(sText, bActivate);

}

// Set the tooltip with a CString
void CSkinButton::SetToolTipText(const char *spText, BOOL bActivate)
{
	// We cannot accept NULL pointer
	if (spText == NULL) return;

	// Initialize ToolTip
	InitToolTip();

	// If there is no tooltip defined then add it
	if (m_ToolTip.GetToolCount() == 0)
	{
		CRect rectBtn; 
		GetClientRect(rectBtn);
		m_ToolTip.AddTool(this, (LPCTSTR)spText, rectBtn, 1);
	}

	// Set text for tooltip
	m_ToolTip.UpdateTipText((LPCTSTR)spText, this, 1);
	m_ToolTip.Activate(bActivate);
}

void CSkinButton::InitToolTip()
{
	if (m_ToolTip.m_hWnd == NULL)
	{
		// Create ToolTip control
		m_ToolTip.Create(this);
		// Create inactive
		m_ToolTip.Activate(FALSE);
	}
} // End of InitToolTip

// Activate the tooltip
void CSkinButton::ActivateTooltip(BOOL bActivate)
{
	// If there is no tooltip then do nothing
	if (m_ToolTip.GetToolCount() == 0) return;

	// Activate tooltip
	m_ToolTip.Activate(bActivate);
} // End of EnableTooltip


void CSkinButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	Rect rc, rc1;
	CRect rcWindow = lpDrawItemStruct->rcItem;

	Bitmap bmpBuf(rcWindow.Width(), rcWindow.Height());
	Graphics graphics(&bmpBuf);
	Graphics g(lpDrawItemStruct->hDC);

	int txtOffsetX = 0;
	int txtOffsetY = 0;

	switch(m_nStyle)
	{
	case BS_PUSHBUTTON:
		
		if(lpDrawItemStruct->itemState & ODS_SELECTED)
		{
			rc = m_mapRect["Pushed"];
			txtOffsetX = 1;
		}
		else if(lpDrawItemStruct->itemState & ODS_DISABLED)
		{
			rc = m_mapRect["Disabled"];
		}
		else if(m_bHover)
		{	
			rc = m_mapRect["Hover"];
		}
		else
		{
			rc = m_mapRect["Normal"];
		}
		
		break;

	case BS_AUTORADIOBUTTON:
	case BS_RADIOBUTTON:
	case BS_AUTOCHECKBOX:
	case BS_CHECKBOX:
		{		
			bool bChecked = GetCheck()==1;

			if(lpDrawItemStruct->itemState & ODS_SELECTED)
			{
				if(bChecked)
					rc = m_mapRect["PushedChecked"];
				else
					rc = m_mapRect["Pushed"];
			}
			else if(lpDrawItemStruct->itemState & ODS_DISABLED)
			{
				if(bChecked)
					rc = m_mapRect["DisabledChecked"];
				else
					rc = m_mapRect["Disabled"];
			}
			else if(m_bHover)
			{	
				if(bChecked)
					rc = m_mapRect["HoverChecked"];
				else
					rc = m_mapRect["Hover"];
			}
			else
			{
				if(bChecked)
					rc = m_mapRect["NormalChecked"];
				else
					rc = m_mapRect["Normal"];
			}
		}

		break;

	case BS_GROUPBOX:

		rc.X = rcWindow.left;
		rc.Y = rcWindow.right;
		rc.Width = rcWindow.Width();
		rc.Height = rcWindow.Height();

		break;
	}
	
	Font myFont(L"ËÎÌו", 9);
	Color col(255,0,0,0);
	Pen myPen(col, 1);
	StringFormat format;
	col.SetFromCOLORREF(m_mapColor["Background"]);
	SolidBrush brush(col);

	WCHAR string[MAX_PATH] = {0};
	CString str;
	GetWindowText(str);
	MultiByteToWideChar( CP_ACP, 0, str, -1, string, MAX_PATH) ;

	// background
	if(m_nStyle==BS_AUTOCHECKBOX)
	{
		rc1.X = rc1.Y = 0;
		rc1.Width = rcWindow.Width();
		rc1.Height = rcWindow.Height();
		graphics.FillRectangle(&brush, rc1);
	}

	rc1.X = 0;
	rc1.Y = 0;
	rc1.Width = rc.Width;
	rc1.Height = rc.Height;

	if(m_nStyle==BS_CHECKBOX || m_nStyle==BS_AUTOCHECKBOX || m_nStyle==BS_RADIOBUTTON || m_nStyle==BS_AUTORADIOBUTTON)
	{
		graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);	
		format.SetAlignment(StringAlignmentNear);
		txtOffsetX = rc.Width+5;
		txtOffsetY = 0;
	}
	else if(m_nStyle!=BS_GROUPBOX)
	{
		graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel);	
		format.SetAlignment(StringAlignmentCenter);
		txtOffsetY = (rcWindow.Height()-9)/2-1+txtOffsetX;
	}
	else
	{
		Rect rcCorner = m_mapRect["Corner"];

		myPen.SetWidth(rcCorner.Width);
		col.SetFromCOLORREF(m_mapColor["Rect"]);
		myPen.SetColor(col);

		Rect rcRect = rc1;

		PointF pnts[10];
		int dpi = GetDeviceCaps(lpDrawItemStruct->hDC, LOGPIXELSY );
		float FontHeight = myFont.GetHeight(dpi);
		float HalfFontHeight = FontHeight/2;
		float TxtStart = rcCorner.Y;
		float CornerLen = rcCorner.X;

		rcRect.Y += HalfFontHeight;
		rcRect.X += 1;
		rcRect.Width -= 2;
		rcRect.Height -= 2;

		pnts[0].X = rcRect.X+TxtStart; pnts[0].Y = rcRect.Y;
		pnts[1].X = rcRect.X+CornerLen; pnts[1].Y = pnts[0].Y;
		pnts[2].X = rcRect.X; pnts[2].Y = rcRect.Y+CornerLen;
		pnts[3].X = pnts[2].X; pnts[3].Y = rcRect.Height-CornerLen;
		pnts[4].X = pnts[1].X; pnts[4].Y = rcRect.Height;
		pnts[5].X = rcRect.Width-CornerLen; pnts[5].Y = pnts[4].Y;
		pnts[6].X = rcRect.Width; pnts[6].Y = pnts[3].Y;
		pnts[7].X = rcRect.Width; pnts[7].Y = pnts[2].Y;
		pnts[8].X = rcRect.Width-CornerLen; pnts[8].Y = pnts[0].Y;

		CClientDC dc(this);
		CSize sz = dc.GetTextExtent(str);

		pnts[9].X = pnts[0].X+sz.cx-1; pnts[9].Y = pnts[0].Y;

		graphics.DrawLines(&myPen, pnts, 10);

		format.SetAlignment(StringAlignmentNear);
		txtOffsetX = rcCorner.Y+3;
		txtOffsetY = 0;
	}
	
	col.SetFromCOLORREF(m_mapColor["Text"]);
	SolidBrush blackBrush(col);
	
	
	RectF layoutRect(txtOffsetX, txtOffsetY, rcWindow.Width(), rcWindow.Height());

	graphics.DrawString(string,	-1, &myFont, layoutRect, &format, &blackBrush);
	
	g.DrawImage(&bmpBuf, 0, 0);

}

BOOL CSkinButton::LoadSkin(const char * szSkinPath, const char * szControlName)
{
	if(szSkinPath==NULL)
	{
		CImgSkin::Unload();

		return true;
	}

	if(!CImgSkin::Load(szSkinPath, szControlName))
		return false;

	Rect & rcImg = m_mapRect["Normal"];

	RECT rcNew;

	m_nStyle = GetButtonStyle();

	if(m_nStyle!=BS_GROUPBOX)
	{
		GetWindowRect(&rcNew);
		this->GetParent()->ScreenToClient(&rcNew);

		if(m_nStyle==BS_PUSHBUTTON || GetWindowTextLength()==0)
		rcNew.right = rcNew.left+rcImg.Width;
		rcNew.bottom = rcNew.top+rcImg.Height;
		MoveWindow(&rcNew, TRUE);
	}

	if(m_nStyle==BS_PUSHBUTTON)
		ModifyStyle(0, BS_OWNERDRAW);

	return true;
}


LRESULT CSkinButton::OnMouseHover(WPARAM wparam, LPARAM lparam) 
{
	// TODO: Add your message handler code here and/or call default
	m_bHover=TRUE;
	Invalidate();
	return TRUE;
}


LRESULT CSkinButton::OnMouseLeave(WPARAM wparam, LPARAM lparam)
{
	m_bTracking = FALSE;
	m_bHover=FALSE;
	m_nState &= ~ODS_FOCUS;
	Invalidate();
	return 0;
}

BOOL CSkinButton::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
	return CBitmapButton::OnEraseBkgnd(pDC);
}

void CSkinButton::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	DRAWITEMSTRUCT d;
	d.hDC = dc.GetSafeHdc();
	GetClientRect(&d.rcItem);

	d.itemState = m_nState;
	
	DrawItem(&d);

	// Do not call CBitmapButton::OnPaint() for painting messages
}

void CSkinButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_nState |= ODS_SELECTED;

	CBitmapButton::OnLButtonDown(nFlags, point);
}

void CSkinButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_nState &= ~ODS_SELECTED;

	CBitmapButton::OnLButtonUp(nFlags, point);
}
