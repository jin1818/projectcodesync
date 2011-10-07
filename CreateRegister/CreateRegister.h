// CreateRegister.h : main header file for the CREATEREGISTER application
//

#if !defined(AFX_CREATEREGISTER_H__B8F8BD4B_6AAA_4E59_B7EA_3B671F642DE9__INCLUDED_)
#define AFX_CREATEREGISTER_H__B8F8BD4B_6AAA_4E59_B7EA_3B671F642DE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateRegisterApp:
// See CreateRegister.cpp for the implementation of this class
//

class CCreateRegisterApp : public CWinApp
{
public:
	CCreateRegisterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateRegisterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateRegisterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEREGISTER_H__B8F8BD4B_6AAA_4E59_B7EA_3B671F642DE9__INCLUDED_)
