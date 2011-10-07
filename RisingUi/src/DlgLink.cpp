// DlgLink.cpp : implementation file
//

#include "stdafx.h"
#include "risingui.h"
#include "DlgLink.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgLink dialog


CDlgLink::CDlgLink(CWnd* pParent /*=NULL*/)
	: CSkinDialog(CDlgLink::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLink)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgLink::DoDataExchange(CDataExchange* pDX)
{
	CSkinDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLink)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLink, CSkinDialog)
	//{{AFX_MSG_MAP(CDlgLink)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLink message handlers

BOOL CDlgLink::OnInitDialog() 
{
	CSkinDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	LoadSkin("./skin/skin1.xml", "DlgLink");


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
