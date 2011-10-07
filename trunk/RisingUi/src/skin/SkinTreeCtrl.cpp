// SkinTreeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "SkinTreeCtrl.h"


/////////////////////////////////////////////////////////////////////////////
// CSkinTreeCtrl

CSkinTreeCtrl::CSkinTreeCtrl()
{
}

CSkinTreeCtrl::~CSkinTreeCtrl()
{
}


BEGIN_MESSAGE_MAP(CSkinTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CSkinTreeCtrl)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinTreeCtrl message handlers

BOOL CSkinTreeCtrl::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
	return CTreeCtrl::OnEraseBkgnd(pDC);
}

bool CSkinTreeCtrl::IsForder(HTREEITEM hItem)
{
	int nImage, nSelImage;

	GetItemImage(hItem, nImage, nSelImage);

	return nImage==0;
}

HTREEITEM CSkinTreeCtrl::ExpandAllItem(HTREEITEM hItemStart, UINT nCode)
{
	HTREEITEM hItemChild = NULL;

	Expand(hItemStart, nCode);

	hItemChild = GetChildItem(hItemStart);

	if(hItemChild)
		Expand(hItemChild, nCode);
	
	while(hItemChild = GetNextItem(hItemChild, TVGN_NEXT))
	{
		Expand(hItemChild, nCode);
	}

	return hItemChild;
}

HTREEITEM CSkinTreeCtrl::FindItemByData(HTREEITEM hItemStart, DWORD dwData)
{
	if(hItemStart!=TVI_ROOT && GetItemData(hItemStart)==dwData)
		return hItemStart;

	HTREEITEM hItemNext = NULL;
	HTREEITEM hItemChild = NULL;
	hItemChild = GetChildItem(hItemStart);
	if(hItemChild==NULL)
		return NULL;

	if(GetItemData(hItemChild)==dwData)
		return hItemChild;

	while(hItemChild)
	{  
		if(FindItemByData(hItemChild, dwData)!=NULL)
			return FindItemByData(hItemChild, dwData);

		hItemNext = GetNextItem(hItemChild, TVGN_NEXT);  
		hItemChild = hItemNext;  
	}

	return NULL;
}

/*
void CSkinTreeCtrl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVCUSTOMDRAW lpLVCustomDraw = reinterpret_cast<LPNMLVCUSTOMDRAW>(pNMHDR);
	
	switch(lpLVCustomDraw->nmcd.dwDrawStage)
	{
    case CDDS_ITEMPREPAINT:
    case CDDS_ITEMPREPAINT | CDDS_SUBITEM:
		{			
			if (lpLVCustomDraw->nmcd.uItemState &(CDIS_FOCUS | CDIS_SELECTED))
			{
				lpLVCustomDraw->clrTextBk = m_mapColor["TextBkSel"];
			}
			else 
			{
				lpLVCustomDraw->clrTextBk = m_mapColor["TextBk"];	
			}
			lpLVCustomDraw->clrText = m_mapColor["Text"];

			RECT rc = lpLVCustomDraw->nmcd.rc;
			HDC hdc = lpLVCustomDraw->nmcd.hdc;

			CDC dc;
			dc.Attach(hdc);
			// dc.FromHandle(hdc);
			dc.MoveTo(rc.left, rc.top);
			dc.LineTo(rc.right, rc.bottom);
			dc.Detach();
		}
		
		break;
		
    default: break;    
	}
	
	// TODO: Add your control notification handler code here
	*pResult = 0;
	*pResult |= CDRF_NOTIFYPOSTPAINT;
	*pResult |= CDRF_NOTIFYITEMDRAW;
	*pResult |= CDRF_NOTIFYSUBITEMDRAW;
}
*/

bool CSkinTreeCtrl::LoadSkin(const char * szPath, const char * szType)
{
	bool b = CImgSkin::Load(szPath, szType);
	if(!b)
		return b;

	SetItemHeight(20);

	return true;
}

void CSkinTreeCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	HTREEITEM hShow, hParent;

	int state;
	bool seled;
	bool has_child;
	DWORD tree_style;
	CRect rc_item;

	Rect rcDesc, rcSrc;
	CRect rcWindow;
	GetClientRect(&rcWindow);

	Bitmap bmpBuf(rcWindow.Width(), rcWindow.Height());
	Graphics graphics(&bmpBuf);
	Graphics g(dc.GetSafeHdc());

	WCHAR string[MAX_PATH] = {0};
	CString str;
	Font myFont(L"ËÎÌו", 9);
	Color col(255,0,0);
	Pen myPen(col, 1);
	StringFormat format;
	format.SetAlignment(StringAlignmentNear);

	int offset;
	int height;

	tree_style = ::GetWindowLong( m_hWnd, GWL_STYLE ); 

	// Background
	col.SetFromCOLORREF(m_mapColor["Background"]);
	rcDesc.X = rcWindow.left;
	rcDesc.Y = rcWindow.top;
	rcDesc.Width = rcWindow.Width();
	rcDesc.Height = rcWindow.Height();
	SolidBrush brush(col);
	
	
	graphics.FillRectangle(&brush, rcDesc);

	hShow = GetFirstVisibleItem();
	if(hShow!=NULL)
	do 
	{
		state = GetItemState(hShow, TVIF_STATE);
		hParent = GetParentItem(hShow);
		has_child = ItemHasChildren(hShow)==TRUE?true:false;// || hParent==NULL;
		seled = (state & TVIS_SELECTED) && ((this == GetFocus()) || 
				(tree_style & TVS_SHOWSELALWAYS));

		
		if(GetItemRect(hShow, rc_item, FALSE))
		{
			height = rc_item.Height();
			// sel mask
			if(seled)
			{
				rcSrc = m_mapRect["SelMask"];
				rcDesc.X = rc_item.left;
				rcDesc.Y = rc_item.top;
				rcDesc.Width = rc_item.Width();
				rcDesc.Height = rc_item.Height();
				graphics.DrawImage(m_pImg, rcDesc, rcSrc.GetLeft(), rcSrc.GetTop(), rcSrc.Width, rcSrc.Height, UnitPixel);
			}

			GetItemRect(hShow, rc_item, TRUE);

			offset = 0;

			rcSrc = m_mapRect["BtnOpen"];
			offset = rcSrc.Width+5;

			// btn
			if(ItemHasChildren(hShow))
			{
				if(state & TVIS_EXPANDED)
					rcSrc = m_mapRect["BtnClose"];

				rcDesc.X = rc_item.left;
				rcDesc.Y = rc_item.top+(height-rcSrc.Height)/2;
				rcDesc.Width = rcSrc.Width;
				rcDesc.Height = rcSrc.Height;
				graphics.DrawImage(m_pImg, rcDesc, rcSrc.GetLeft(), rcSrc.GetTop(), rcSrc.Width, rcSrc.Height, UnitPixel);
			}

			// img
			int nImage, nSelImage;
			nImage = nSelImage = 0;
			GetItemImage(hShow, nImage, nSelImage);

			if(nImage==0)
			{
				rcSrc = m_mapRect["ImgForder"];
			}
			else
			{
				rcSrc = m_mapRect["ImgChild"];
			}

			//if(!has_child)
			//	offset+=3;
			
			rcDesc.X = rc_item.left+offset;
			rcDesc.Y = rc_item.top+(height-rcSrc.Height)/2;
			rcDesc.Width = rcSrc.Width;
			rcDesc.Height = rcSrc.Height;
			graphics.DrawImage(m_pImg, rcDesc, rcSrc.GetLeft(), rcSrc.GetTop(), rcSrc.Width, rcSrc.Height, UnitPixel);

			offset+=rcSrc.Width+3;

			// text
			str = GetItemText(hShow);
			MultiByteToWideChar( CP_ACP, 0, str, -1, string, MAX_PATH);
			if(seled)
				col.SetFromCOLORREF(m_mapColor["TextSel"]);
			else
				col.SetFromCOLORREF(m_mapColor["Text"]);

			CSize sz = dc.GetTextExtent(str);
			brush.SetColor(col);
			RectF layoutRect(rc_item.left+offset, rc_item.top+(height-sz.cy), rc_item.Width(), height);
			graphics.DrawString(string,	-1, &myFont, layoutRect, &format, &brush);
		}

	} 
	while( (hShow = GetNextVisibleItem( hShow )) != NULL );

	g.DrawImage(&bmpBuf, 0, 0);
}

void CSkinTreeCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	HTREEITEM hTree = FindItemByPoint(TVI_ROOT, point);
	if(hTree!=NULL)
	{
		Expand(hTree, TVE_TOGGLE);
		SelectItem(hTree);
	}
	
	// point.x = point.y = -1;
	CTreeCtrl::OnLButtonDown(nFlags, point);
}

HTREEITEM CSkinTreeCtrl::FindItemByPoint(HTREEITEM hItemStart, CPoint pnt)
{
	CRect rc;

	if(hItemStart!=TVI_ROOT && GetItemRect(hItemStart, &rc, FALSE) && rc.PtInRect(pnt))
		return hItemStart;

	HTREEITEM hItemNext = NULL;
	HTREEITEM hItemChild = NULL;
	hItemChild = GetChildItem(hItemStart);
	if(hItemChild==NULL)
		return NULL;

	if(GetItemRect(hItemChild, &rc, FALSE) && rc.PtInRect(pnt))
		return hItemChild;

	while(hItemChild)
	{  
		if(FindItemByPoint(hItemChild, pnt)!=NULL)
			return FindItemByPoint(hItemChild, pnt);

		hItemNext = GetNextItem(hItemChild, TVGN_NEXT);  
		hItemChild = hItemNext;  
	}

	return NULL;
}

void CSkinTreeCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CTreeCtrl::OnLButtonDblClk(nFlags, point);
}

void CSkinTreeCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CTreeCtrl::OnLButtonUp(nFlags, point);
}
