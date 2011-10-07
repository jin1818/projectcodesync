// HtmlView.h : interface of the CHtmlView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HtmlView_H__053AD676_0AE2_11D6_8BF1_00500477589F__INCLUDED_)
#define AFX_HtmlView_H__053AD676_0AE2_11D6_8BF1_00500477589F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CHtmlView:
	public CWindowImpl<CHtmlView, CAxWindow>
{
public:
	HRESULT get_Control(IUnknown** ppControl)
	{
		if(m_hWnd != NULL)
		{
			return CAxWindow::QueryControl(ppControl);
		}
		return NULL;
	}

	HRESULT get_Browser(IWebBrowser2** ppBrowser)
	{
		if(m_hWnd != NULL)
		{
			return CAxWindow::QueryControl(ppBrowser);
		}
		return NULL;
	}

public:
	DECLARE_WND_SUPERCLASS(_T("HtmlView"), CAxWindow::GetWndClassName())

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		if((pMsg->message < WM_KEYFIRST || pMsg->message > WM_KEYLAST) &&
			(pMsg->message < WM_MOUSEFIRST || pMsg->message > WM_MOUSELAST))
			return FALSE;

		// give HTML page a chance to translate this message
		return (BOOL)SendMessage(WM_FORWARDMSG, 0, (LPARAM)pMsg);
	}

	BEGIN_MSG_MAP(CHtmlView)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
		COMMAND_ID_HANDLER(ID_ACTION_BACK, OnActionBack)
		COMMAND_ID_HANDLER(ID_ACTION_GONEXT, OnActionGonext)
		COMMAND_ID_HANDLER(ID_ACTION_STOP, OnActionStop)
		COMMAND_ID_HANDLER(ID_ACTION_RELOAD, OnActionReload)
		DEFAULT_REFLECTION_HANDLER()
	END_MSG_MAP()


	LRESULT OnActionBack(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		IWebBrowser2* ppBrowser = NULL ;
		this->get_Browser(&ppBrowser) ;
		if(NULL == ppBrowser)
		{	
			return 0 ;
		}
		ppBrowser->GoBack() ;

		return 0;
	}

	LRESULT OnActionGonext(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		IWebBrowser2* ppBrowser = NULL ;
		this->get_Browser(&ppBrowser) ;
		if(NULL == ppBrowser)
		{	
			return 0 ;
		}
		ppBrowser->GoForward() ;

		return 0;
	}

	LRESULT OnActionStop(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		IWebBrowser2* ppBrowser = NULL ;
		this->get_Browser(&ppBrowser) ;
		if(NULL == ppBrowser)
		{	
			return 0 ;
		}
		ppBrowser->Stop() ;

		return 0;
	}

	LRESULT OnActionReload(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		IWebBrowser2* ppBrowser = NULL ;
		this->get_Browser(&ppBrowser) ;
		if(NULL == ppBrowser)
		{	
			return 0 ;
		}
		ppBrowser->Refresh() ;

		return 0;
	}


	// Handler prototypes (uncomment arguments if needed):
	//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// "base::OnCreate"
		LRESULT nResult = DefWindowProc(uMsg, wParam, lParam);

		//CAxWindow::QueryControl(&m_pBrowser);
		//if(m_pBrowser)
		//{
		//	DispEventAdvise(m_pBrowser, &DIID_DWebBrowserEvents2);
		//}

		bHandled = TRUE;
		return nResult;
	}

	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
	{
		//if(m_pBrowser)
		//{
		//	DispEventUnadvise(m_pBrowser, &DIID_DWebBrowserEvents2);
		//}

		bHandled = FALSE;
		return 0;
	}

	LRESULT OnSetFocus(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
	{
		// The base class ActiveX hosting code for forwarding focus doesn't work well
		// with Internet Explorer, so we'll do it ourself.
		CComPtr<IOleObject> oleObject;
		this->QueryControl(&oleObject);
		if(oleObject)
		{
			CComPtr<IOleClientSite> oleClientSite; 
			this->QueryHost(&oleClientSite);
			if(oleClientSite)
			{
				CRect rcControl;
				this->GetClientRect(&rcControl);
				oleObject->DoVerb(OLEIVERB_UIACTIVATE, NULL, oleClientSite, 0, m_hWnd, &rcControl);
			}
		}

		bHandled = FALSE;
		return 0;
	}

};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HtmlView_H__053AD676_0AE2_11D6_8BF1_00500477589F__INCLUDED_)
