#if !defined(AFX_SETHOTKEY_H__8797B09B_9A11_4778_9763_178B44339A54__INCLUDED_)
#define AFX_SETHOTKEY_H__8797B09B_9A11_4778_9763_178B44339A54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetHotKey.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SetHotKey dialog

class SetHotKey : public CDialog
{
// Construction
public:
	SetHotKey(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SetHotKey)
	enum { IDD = IDD_DIALOG1 };
	CString	m_key;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SetHotKey)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SetHotKey)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETHOTKEY_H__8797B09B_9A11_4778_9763_178B44339A54__INCLUDED_)
