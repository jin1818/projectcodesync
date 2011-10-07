// popie.h : main header file for the POPIE application
//

#if !defined(AFX_POPIE_H__DE13A400_DA66_4F09_95B9_B6BC585F3F42__INCLUDED_)
#define AFX_POPIE_H__DE13A400_DA66_4F09_95B9_B6BC585F3F42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "../rzxsvrseach.h"
#include "../winused.h"
#include "../appname.h"
#include "../appstruct.h"
#include "../waterworker.h"


/////////////////////////////////////////////////////////////////////////////
// CPopieApp:
// See popie.cpp for the implementation of this class
//

class CPopieApp : public CWinApp
{
public:
	CPopieApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopieApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPopieApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPIE_H__DE13A400_DA66_4F09_95B9_B6BC585F3F42__INCLUDED_)
