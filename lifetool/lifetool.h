// lifetool.h : main header file for the LIFETOOL application
//

#if !defined(AFX_LIFETOOL_H__7DFB2948_0139_47C5_817E_30D018E03954__INCLUDED_)
#define AFX_LIFETOOL_H__7DFB2948_0139_47C5_817E_30D018E03954__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLifetoolApp:
// See lifetool.cpp for the implementation of this class
//

class CLifetoolApp : public CWinApp
{
public:
	CLifetoolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLifetoolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLifetoolApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIFETOOL_H__7DFB2948_0139_47C5_817E_30D018E03954__INCLUDED_)
