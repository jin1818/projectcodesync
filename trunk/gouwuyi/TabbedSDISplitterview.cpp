// TabbedSDISplitterView.cpp
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"


#include "TabbedSDISplitterView.h"
#include ".\tabbedsdisplitterview.h"

int updateView(const char* pUrl) ;
bool downloadFile(const string & strURL, const string & strWriteFile) ;


BOOL CLeftPaneTreeView::PreTranslateMessage(MSG* pMsg)
{
	return FALSE ;
}

LRESULT CLeftPaneTreeView::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	// "CTreeViewCtrl::OnCreate()"
	LRESULT lRet = DefWindowProc(uMsg, wParam, lParam);
	
	return lRet;
}

LRESULT CLeftPaneTreeView::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
{
	// Say that we didn't handle it so that the treeview and anyone else
	//  interested gets to handle the message
	bHandled = FALSE;
	return 0;
}

LRESULT CLeftPaneTreeView::OnNmItemdblclick(int idCtrl, LPNMHDR pnmh, BOOL& bHandled)
{
	return 0 ;
}

void CSomeChildView::DoPaint(CDCHandle dc, RECT& rcClip)
{

}



LRESULT CSomeSelfDeletingChildView::OnSize(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	Invalidate();
	return 0;
}

void CSomeSelfDeletingChildView::DoPaint(CDCHandle dc, RECT& rcClip)
{
	// "EraseBackground"
	dc.FillRect(&rcClip, (HBRUSH)(COLOR_WINDOW+1));

	CRect rcClient;
	this->GetClientRect(&rcClient);

	CString sText(_T("Hello World"));
	dc.DrawText(sText, sText.GetLength(), &rcClient, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

BOOL CSdiDlgView::PreTranslateMessage(MSG* pMsg)
{
	return IsDialogMessage(pMsg);
}

LRESULT CSdiDlgView::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	this->SetWindowText(_T("Dialog View"));

	DlgResize_Init(false, true, WS_CLIPCHILDREN);

	return 0;
}

LRESULT CSdiDlgView::OnForwardMsg(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& /*bHandled*/)
{
	LPMSG pMsg = (LPMSG)lParam;

	return this->PreTranslateMessage(pMsg);
}

LRESULT CMyCustomListView::OnPaint(UINT uMsg, WPARAM wParam, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	if( wParam != NULL )
	{
		CMemDC memdc((HDC)wParam, NULL);

		memdc.FillSolidRect(&memdc.m_rc, ::GetSysColor(COLOR_WINDOW));
		this->DefWindowProc( uMsg, (WPARAM)memdc.m_hDC, 0);
	}
	else
	{
		CPaintDC dc(m_hWnd);
		CMemDC memdc(dc.m_hDC, &dc.m_ps.rcPaint);

		memdc.FillSolidRect(&dc.m_ps.rcPaint, ::GetSysColor(COLOR_WINDOW));
		this->DefWindowProc( uMsg, (WPARAM)memdc.m_hDC, 0);
	}
	return 0;
}

LRESULT CMyCustomListView::OnEraseBackground(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// Erase the background in OnPaint
	return 1;
}

DWORD CMyCustomListView::OnPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/)
{
	return CDRF_NOTIFYITEMDRAW;
}

DWORD CMyCustomListView::OnItemPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/)
{
	return CDRF_NOTIFYPOSTPAINT;
}

DWORD CMyCustomListView::OnItemPostPaint(int /*idCtrl*/, LPNMCUSTOMDRAW lpNMCustomDraw)
{
	CDCHandle dc( lpNMCustomDraw->hdc );

	int nItem = (int)lpNMCustomDraw->dwItemSpec;

	RECT rcItem;
	this->GetItemRect(nItem, &rcItem, LVIR_BOUNDS);

	CPen penOutline;
	if(this->GetItemState(nItem, LVIS_SELECTED) == LVIS_SELECTED)
	{
		penOutline.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_HIGHLIGHT));
	}
	else 
	{
		penOutline.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_GRAYTEXT));
	}

	CPenHandle penOld = dc.SelectPen(penOutline);

	dc.MoveTo(rcItem.left, rcItem.top);
	dc.LineTo(rcItem.left, rcItem.bottom-1);
	dc.LineTo(rcItem.right-1, rcItem.bottom-1);
	dc.LineTo(rcItem.right-1, rcItem.top);
	dc.LineTo(rcItem.left, rcItem.top);

	dc.SelectPen(penOld);

	return CDRF_DODEFAULT;
}



