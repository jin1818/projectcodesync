// WeatherDlg.cpp : implementation file
//

#include "stdafx.h"
#include "linkmgr.h"
#include "WeatherDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWeatherDlg dialog


CWeatherDlg::CWeatherDlg(CWnd* pParent /*=NULL*/)
	: CPropertyPage(CWeatherDlg::IDD)
{
	//{{AFX_DATA_INIT(CWeatherDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWeatherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWeatherDlg)
	DDX_Control(pDX, IDC_EXPLORER_WEATHER, m_ie);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWeatherDlg, CDialog)
	//{{AFX_MSG_MAP(CWeatherDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeatherDlg message handlers

BOOL CWeatherDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	RECT rect;
	this->GetWindowRect(&rect);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	m_ie.Navigate(CString("http://www.cppentry.com/life/taobaoweather.html") , NULL , NULL , NULL , NULL) ;
	m_ie.MoveWindow(0,0,width,height) ;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
