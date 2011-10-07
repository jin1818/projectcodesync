// WebBrowser2Ex.cpp: implementation of the CWebBrowser2Ex class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "groupbuyV2.h"
#include "WebBrowser2Ex.h"

#include "groupbuyV2Dlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWebBrowser2Ex::CWebBrowser2Ex()
{

}

CWebBrowser2Ex::~CWebBrowser2Ex()
{
}

void CWebBrowser2Ex::resetProcess()
{
	((CGroupbuyV2Dlg*)AfxGetApp()->m_pMainWnd)->resetProcess() ;
}
