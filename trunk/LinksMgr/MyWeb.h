#if !defined(AFX_MYWEB_H__6D8EB75C_54C3_4196_827F_DFA27F291568__INCLUDED_)
#define AFX_MYWEB_H__6D8EB75C_54C3_4196_827F_DFA27F291568__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyWeb.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyWeb dialog

class CMyWeb : public CDialog
{
// Construction
public:
	CMyWeb(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyWeb)
	enum { IDD = IDD_DIALOG_LINKS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWeb)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyWeb)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWEB_H__6D8EB75C_54C3_4196_827F_DFA27F291568__INCLUDED_)
