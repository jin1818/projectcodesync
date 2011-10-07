// wtltest1View.h : interface of the CWtltest1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WTLTEST1VIEW_H__42E911CD_4887_4C35_9920_5DB49E050F0F__INCLUDED_)
#define AFX_WTLTEST1VIEW_H__42E911CD_4887_4C35_9920_5DB49E050F0F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "../webcrawler/webcrawlerdll/impl.h"

int updateViewFrame(const char* pUrl , const char* pFrame) ;

class CSearchView : public CWindowImpl<CSearchView>
{
public:
	CButton button ;
	CEdit edit ;
	DECLARE_WND_CLASS(NULL)
		
	BOOL PreTranslateMessage(MSG* pMsg)
	{
		pMsg;
		return FALSE;
	}
	
	BEGIN_MSG_MAP(CSearchView)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
		MESSAGE_HANDLER(WM_SIZE, OnSize)
		COMMAND_HANDLER(ID_SEARCH_BUTTON, BN_CLICKED, OnSearch)
		DEFAULT_REFLECTION_HANDLER()
		END_MSG_MAP()
		// Handler prototypes (uncomment arguments if needed):
		//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
		//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
		//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
		
	LRESULT OnSize(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		RECT rect ;
		
		this->GetWindowRect(&rect) ;
		//ClientToScreen(&rect) ;
		
		RECT rc1;
		rc1.left = rect.right/2 - 180 ;
		rc1.top = 10;
		rc1.bottom = rc1.top + 18;
		rc1.right = rc1.left + 180 ;
		edit.MoveWindow(&rc1) ;
		
		RECT rc2;
		rc2.left = rect.right/2 + 10 ;
		rc2.top = 10;
		rc2.bottom = rc2.top + 18;
		rc2.right = rc2.left + 60;
		button.MoveWindow(&rc2) ;

		return 0 ;
	}

	LRESULT OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		CPaintDC dc(m_hWnd);
		
		
		
		return 0;
	}
	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/) 
	{
		RECT rc1;
		rc1.left = 0;
		rc1.top = 10;
		rc1.bottom = rc1.top + 18;
		rc1.right = rc1.left + 60;
		edit.Create( m_hWnd,&rc1,_T("±à³Ì"),WS_CHILD | WS_VISIBLE|WS_BORDER ,0,ID_SEARCH_EDIT) ;
		
		
		RECT rc2;
		rc2.left =  60 ;
		rc2.top = 10;
		rc2.bottom = rc2.top + 18;
		rc2.right = rc2.left + 60;
		button.Create( m_hWnd,&rc2,_T("ËÑË÷"),WS_CHILD | WS_VISIBLE,0,ID_SEARCH_BUTTON) ;
		
		return 0 ;
	}

	LRESULT OnSearch(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		TCHAR szKey[MAX_PATH+1] = {0};
		edit.GetWindowText(szKey,MAX_PATH) ;
		USES_CONVERSION ;
		getResult(W2CA(szKey) , updateViewFrame) ;

		return 0;
	}
	
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WTLTEST1VIEW_H__42E911CD_4887_4C35_9920_5DB49E050F0F__INCLUDED_)
