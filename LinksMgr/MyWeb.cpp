// MyWeb.cpp : implementation file
//

#include "stdafx.h"
#include "LinksMgr.h"
#include "MyWeb.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyWeb dialog


CMyWeb::CMyWeb(CWnd* pParent /*=NULL*/)
	: CDialog(CMyWeb::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyWeb)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMyWeb::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyWeb)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyWeb, CDialog)
	//{{AFX_MSG_MAP(CMyWeb)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyWeb message handlers
