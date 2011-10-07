// showpic.h : main header file for the SHOWPIC application
//

#if !defined(AFX_SHOWPIC_H__CB074BBF_399F_47CE_98CF_F378DCE98EDB__INCLUDED_)
#define AFX_SHOWPIC_H__CB074BBF_399F_47CE_98CF_F378DCE98EDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowpicApp:
// See showpic.cpp for the implementation of this class
//

class CShowpicApp : public CWinApp
{
public:
	CShowpicApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowpicApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShowpicApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWPIC_H__CB074BBF_399F_47CE_98CF_F378DCE98EDB__INCLUDED_)
