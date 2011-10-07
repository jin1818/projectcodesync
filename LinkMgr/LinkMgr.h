// LinkMgr.h : main header file for the LINKMGR application
//

#if !defined(AFX_LINKMGR_H__3BD7C774_FB5D_4216_B74F_33991AE28051__INCLUDED_)
#define AFX_LINKMGR_H__3BD7C774_FB5D_4216_B74F_33991AE28051__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLinkMgrApp:
// See LinkMgr.cpp for the implementation of this class
//

class CLinkMgrApp : public CWinApp
{
public:
	CLinkMgrApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkMgrApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLinkMgrApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKMGR_H__3BD7C774_FB5D_4216_B74F_33991AE28051__INCLUDED_)
