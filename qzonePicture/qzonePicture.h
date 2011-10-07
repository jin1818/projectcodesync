// qzonePicture.h : main header file for the QZONEPICTURE application
//

#if !defined(AFX_QZONEPICTURE_H__E5542C0C_EDE5_4E4B_BE84_5E59B7A9EE09__INCLUDED_)
#define AFX_QZONEPICTURE_H__E5542C0C_EDE5_4E4B_BE84_5E59B7A9EE09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQzonePictureApp:
// See qzonePicture.cpp for the implementation of this class
//

class CQzonePictureApp : public CWinApp
{
public:
	CQzonePictureApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQzonePictureApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CQzonePictureApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QZONEPICTURE_H__E5542C0C_EDE5_4E4B_BE84_5E59B7A9EE09__INCLUDED_)
