// SplitDemo.h : main header file for the SplitDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSplitDemoApp:
// See SplitDemo.cpp for the implementation of this class
//

class CSplitDemoApp : public CWinApp
{
public:
	CSplitDemoApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSplitDemoApp theApp;