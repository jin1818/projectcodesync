// DlgInfo.cpp : implementation file
//

#include "stdafx.h"
#include "RisingUi.h"
#include "DlgInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgInfo dialog


CDlgInfo::CDlgInfo(CWnd* pParent /*=NULL*/)
	: CSkinDialog(CDlgInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgInfo::DoDataExchange(CDataExchange* pDX)
{
	CSkinDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgInfo)
	DDX_Control(pDX, IDC_BTN_UPDATE, m_btnUpdate);
	DDX_Control(pDX, IDC_BTN_PRO, m_btnPro);
	DDX_Control(pDX, IDC_BTN_KILL, m_btnKill);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDC_TXT_TARGET, m_txtTarget);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgInfo, CSkinDialog)
	//{{AFX_MSG_MAP(CDlgInfo)
	ON_BN_CLICKED(IDC_BTN_KILL, OnBtnKill)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgInfo message handlers

BOOL CDlgInfo::OnInitDialog() 
{
	CSkinDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	LoadSkin("./skin/skin1.xml", "DlgInfo");
	m_slider.LoadSkin("./skin/skin1.xml");

	m_slider.SetRange(0, 100);
	m_slider.SetPos(50);

	m_btnKill.LoadSkin("./skin/skin1.xml", "BtnKill");
	m_btnPro.LoadSkin("./skin/skin1.xml", "BtnPro");
	m_btnUpdate.LoadSkin("./skin/skin1.xml", "BtnUpdate");

	// ModifyStyle(0, WS_CLIPCHILDREN);

	m_txtTarget.SetTransparent(TRUE);
	m_txtTarget.SetTextColor(RGB(255,255,255));

	AddAnchor(IDC_SLIDER1, ANCHOR_BOTTOMLEFT|ANCHOR_BOTTOMRIGHT);
	AddAnchor(IDC_BTN_KILL, ANCHOR_BOTTOMLEFT|ANCHOR_BOTTOMLEFT);
	AddAnchor(IDC_BTN_PRO,  ANCHOR_BOTTOMRIGHT);
	AddAnchor(IDC_BTN_UPDATE, ANCHOR_BOTTOM);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInfo::OnBtnKill() 
{
	// TODO: Add your control notification handler code here

}

