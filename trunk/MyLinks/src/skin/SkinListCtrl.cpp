// SkinListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "SkinListCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CSkinListCtrl

CSkinListCtrl::CSkinListCtrl()
{
}

CSkinListCtrl::~CSkinListCtrl()
{
}

BEGIN_MESSAGE_MAP(CSkinListCtrl, CXTListCtrl)
	//{{AFX_MSG_MAP(CSkinListCtrl)
	ON_WM_DRAWITEM()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinListCtrl message handlers

CSkinHeaderTheme::CSkinHeaderTheme()
{

}

CSkinHeaderTheme::~CSkinHeaderTheme()
{

}

void CSkinHeaderTheme::DrawHeader(CDC* pDC, CXTHeaderCtrl* pHeaderCtrl)
{
	/*
	CMemDC dc(pDC);
	CRect rc;
	int i;
	BITMAP bm;
	CDC ImageDC;
	CBitmap *pOldImageBMP;

	m_bmpHeader.GetBitmap(&bm);
	pHeaderCtrl->GetClientRect(&rc);

	ImageDC.CreateCompatibleDC(&dc);
	pOldImageBMP = ImageDC.SelectObject(&m_bmpHeader);

	int iCount = pHeaderCtrl->GetItemCount();
	HDITEM hdItem;
	int Width;
	int j;
	int TotalWidth = 0;

	char * buf = new char[100];

	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(49,89,132));
	CXTPFontDC font(&dc, pHeaderCtrl->GetFont());

	for(i=0; i<iCount; i++)
	{
		hdItem.mask = HDI_WIDTH;
		pHeaderCtrl->GetItem(i, &hdItem);
		Width = hdItem.cxy;

		for(j=TotalWidth; j<TotalWidth + Width - bm.bmWidth/8; j+=bm.bmWidth/8)
		{
			BitBlt(dc.GetSafeHdc(), j, 0, bm.bmWidth/8, bm.bmHeight, ImageDC.GetSafeHdc(), 0, 0, SRCCOPY);			
		}

		BitBlt(dc.GetSafeHdc(), j, 0, TotalWidth+Width-j, bm.bmHeight, ImageDC.GetSafeHdc(), j+bm.bmWidth/4-(TotalWidth+Width), 0, SRCCOPY);

		CRect rcTitle(TotalWidth, 0,  TotalWidth+Width, bm.bmHeight);

		hdItem.mask = HDI_TEXT;
		hdItem.pszText = buf;
		hdItem.cchTextMax = 100;
		pHeaderCtrl->GetItem(i, &hdItem);
		
		dc.DrawText(buf, rcTitle, DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOCLIP);

		TotalWidth += Width;
	}

	delete [] buf;

	// 
	Width = rc.Width()-TotalWidth;

	for(j=TotalWidth; j<TotalWidth + Width - bm.bmWidth/8; j+=bm.bmWidth/8)
	{
		BitBlt(dc.GetSafeHdc(), j, 0, bm.bmWidth/8, bm.bmHeight, ImageDC.GetSafeHdc(), 0, 0, SRCCOPY);			
	}

	BitBlt(dc.GetSafeHdc(), j, 0, TotalWidth+Width-j, bm.bmHeight, ImageDC.GetSafeHdc(), j+bm.bmWidth/4-(TotalWidth+Width), 0, SRCCOPY);	

	ImageDC.SelectObject(pOldImageBMP);
	*/
}


bool CSkinListCtrl::LoadSkin(const char * szSkinPath, const char * szControlName)
{
	if(szSkinPath==NULL)
	{
		// m_SkinTheme.Unload();
		
		return true;
	}
	
	//if(!m_SkinTheme.Load(szSkinPath, szControlName))
	//	return false;

	m_skinHeader.SubclassWindow(this->GetHeaderCtrl()->GetSafeHwnd());


	return true;
}

void CSkinListCtrl::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
	ASSERT(lpDrawItemStruct->CtlType == ODT_HEADER);

	CDC * pdc = CDC::FromHandle(lpDrawItemStruct->hDC);
	CFont * pOldFont = pdc->SelectObject(&m_normalFont);
	
	LVCOLUMN col;
	char buff[64];
	
	col.mask = LVCF_IMAGE | LVCF_TEXT;
	col.pszText = buff;
	col.cchTextMax = sizeof(buff);
	
	GetColumn(lpDrawItemStruct->itemID, &col);
	
	CRect rect(lpDrawItemStruct->rcItem);
	rect.left += 2;
	int height = pdc->DrawText(buff, rect, DT_SINGLELINE | DT_LEFT | DT_TOP | DT_END_ELLIPSIS);
	height = 100;
	rect.top += height;
	// m_headerImageList.Draw(pdc, lpDrawItemStruct->, rect.TopLeft(), ILD_NORMAL);
	
	pdc->SelectObject(pOldFont);
	
	// CXTListCtrl::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
