// InternetShop.cpp : implementation file
//

#include "stdafx.h"
#include "risingui.h"
#include "InternetShop.h"
#include "common.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInternetShop dialog


CInternetShop::CInternetShop(CWnd* pParent /*=NULL*/)
	: CSkinDialog(CInternetShop::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInternetShop)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CInternetShop::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInternetShop)
	DDX_Control(pDX, IDC_EXPLORER, m_browser);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInternetShop, CDialog)
	//{{AFX_MSG_MAP(CInternetShop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInternetShop message handlers

BOOL CInternetShop::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	LoadSkin("./skin/skin1.xml", "DlgLink");
	char viewPath[2*MAX_PATH] = {0} ;
	sprintf(viewPath , "%s\\internetshop.html" , getModulePath()) ;
	m_browser.Navigate(viewPath,NULL,NULL,NULL,NULL) ;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CInternetShop::MoveWindow(LPCRECT lpRect, BOOL bRepaint)
{
	CSkinDialog::MoveWindow(lpRect , bRepaint) ;

	m_browser.MoveWindow(lpRect , bRepaint) ;

}
