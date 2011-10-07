#if !defined(AFX_REGISTER_H__F99683BA_9623_4326_9C23_C414B1A93756__INCLUDED_)
#define AFX_REGISTER_H__F99683BA_9623_4326_9C23_C414B1A93756__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Register.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Register dialog

class Register : public CDialog
{
// Construction
public:
	Register(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Register)
	enum { IDD = IDD_DIALOG_REGISTER };
	CString	m_src;
	CString	m_dst;
	CString	m_qqnum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Register)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Register)
	afx_msg void OnButtonGoregister();
	afx_msg void OnButtonPay();
	afx_msg void OnButtonCallme();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTER_H__F99683BA_9623_4326_9C23_C414B1A93756__INCLUDED_)
