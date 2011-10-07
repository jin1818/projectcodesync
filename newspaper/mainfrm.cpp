// MainFrm.cpp : implmentation of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "aboutdlg.h"
#include "TabbedSdiSplitterView.h"
#include "MainFrm.h"
#include ".\mainfrm.h"


BOOL CMainFrame::PreTranslateMessage(MSG* pMsg)
{
	if(CFrameWindowImpl<CMainFrame>::PreTranslateMessage(pMsg))
		return TRUE;

	//return m_view.PreTranslateMessage(pMsg);

	HWND hWndFocus = ::GetFocus();

	if(m_tabbedChildWindow.IsChild(hWndFocus))
	{
		if(m_tabbedChildWindow.PreTranslateMessage(pMsg))
		{
			return TRUE;
		}
	}
	else if(m_paneTree.IsChild(hWndFocus))
	{
		if(m_viewTree.PreTranslateMessage(pMsg))
		{
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CMainFrame::OnIdle()
{
	UIUpdateToolBar();
	return FALSE;
}

LRESULT CMainFrame::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// create command bar window
	HWND hWndCmdBar = m_CmdBar.Create(m_hWnd, rcDefault, NULL, ATL_SIMPLE_CMDBAR_PANE_STYLE);
	// attach menu
	m_CmdBar.AttachMenu(GetMenu());
	// load command bar images
	m_CmdBar.LoadImages(IDR_MAINFRAME);
	// remove old menu
	SetMenu(NULL);

	HWND hWndToolBar = CreateSimpleToolBarCtrl(m_hWnd, IDR_MAINFRAME, TRUE, ATL_SIMPLE_TOOLBAR_PANE_STYLE);

	CreateSimpleReBar(ATL_SIMPLE_REBAR_NOBORDER_STYLE);
	AddSimpleReBarBand(hWndCmdBar);
	AddSimpleReBarBand(hWndToolBar, NULL, TRUE);

	CreateSimpleStatusBar();

	// register object for message filtering and idle updates
	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != NULL);
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

	UIAddToolBar(hWndToolBar);
	UISetCheck(ID_VIEW_TOOLBAR, 1);
	UISetCheck(ID_VIEW_STATUS_BAR, 1);
	UISetCheck(ID_VIEW_TREE, 1);


	m_hWndClient = m_splitter.Create(m_hWnd, rcDefault, NULL,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

	m_splitter.SetSplitterExtendedStyle(0);
	//SetSplitterPos works best in a "Post-Create" step
	//m_splitter.SetSplitterPos(200);

	m_paneTree.Create(m_splitter, _T("Tree"));

	// If you plan on having any tab views needing
	// notifications to be reflected (such as if you
	// have a custom draw list view), be sure to include
	// the following line.  If you know you won't need
	// notifications to be reflected, it can cut down
	// on the message traffic if you don't.
	// Also beware that reflecting notifications back
	// to some common controls (especially a tree view)
	// can cause visual anomolies unless you superclass
	// the control and add "DEFAULT_REFLECTION_HANDLER()"
	// to the message map.
	m_tabbedChildWindow.SetReflectNotifications(true);

	m_tabbedChildWindow.SetTabStyles(CTCS_TOOLTIPS | CTCS_DRAGREARRANGE);
	m_tabbedChildWindow.Create(m_splitter, rcDefault);
	//m_tabbedChildWindow.GetTabCtrl().ModifyStyle(CTCS_BOTTOM, (CTCS_SCROLL | CTCS_CLOSEBUTTON));

	m_view1.Create(m_tabbedChildWindow ,  rcDefault, CString(HOMEPAGELINK) , WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL, WS_EX_CLIENTEDGE);
	::SetWindowText(m_view1, _T("±¨¿¯") ) ;

	m_viewTree.Create(m_paneTree, rcDefault, NULL,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS,
		WS_EX_CLIENTEDGE);
	m_paneTree.SetClient(m_viewTree);
	m_viewTree.setMainFrame(this) ;
	
	m_tabbedChildWindow.DisplayTab(m_view1);

	m_splitter.SetSplitterPanes(m_paneTree, m_tabbedChildWindow);

	this->PostMessage(WM_POSTCREATE);

	return 0;
}

LRESULT CMainFrame::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
{
	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != NULL);
	pLoop->RemoveMessageFilter(this);
	pLoop->RemoveIdleHandler(this);

	bHandled = FALSE;
	return 0;
}

LRESULT CMainFrame::OnPostCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	//SetSplitterPos works best after the default WM_CREATE has been handled
	m_splitter.SetSplitterPos(200);

	return 0;
}

LRESULT CMainFrame::OnSettingChange(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
{
	// System settings or metrics have changed.  Propogate this message
	// to all the child windows so they can update themselves as appropriate.
	this->SendMessageToDescendants(uMsg, wParam, lParam, TRUE);

	return 0;
}

LRESULT CMainFrame::OnFileExit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	PostMessage(WM_CLOSE);
	return 0;
}

LRESULT CMainFrame::OnFileNew(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	static int nCount = 1;
	CString sText;
	sText.Format(_T("View %d"), nCount++);

	CSomeSelfDeletingChildView* pChild = new CSomeSelfDeletingChildView;
	pChild->Create(m_tabbedChildWindow, rcDefault, sText);
	m_tabbedChildWindow.DisplayTab(pChild->m_hWnd, TRUE, TRUE);

	return 0;
}

LRESULT CMainFrame::OnViewToolBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	static BOOL bVisible = TRUE;	// initially visible
	bVisible = !bVisible;
	CReBarCtrl rebar = m_hWndToolBar;
	int nBandIndex = rebar.IdToIndex(ATL_IDW_BAND_FIRST + 1);	// toolbar is 2nd added band
	rebar.ShowBand(nBandIndex, bVisible);
	UISetCheck(ID_VIEW_TOOLBAR, bVisible);
	UpdateLayout();
	return 0;
}

LRESULT CMainFrame::OnViewStatusBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	BOOL bVisible = !::IsWindowVisible(m_hWndStatusBar);
	::ShowWindow(m_hWndStatusBar, bVisible ? SW_SHOWNOACTIVATE : SW_HIDE);
	UISetCheck(ID_VIEW_STATUS_BAR, bVisible);
	UpdateLayout();
	return 0;
}

LRESULT CMainFrame::OnViewTree(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	BOOL bVisible = !::IsWindowVisible(m_paneTree);
	::ShowWindow(m_paneTree, bVisible ? SW_SHOWNOACTIVATE : SW_HIDE);
	UISetCheck(ID_VIEW_TREE, bVisible);
	m_splitter.SetSinglePaneMode(bVisible ? SPLIT_PANE_NONE : SPLIT_PANE_RIGHT);
	UpdateLayout();
	return 0;
}

LRESULT CMainFrame::OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CAboutDlg dlg;
	dlg.DoModal();
	return 0;
}

BOOL CMainFrame::updateUrl(const char* pUrl)
{
	IWebBrowser2* ppBrowser = NULL ;
	this->m_view1.get_Browser(&ppBrowser) ;
	if(NULL == ppBrowser)
	{
		return FALSE ;
	}
	ppBrowser->Stop() ;
	
	VARIANT varProject;
	const char *pszMsg = pUrl ;

	VARIANT p1;
	VARIANT p2;
	VARIANT p3;
	VariantInit(&varProject);
	VariantInit(&p1);
	VariantInit(&p2);
	VariantInit(&p3);

	p2.vt = VT_BSTR;
	p2.bstrVal = SysAllocString(A2BSTR(pszMsg));
 
	CString *s = new CString(p2.bstrVal);
	varProject.vt = VT_BSTR;
	p1.vt = VT_BSTR;
	p1.bstrVal= SysAllocString(A2BSTR(pszMsg));
	//varProject.bstrVal = SysAllocString(A2BSTR(pszMsg1));
	
	ppBrowser->Navigate2(&p2,0,0,0,0);
	return TRUE ;
}
