// SkinHeaderCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "SkinHeaderCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinHeaderCtrl

CSkinHeaderCtrl::CSkinHeaderCtrl()
{
}

CSkinHeaderCtrl::~CSkinHeaderCtrl()
{
}


BEGIN_MESSAGE_MAP(CSkinHeaderCtrl, CHeaderCtrl)
	//{{AFX_MSG_MAP(CSkinHeaderCtrl)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	ON_MESSAGE(HDM_LAYOUT, OnLayout)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinHeaderCtrl message handlers

LRESULT CSkinHeaderCtrl::OnLayout( WPARAM wParam, LPARAM lParam ) 
{
	LRESULT lResult = CHeaderCtrl::DefWindowProc(HDM_LAYOUT, 0, lParam);

	HD_LAYOUT &hdl = *( HD_LAYOUT * ) lParam;
	RECT *prc = hdl.prc;
	WINDOWPOS *pwpos = hdl.pwpos;

	int nHeight = m_mapRect["Normal"].Height;

	pwpos->cy = nHeight;
	prc->top = nHeight;

	return lResult;
}

bool CSkinHeaderCtrl::LoadSkin(const char * szSkinPath, const char * szControlName)
{
	if(szSkinPath==NULL)
	{
		Unload();
		return true;
	}
	
	if(!Load(szSkinPath, szControlName))
		return false;

	return true;
}

void CSkinHeaderCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	dc.SetBkMode(TRANSPARENT);
	
	int i;
	int NumCol = GetItemCount();

	HDITEM hdItem;
	int Width;
	int TotalWidth = 0;
	
	TCITEM tci;
	char buf[MAX_PATH] = {0};
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
	col.SetFromCOLORREF(m_mapColor["Text"]);
	SolidBrush blackBrush(col);
	
	StringFormat format;
	format.SetAlignment(StringAlignmentCenter);
	
	Width = 0;
	rc1.X = 0;
	rc1.Y = 0;

	rc = m_mapRect["Normal"];
	rc1.Height = rc.Height;

	for(i=0; i<NumCol; i++)
	{
		hdItem.mask = HDI_WIDTH;
		GetItem(i, &hdItem);
		Width = hdItem.cxy;

		rc1.X = TotalWidth;
		
		rc1.Width = rc.Width/3;
		graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);

		rc1.X = TotalWidth+rc.Width/3;
		rc1.Width = Width-rc.Width/3*2;
		graphics.DrawImage(m_pImg, rc1, rc.GetLeft()+rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);

		rc1.X = TotalWidth+Width-rc.Width/3;
		rc1.Width = rc.Width/3;
		graphics.DrawImage(m_pImg, rc1, rc.GetRight()-rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);
		
		rc1.X = TotalWidth;
		rc1.Width = Width;

		WCHAR string[MAX_PATH] = {0};
		char buf[MAX_PATH];
		hdItem.mask = HDI_TEXT;
		hdItem.pszText = buf;
		hdItem.cchTextMax = MAX_PATH;
		GetItem(i, &hdItem);
		CSize sz = dc.GetTextExtent(buf);
		RectF layoutRect(rc1.X, (rc1.Height-sz.cy+4)/2, rc1.Width, rc1.Height);
		
		MultiByteToWideChar( CP_ACP, 0, buf, -1, string, MAX_PATH);
		
		graphics.DrawString(string,	-1, &myFont, layoutRect, &format, &blackBrush);
		TotalWidth += Width;
	}

	Width = rcWindow.Width()-TotalWidth;
	rc1.X = TotalWidth;
	rc1.Width = rc.Width/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);
	
	rc1.X = TotalWidth+rc.Width/3;
	rc1.Width = Width-rc.Width/3*2;
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft()+rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);
	
	rc1.X = TotalWidth+Width-rc.Width/3;
	rc1.Width = rc.Width/3;
	graphics.DrawImage(m_pImg, rc1, rc.GetRight()-rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);
	
	
	g.DrawImage(&bmpBuf, 0, 0);
	
	// Do not call CTabCtrl::OnPaint() for painting messages
}