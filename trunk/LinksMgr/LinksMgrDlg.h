// LinksMgrDlg.h : header file
//

#if !defined(AFX_LINKSMGRDLG_H__F0A9D05E_8658_4B2A_8388_8A5EDEF3094A__INCLUDED_)
#define AFX_LINKSMGRDLG_H__F0A9D05E_8658_4B2A_8388_8A5EDEF3094A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MYWEB.h"

/////////////////////////////////////////////////////////////////////////////
// CLinksMgrDlg dialog

class CLinksMgrDlg : public CDialog
{
// Construction
public:
	CLinksMgrDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLinksMgrDlg)
	enum { IDD = IDD_LINKSMGR_DIALOG };
	CTabCtrl	m_tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinksMgrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CMyWeb m_myWeb ;

	// Generated message map functions
	//{{AFX_MSG(CLinksMgrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKSMGRDLG_H__F0A9D05E_8658_4B2A_8388_8A5EDEF3094A__INCLUDED_)
