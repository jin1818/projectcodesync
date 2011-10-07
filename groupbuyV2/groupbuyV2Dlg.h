// groupbuyV2Dlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_GROUPBUYV2DLG_H__ACD756D7_774F_43FF_906A_29200D77EDC4__INCLUDED_)
#define AFX_GROUPBUYV2DLG_H__ACD756D7_774F_43FF_906A_29200D77EDC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>
#include <string>
#include "WebBrowser2Ex.h"
using namespace std ;

/////////////////////////////////////////////////////////////////////////////
// CGroupbuyV2Dlg dialog

class CGroupbuyV2Dlg : public CDialog
{
// Construction
public:
	void getWebSites();
	void resetProcess() ;
	CGroupbuyV2Dlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	//{{AFX_DATA(CGroupbuyV2Dlg)
	enum { IDD = IDD_GROUPBUYV2_DIALOG };
	CProgressCtrl	m_loadProcess;
	CListCtrl	m_websites;
	CWebBrowser2Ex	m_webbrowser;
	BOOL	m_autoRun;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGroupbuyV2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	map<string , string> m_WetSites ;
	int	m_flags ;
	void AddSystrayIcon() ;
	void DelSystrayIcon() ;
	
	POINT Old;//存放对话框的宽和高。

	// Generated message map functions
	//{{AFX_MSG(CGroupbuyV2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonBack();
	afx_msg void OnButtonForward();
	afx_msg void OnButtonHomepage();
	afx_msg void OnButtonReload();
	afx_msg void OnButtonSearch();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnCheckAutorun();
	afx_msg void OnButtonHide();
	afx_msg void OnDestroy();
	afx_msg void OnNOTIFYICON(WPARAM wParam, LPARAM lParam);
	afx_msg void OnButtonStop();
	afx_msg void OnAbout();
	afx_msg void OnBUTTONchongzhi();
	afx_msg void OnBUTTONshiyijian();
	afx_msg void OnExitEx();
	afx_msg void OnButtonCaipiao();
	afx_msg void OnButtonXianhua();
	afx_msg void OnButtonLvyou();
	afx_msg void OnButtonTushu();
	afx_msg void OnDocumentCompleteExplorer(LPDISPATCH pDisp, VARIANT FAR* URL);
	afx_msg void OnBeforeNavigate2Explorer(LPDISPATCH pDisp, VARIANT FAR* URL, VARIANT FAR* Flags, VARIANT FAR* TargetFrameName, VARIANT FAR* PostData, VARIANT FAR* Headers, BOOL FAR* Cancel);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROUPBUYV2DLG_H__ACD756D7_774F_43FF_906A_29200D77EDC4__INCLUDED_)
