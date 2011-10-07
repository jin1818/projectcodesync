// lifetoolDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_LIFETOOLDLG_H__558AC10B_A7D4_4765_8FCF_8C52C5CA77C8__INCLUDED_)
#define AFX_LIFETOOLDLG_H__558AC10B_A7D4_4765_8FCF_8C52C5CA77C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLifetoolDlg dialog

class CLifetoolDlg : public CDialog
{
// Construction
public:
	CLifetoolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLifetoolDlg)
	enum { IDD = IDD_LIFETOOL_DIALOG };
	CButton	m_weather;
	CWebBrowser2	m_webbrowser;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLifetoolDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLifetoolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton();
	afx_msg void OnIpaddres();
	afx_msg void OnChongzhi();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIFETOOLDLG_H__558AC10B_A7D4_4765_8FCF_8C52C5CA77C8__INCLUDED_)
