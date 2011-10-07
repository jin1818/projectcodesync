// Register.cpp : implementation file
//

#include "stdafx.h"
#include "qzonepicture.h"
#include "Register.h"

#include "../createregister/auth.h" 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Register dialog


Register::Register(CWnd* pParent /*=NULL*/)
: CDialog(Register::IDD, pParent)
{
	//{{AFX_DATA_INIT(Register)
	m_src = _T("");
	m_dst = _T("");
	m_qqnum = _T("2202082108");
	//}}AFX_DATA_INIT
}


void Register::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Register)
	DDX_Text(pDX, IDC_EDIT_SRC, m_src);
	DDX_Text(pDX, IDC_EDIT_DST, m_dst);
	DDX_Text(pDX, IDC_EDIT_QQ, m_qqnum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Register, CDialog)
//{{AFX_MSG_MAP(Register)
ON_BN_CLICKED(IDC_BUTTON_GOREGISTER, OnButtonGoregister)
ON_BN_CLICKED(IDC_BUTTON_PAY, OnButtonPay)
ON_BN_CLICKED(IDC_BUTTON_CALLME, OnButtonCallme)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Register message handlers

void Register::OnButtonGoregister() 
{
	this->UpdateData() ;
	if (registerSoftware(m_src , m_dst) == 0 )
	{
		MessageBox("×¢²á³É¹¦") ;
		OnOK() ;
	}
}

void Register::OnButtonPay() 
{
	ShellExecute(this->GetSafeHwnd() 
		,   NULL
		,   "http://item.taobao.com/item.htm?id=13085675102" 
		,   NULL
		,   NULL
		,   SW_SHOWNORMAL);
}

void Register::OnButtonCallme() 
{
	ShellExecute(this->GetSafeHwnd() 
		,   NULL
		,   "http://wpa.qq.com/msgrd?v=3&uin=2202082108&site=qq&menu=yes"
		,   NULL
		,   NULL
		,   SW_SHOWNORMAL);
}
