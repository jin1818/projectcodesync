#if !defined(AFX_SKINWND_H__7D135A05_FE2B_409F_ABFC_7FD2FAF42C7B__INCLUDED_)
#define AFX_SKINWND_H__7D135A05_FE2B_409F_ABFC_7FD2FAF42C7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkinWnd.h : header file
//

#include "ImgSkin.h"

/////////////////////////////////////////////////////////////////////////////
// CSkinWnd window

class CSkinWnd : public CWnd, public CImgSkin
{
// Construction
public:
	CSkinWnd();

	bool LoadSkin(const char * szSkinPath = NULL, const char * szControlName="CWnd");

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSkinWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinWnd)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINWND_H__7D135A05_FE2B_409F_ABFC_7FD2FAF42C7B__INCLUDED_)
