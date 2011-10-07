// snapscreenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "snapscreen.h"
#include "snapscreenDlg.h"

#include "SetHotKey.h"
#include "../CreateRegister/auth.h"
#include "Register.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define WM_MYMESSAGE (WM_USER + 101)   

static CString hotkeyStr = "1.同时按下ctrl + alt + " ;
static CString hotkeySetErr = "1.热键设置失败,请重新设置" ;

int StartupChildProcess(const char * szCmdLine,int nSync ) ;

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
// CSnapscreenDlg dialog

CSnapscreenDlg::CSnapscreenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSnapscreenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSnapscreenDlg)
	m_pic_is_edit = TRUE ;
	m_pic_is_copy = TRUE ;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSnapscreenDlg::~CSnapscreenDlg()
{
}


void CSnapscreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSnapscreenDlg)
	DDX_Check(pDX, IDC_CHECK2, m_pic_is_edit);
	DDX_Check(pDX, IDC_CHECK1, m_pic_is_copy);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSnapscreenDlg, CDialog)
	//{{AFX_MSG_MAP(CSnapscreenDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_WEB_URL, OnWebUrl)
	ON_MESSAGE(WM_HOTKEY,OnHotkey)  
	ON_MESSAGE(WM_MYMESSAGE,OnMYMESSAGE)
	ON_BN_CLICKED(ID_MINIZE, OnMinize)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_WM_CLOSE()
	ON_BN_CLICKED(ID_SNAP, OnSnap)
	ON_BN_CLICKED(ID_SET_HOTKEY, OnSetHotkey)
	ON_BN_CLICKED(IDC_BUTTON_MAINREGISTER, OnButtonMainregister)
	ON_BN_CLICKED(IDC_BUTTON_TIMERSNAP, OnButtonTimersnap)
	ON_BN_CLICKED(IDC_BUTTON_WHOLESCREEN, OnButtonWholescreen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnapscreenDlg message handlers

BOOL CSnapscreenDlg::OnInitDialog()
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



	NOTIFYICONDATA tnd;
	tnd.cbSize=sizeof(NOTIFYICONDATA);
	tnd.hWnd=this->m_hWnd;
	tnd.uID=IDR_MAINFRAME;
	tnd.uFlags=NIF_MESSAGE|NIF_ICON|NIF_TIP;
	tnd.uCallbackMessage=WM_MYMESSAGE;
	//file://用户自定义的消息，即鼠标在任务栏上程序图标上动作时图标发送的消息
	tnd.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
	strcpy(tnd.szTip,"和风截图");//图标提示为"测试程序"
	Shell_NotifyIcon(NIM_ADD,&tnd);//向任务栏添加图标

	if (!RegisterHotKey(this->m_hWnd, 2009, MOD_CONTROL | MOD_ALT, 'w')
		|| !RegisterHotKey(this->m_hWnd, 2009, MOD_CONTROL | MOD_ALT, 'W')) 
	{
		MessageBox("热键冲突，注册W失败") ;
		((CWnd*)GetDlgItem(IDC_STATIC_HOTKEY))->SetWindowText(hotkeySetErr) ;
	}
	else {
		((CWnd*)GetDlgItem(IDC_STATIC_HOTKEY))->SetWindowText(hotkeyStr + "W") ;
	}
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

LONG CSnapscreenDlg::OnHotkey(WPARAM wParam,LPARAM lParam)
{
	char szCmd[MAX_PATH]={0} ;
	sprintf(szCmd , "CatchScreen.exe %d" , this->m_pic_is_edit) ;
	ShowWindow(SW_HIDE) ;
	StartupChildProcess(szCmd ,	1) ;
	ShowWindow(SW_SHOW) ;
	
	return 0 ;
}

void CSnapscreenDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSnapscreenDlg::OnPaint() 
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
HCURSOR CSnapscreenDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSnapscreenDlg::OnWebUrl() 
{
	ShellExecute(this->GetSafeHwnd() 
		,   NULL
		,   "http://wpa.qq.com/msgrd?v=3&uin=2202082108&site=qq&menu=yes"
		,   NULL
		,   NULL
		,   SW_SHOWNORMAL);
}

void CSnapscreenDlg::OnMYMESSAGE(WPARAM wParam,LPARAM lParam)
{
	UINT uID;//发出该消息的图标的ID
	UINT uMouseMsg;//鼠标动作
	POINT pt;
	uID=(UINT) wParam;
	uMouseMsg=(UINT) lParam;
	if(uMouseMsg==WM_RBUTTONDOWN || uMouseMsg == WM_LBUTTONDOWN || uMouseMsg == WM_LBUTTONDBLCLK)//如果是单击右键
	{
		switch(uID)
		{
		case IDR_MAINFRAME://如果是我们的图标
			GetCursorPos(&pt);//取得鼠标位置
			AfxGetApp( )-> m_pMainWnd->ShowWindow(SW_SHOWNORMAL);//显示程序窗口
			break;
		default:
			break ;
		}
	}
	return; 
} 



int StartupChildProcess(const char * szCmdLine,int nSync )
{

	OutputDebugString(szCmdLine) ;

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
	
    // Start the child process. 
    if( !CreateProcess( NULL,   // No module name (use command line). 
        (LPSTR)szCmdLine,           // Command line. 
        NULL,             // Process handle not inheritable. 
        NULL,             // Thread handle not inheritable. 
        FALSE,            // Set handle inheritance to FALSE. 
        NORMAL_PRIORITY_CLASS   |   CREATE_NO_WINDOW,                //不显示窗口 No creation flags. 
        NULL,             // Use parent's environment block. 
        NULL,             // Use parent's starting directory. 
        &si,              // Pointer to STARTUPINFO structure.
        &pi )             // Pointer to PROCESS_INFORMATION structure.
		) 
    {
        //printf( "CreateProcess failed (%d).\n", GetLastError() );
		OutputDebugString("StartupChildProcess FALSE") ;
		
        return -1;
    }
	
    if(nSync)
    {
		// Wait until child process exits.
		WaitForSingleObject( pi.hProcess, INFINITE );
		// Close process and thread handles. 
		CloseHandle( pi.hProcess );
		CloseHandle( pi.hThread );
    }else
	{
		WaitForSingleObject( pi.hProcess, 1);
	}	
	return 0;
}


void CSnapscreenDlg::OnMinize() 
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE); //隐藏窗口
}

void CSnapscreenDlg::OnCheck2() 
{
	// TODO: Add your control notification handler code here
	this->m_pic_is_edit = !this->m_pic_is_edit ;
}

void CSnapscreenDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

	NOTIFYICONDATA tnid;
	tnid.cbSize=sizeof(NOTIFYICONDATA);
	tnid.hWnd=this->m_hWnd;
	tnid.uID=IDR_MAINFRAME;//保证删除的是我们的图标
	Shell_NotifyIcon(NIM_DELETE,&tnid);

	UnregisterHotKey(this->m_hWnd, 2009) ;
	
	CDialog::OnClose();
}

void CSnapscreenDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	OnClose() ;

	CDialog::OnCancel();	
}

void CSnapscreenDlg::OnSnap() 
{
	// TODO: Add your control notification handler code here
	char szCmd[MAX_PATH]={0} ;
	sprintf(szCmd , "CatchScreen.exe %d" , this->m_pic_is_edit) ;
	ShowWindow(SW_HIDE) ;
	StartupChildProcess(szCmd ,	1) ;
	ShowWindow(SW_SHOW) ;
}

void CSnapscreenDlg::OnSetHotkey() 
{
	// TODO: Add your control notification handler code here
	SetHotKey dlg ;
	dlg.DoModal() ;
	static int hotkeyid = 2010 ;
	
	if (!RegisterHotKey(this->m_hWnd, hotkeyid++, MOD_CONTROL | MOD_ALT, toupper(dlg.m_key.GetAt(0)))) 
	{
		MessageBox("热键冲突，注册失败") ;
	}
	else {
		((CWnd*)GetDlgItem(IDC_STATIC_HOTKEY))->SetWindowText(hotkeyStr + dlg.m_key) ;
	}
}

void CSnapscreenDlg::OnButtonMainregister() 
{
	if (checkRegister() != 0) {
		CString src = getSrcCode(99999) ;
		Register reg ;
		reg.m_src = src ;
		reg.DoModal() ;
	}
	else {
		MessageBox("你已经注册，请继续使用") ;
	}
	
}

void CSnapscreenDlg::OnButtonTimersnap() 
{
	
}


void CSnapscreenDlg::OnButtonWholescreen() 
{
	// TODO: Add your control notification handler code here
	char szCmd[MAX_PATH]={0} ;
	sprintf(szCmd , "CatchScreen.exe %d 1" , this->m_pic_is_edit) ;
	ShowWindow(SW_HIDE) ;
	StartupChildProcess(szCmd ,	1) ;
	ShowWindow(SW_SHOW) ;
}
