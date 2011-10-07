// SkinWnd.cpp : implementation file
//

#include "stdafx.h"
#include "SkinWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinWnd

CSkinWnd::CSkinWnd()
{
}

CSkinWnd::~CSkinWnd()
{
}


BEGIN_MESSAGE_MAP(CSkinWnd, CWnd)
	//{{AFX_MSG_MAP(CSkinWnd)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CSkinWnd message handlers

void CSkinWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	if(!CImgSkin::IsLoaded())
	{
		CWnd::OnPaint();
		return;
	}

	Rect rc, rc1;
	CRect rcWindow;
	GetClientRect(&rcWindow);

	Bitmap bmpBuf(rcWindow.Width(), rcWindow.Height());
	Graphics graphics(&bmpBuf);
	Graphics g(dc.GetSafeHdc());

	rc = m_mapRect["Background"];

	// Top
	rc1.X = 0;
	rc1.Y = 0;
	rc1.Width = rc.Width/3;
	rc1.Height = rc.Height/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width/3, rc.Height/3, UnitPixel);

	rc1.X = rc.Width/3;
	rc1.Width = rcWindow.Width()-rc.Width/3*2;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft()+rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height/3, UnitPixel);

	rc1.X = rcWindow.Width()-rc.Width/3;
	rc1.Width = rc.Width/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetRight()-rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height/3, UnitPixel);


	//Center
	rc1.X = 0;
	rc1.Y = rc.Height/3;
	rc1.Width = rc.Width/3;
	rc1.Height = rcWindow.Height()-rc.Height/3*2;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop()+rc.Height/3, rc.Width/3, rc.Height/3, UnitPixel);

	rc1.X = rc.Width/3;
	rc1.Width = rcWindow.Width()-rc.Width/3*2;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft()+rc.Width/3, rc.GetTop()+rc.Height/3, rc.Width/3, rc.Height/3, UnitPixel);

	rc1.X = rcWindow.Width()-rc.Width/3;
	rc1.Width = rc.Width/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetRight()-rc.Width/3, rc.GetTop()+rc.Height/3, rc.Width/3, rc.Height/3, UnitPixel);

	//Bottom
	rc1.X = 0;
	rc1.Y = rcWindow.Height()-rc.Height/3;
	rc1.Width = rc.Width/3;
	rc1.Height = rc.Height/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetBottom()-rc.Height/3, rc.Width/3, rc.Height/3, UnitPixel);

	rc1.X = rc.Width/3;
	rc1.Width = rcWindow.Width()-rc.Width/3*2;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft()+rc.Width/3, rc.GetBottom()-rc.Height/3, rc.Width/3, rc.Height/3, UnitPixel);

	rc1.X = rcWindow.Width()-rc.Width/3;
	rc1.Width = rc.Width/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetRight()-rc.Width/3, rc.GetBottom()-rc.Height/3, rc.Width/3, rc.Height/3, UnitPixel);

	g.DrawImage(&bmpBuf, 0, 0);		
	// Do not call CWnd::OnPaint() for painting messages
}

bool CSkinWnd::LoadSkin(const char * szSkinPath /* = NULL */, const char * szControlName/* = */)
{
	if(szSkinPath==NULL)
	{
		CImgSkin::Unload();
		return true;
	}

	if(!CImgSkin::Load(szSkinPath, szControlName))
		return false;

	return true;
}
