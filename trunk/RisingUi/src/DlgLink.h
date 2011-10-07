#if !defined(AFX_DLGLINK_H__CCE502C2_6AC3_4B74_A824_6C8EF82EDC5B__INCLUDED_)
#define AFX_DLGLINK_H__CCE502C2_6AC3_4B74_A824_6C8EF82EDC5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgLink.h : header file
//

#include "./skin/SkinDialog.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgLink dialog

class CDlgLink : public CSkinDialog
{
// Construction
public:
	CDlgLink(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgLink)
	enum { IDD = IDD_Link };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgLink)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgLink)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLINK_H__CCE502C2_6AC3_4B74_A824_6C8EF82EDC5B__INCLUDED_)
