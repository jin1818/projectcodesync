// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "linkmgr.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include "sysrun.h"
NOTIFYICONDATA  g_nd;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog


CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
	, m_flags(SW_SHOW)
{
	//{{AFX_DATA_INIT(CMainDlg)
	m_autoRun = FALSE;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDlg)
	DDX_Check(pDX, IDC_CHECK_AUTORUN, m_autoRun);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	//{{AFX_MSG_MAP(CMainDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_COMMAND(ID_RUN, OnRun)
	ON_BN_CLICKED(IDC_CHECK_AUTORUN, OnCheckAutorun)
	ON_BN_CLICKED(IDC_HIDE, OnHide)
	ON_MESSAGE(MYWM_NOTIFYICON,OnNOTIFYICON)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg message handlers

BOOL CMainDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
		// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_autoRun = checkRun() > 0 ? true : false ;

	m_sheet.AddPage(&m_pageLinkMgr) ;	
	m_sheet.AddPage(&m_pageWeather) ;

	
	m_sheet.Create(this, WS_CHILD | WS_VISIBLE, WS_EX_CONTROLPARENT);
	
	RECT rect;
	m_sheet.GetWindowRect(&rect);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	
	//调整属性页的大小和位置
	m_sheet.SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

	AddSystrayIcon();

	this->UpdateData(FALSE) ;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



/////////////////////////////////////////////////////////////////////////////
// CLinkMgrDlg message handlers
void CMainDlg::OnNOTIFYICON(WPARAM wParam, LPARAM lParam) 
{
	if(lParam==WM_LBUTTONDBLCLK)
	{
		if (m_flags == SW_SHOW)
		{
			m_flags = SW_HIDE ;
		}
		else 
		{
			m_flags = SW_SHOW ;
		}
		AfxGetApp()->m_pMainWnd->ShowWindow(m_flags);
		
	}else if(lParam==WM_RBUTTONDOWN)		
	{
		
/*		CMenu menu;
		
		//载入事先定义的选单
		
		menu.LoadMenu(IDR_TRADEMEMU);
		
		CMenu*pMenu=menu.GetSubMenu(0);
		
		CPoint pos;
		
		GetCursorPos(&pos);
		
		//加入SetForegroundWindow的目的为使用户点菜单之外时菜单可以消失
		
		::SetForegroundWindow(m_hWnd);
		
		pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,pos.x,pos.y,AfxGetMainWnd());
*/		
	}
	
}


void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMainDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CMainDlg::AddSystrayIcon()
{
	
	// 将图标放入系统托盘
	
	g_nd.cbSize = sizeof (NOTIFYICONDATA);
	
	g_nd.hWnd = m_hWnd;
	
	g_nd.uID = IDR_MAINFRAME;
	
	g_nd.uFlags = NIF_ICON|NIF_MESSAGE|NIF_TIP;
	
	g_nd.uCallbackMessage= MYWM_NOTIFYICON;
	
	g_nd.hIcon = m_hIcon;
	
	strcpy(g_nd.szTip, "");
	
	Shell_NotifyIcon(NIM_ADD, &g_nd);
	
}

void CMainDlg::DelSystrayIcon()
{
	Shell_NotifyIcon(NIM_DELETE, &g_nd);
}

void CMainDlg::OnDestroy() 
{
	DelSystrayIcon() ;
	CDialog::OnDestroy();
}

void CMainDlg::OnHide() 
{
	m_flags = SW_HIDE ;
	this->ShowWindow(m_flags) ;
}


void CMainDlg::OnRun() 
{
	m_pageLinkMgr.OnRun() ;
}

void CMainDlg::OnCheckAutorun() 
{
	this->UpdateData() ;
	if (m_autoRun)
	{
		RegisterSysInit() ;
	}
	else
	{
		CleanIniReg() ;
	}
}
