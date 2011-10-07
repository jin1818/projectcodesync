// SkinSlider.cpp : implementation file
//

#include "stdafx.h"
#include "SkinSlider.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinSlider

CSkinSlider::CSkinSlider()
{
	m_bDragging = false;
}

CSkinSlider::~CSkinSlider()
{
}


BEGIN_MESSAGE_MAP(CSkinSlider, CSliderCtrl)
	//{{AFX_MSG_MAP(CSkinSlider)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinSlider message handlers

void CSkinSlider::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	if(!CImgSkin::IsLoaded())
	{
		CSliderCtrl::OnPaint();
		return;
	}
	
	dc.SetBkMode(TRANSPARENT);
	
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
	
	rc = m_mapRect["Background"];
	rc1.X = 0;
	rc1.Y = 0;
	rc1.Width = rc.Width/3;
	rc1.Height = rcWindow.Height();
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);

	rc1.X = rc.Width/3;
	rc1.Width = rcWindow.Width()-rc.Width/3*2;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft()+rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);
	
	rc1.X = rcWindow.Width()-rc.Width/3;
	rc1.Width = rc.Width/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetRight()-rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);

	int nMin = GetRangeMin();
	int nMax = GetRangeMax();
	int nPos = GetPos();
	int nWidth = (nPos-nMin)*rcWindow.Width()/(nMax-nMin);

	rc = m_mapRect["Selected"];

	if(nWidth>0)
	{
		rc1.X = 0;
		rc1.Y = 0;
		rc1.Width = nWidth>rc.Width/3?rc.Width/3:nWidth;
		rc1.Height = rcWindow.Height();
		graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc1.Width, rc.Height, UnitPixel);
	}
	
	if(nWidth>rc.Width/3)
	{
		rc1.X = rc.Width/3;
		rc1.Width = rcWindow.Width()-rc.Width/3*2;
		if(rc1.Width>nWidth-rc.Width/3)
			rc1.Width = nWidth-rc.Width/3;

		graphics.DrawImage(m_pImg, rc1, rc.GetLeft()+rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);
	}

	if(nWidth>rcWindow.Width()-rc.Width/3)
	{
		rc1.X = rcWindow.Width()-rc.Width/3;
		rc1.Width = nWidth-(rcWindow.Width()-rc.Width/3)+1;

		graphics.DrawImage(m_pImg, rc1, rc.GetRight()-rc.Width/3, rc.GetTop(), rc1.Width, rc.Height, UnitPixel);
	}

	g.DrawImage(&bmpBuf, 0, 0);
	
	// Do not call CSliderCtrl::OnPaint() for painting messages
}

bool CSkinSlider::LoadSkin(const char * szSkinPath , const char * szControlName/* = */)
{
	if(szSkinPath==NULL)
	{
		CImgSkin::Unload();
		
		return true;
	}
	
	if(!CImgSkin::Load(szSkinPath, szControlName))
		return false;
	

	ModifyStyleEx(0, WS_EX_TRANSPARENT);

	RECT rcNew;

	GetWindowRect(&rcNew);
	this->GetParent()->ScreenToClient(&rcNew);

	Rect & rcImg = m_mapRect["Background"];
	
	rcNew.bottom = rcNew.top+rcImg.Height;

	MoveWindow(&rcNew, TRUE);

	
	
	return true;
}

BOOL CSkinSlider::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
	return CSliderCtrl::OnEraseBkgnd(pDC);
}

void CSkinSlider::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bDragging = true;
	SetPosByPoint(point);
	SetCapture();
	// CSliderCtrl::OnLButtonDown(nFlags, point);
}

void CSkinSlider::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bDragging = false;
	ReleaseCapture();
	// CSliderCtrl::OnLButtonUp(nFlags, point);
}

void CSkinSlider::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	// CSliderCtrl::OnMouseMove(nFlags, point);
	
	if(m_bDragging)
	{
		SetPosByPoint(point);
	}
}

void CSkinSlider::SetPosByPoint(CPoint & Point)
{
	CRect Rect;
	GetClientRect(&Rect);

	int nMax = GetRangeMax();
	int nMin = GetRangeMin();
	int nPos = Point.x*(nMax-nMin)/Rect.Width()+nMin;
	SetPos(nPos);

	Invalidate();

	this->GetParent()->SendMessage(WM_HSCROLL, NULL, (LPARAM)this->GetSafeHwnd());
}

void CSkinSlider::SetPos(int nPos)
{
	CSliderCtrl::SetPos(nPos);
	Invalidate();
}