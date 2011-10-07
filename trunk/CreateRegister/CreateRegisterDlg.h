// CreateRegisterDlg.h : header file
//

#if !defined(AFX_CREATEREGISTERDLG_H__10D9706E_622A_4DA6_9F68_B5E2ED548BC4__INCLUDED_)
#define AFX_CREATEREGISTERDLG_H__10D9706E_622A_4DA6_9F68_B5E2ED548BC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateRegisterDlg dialog

class CCreateRegisterDlg : public CDialog
{
// Construction
public:
	CCreateRegisterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateRegisterDlg)
	enum { IDD = IDD_CREATEREGISTER_DIALOG };
	CString	m_dst;
	CString	m_src;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateRegisterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateRegisterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonCreate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEREGISTERDLG_H__10D9706E_622A_4DA6_9F68_B5E2ED548BC4__INCLUDED_)
