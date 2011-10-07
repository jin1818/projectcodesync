// snapscreen.h : main header file for the SNAPSCREEN application
//

#if !defined(AFX_SNAPSCREEN_H__74A31B0E_3148_46CB_AF43_A2957D63EAD6__INCLUDED_)
#define AFX_SNAPSCREEN_H__74A31B0E_3148_46CB_AF43_A2957D63EAD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSnapscreenApp:
// See snapscreen.cpp for the implementation of this class
//

class CSnapscreenApp : public CWinApp
{
public:
	CSnapscreenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnapscreenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSnapscreenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAPSCREEN_H__74A31B0E_3148_46CB_AF43_A2957D63EAD6__INCLUDED_)
