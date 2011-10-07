// picDlg.h : header file
//

#if !defined(AFX_PICDLG_H__44DEB826_16FB_4744_B456_AB5D61E8CEF5__INCLUDED_)
#define AFX_PICDLG_H__44DEB826_16FB_4744_B456_AB5D61E8CEF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPicDlg dialog

#include "msgwnd.h"

class CPicDlg : public CDialog
{
// Construction
public:
	CPicDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPicDlg)
	enum { IDD = IDD_PIC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CMsgWnd *pMsgWindow ;

	// Generated message map functions
	//{{AFX_MSG(CPicDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICDLG_H__44DEB826_16FB_4744_B456_AB5D61E8CEF5__INCLUDED_)
