//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES
#if !defined(AFX_INTERNETSHOP_H__6566063E_A257_432A_A108_5AEAD7AE399B__INCLUDED_)
#define AFX_INTERNETSHOP_H__6566063E_A257_432A_A108_5AEAD7AE399B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InternetShop.h : header file
//

#include "./skin/SkinDialog.h"

/////////////////////////////////////////////////////////////////////////////
// CInternetShop dialog

class CInternetShop : public CSkinDialog
{
// Construction
public:
	CInternetShop(CWnd* pParent = NULL);   // standard constructor
	void MoveWindow(LPCRECT lpRect, BOOL bRepaint = TRUE);

// Dialog Data
	//{{AFX_DATA(CInternetShop)
	enum { IDD = IDD_InternetShop };
	CWebBrowser2	m_browser;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInternetShop)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInternetShop)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERNETSHOP_H__6566063E_A257_432A_A108_5AEAD7AE399B__INCLUDED_)
