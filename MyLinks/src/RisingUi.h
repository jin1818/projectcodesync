// RisingUi.h : main header file for the RISINGUI application
//

#if !defined(AFX_RISINGUI_H__B1171063_0797_45E3_9061_F144B66A5FE7__INCLUDED_)
#define AFX_RISINGUI_H__B1171063_0797_45E3_9061_F144B66A5FE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRisingUiApp:
// See RisingUi.cpp for the implementation of this class
//

class CRisingUiApp : public CWinApp
{
public:
	CRisingUiApp();

	ULONG_PTR m_gdiplusToken;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRisingUiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRisingUiApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RISINGUI_H__B1171063_0797_45E3_9061_F144B66A5FE7__INCLUDED_)
