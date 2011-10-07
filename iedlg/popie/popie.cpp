// popie.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "popie.h"
#include "popieDlg.h"
#include "..\appname.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopieApp

BEGIN_MESSAGE_MAP(CPopieApp, CWinApp)
	//{{AFX_MSG_MAP(CPopieApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopieApp construction

CPopieApp::CPopieApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPopieApp object

CPopieApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPopieApp initialization

BOOL CPopieApp::InitInstance()
{	  	
/*	PVOID psharemem;
	HANDLE hShareMem;
	PAPPSHAREINFO m_pControlInfo;
	if(hShareMem=wuCreateShareMem(psharemem,4096*2,APP_FLAG_STRING))
	{

		if(0==SharemInit(m_pControlInfo=(PAPPSHAREINFO)psharemem,APP_FLAG_STRING))
		{
			wuCloseShareMem(hShareMem,psharemem);
			return TRUE;

		}
	}
	   */
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	CPopieDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
