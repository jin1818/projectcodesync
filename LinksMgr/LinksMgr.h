// LinksMgr.h : main header file for the LINKSMGR application
//

#if !defined(AFX_LINKSMGR_H__1A9F2B77_D527_4591_A0F4_3C5A2B724ABE__INCLUDED_)
#define AFX_LINKSMGR_H__1A9F2B77_D527_4591_A0F4_3C5A2B724ABE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLinksMgrApp:
// See LinksMgr.cpp for the implementation of this class
//

class CLinksMgrApp : public CWinApp
{
public:
	CLinksMgrApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinksMgrApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLinksMgrApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKSMGR_H__1A9F2B77_D527_4591_A0F4_3C5A2B724ABE__INCLUDED_)
