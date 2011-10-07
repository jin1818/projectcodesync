// groupbuyV2.h : main header file for the GROUPBUYV2 application
//

#if !defined(AFX_GROUPBUYV2_H__B984F01B_BA3F_4762_9383_61E842B903D1__INCLUDED_)
#define AFX_GROUPBUYV2_H__B984F01B_BA3F_4762_9383_61E842B903D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGroupbuyV2App:
// See groupbuyV2.cpp for the implementation of this class
//

class CGroupbuyV2App : public CWinApp
{
public:
	CGroupbuyV2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGroupbuyV2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGroupbuyV2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROUPBUYV2_H__B984F01B_BA3F_4762_9383_61E842B903D1__INCLUDED_)
