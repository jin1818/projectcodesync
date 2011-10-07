// pic.h : main header file for the PIC application
//

#if !defined(AFX_PIC_H__927D263E_D024_4B73_B1EF_D90ECA853B1B__INCLUDED_)
#define AFX_PIC_H__927D263E_D024_4B73_B1EF_D90ECA853B1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPicApp:
// See pic.cpp for the implementation of this class
//

class CPicApp : public CWinApp
{
public:
	CPicApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPicApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIC_H__927D263E_D024_4B73_B1EF_D90ECA853B1B__INCLUDED_)
