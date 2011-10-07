// groupbuyV2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "groupbuyV2.h"
#include "groupbuyV2Dlg.h"
#include <httpdownload.h>
#include <fstream>
#include <sysrun.h>

#include <string>
using namespace std ;
NOTIFYICONDATA  g_nd;

CString homepage = "http://www.cppentry.com/gb/gbindexV2.html" ;
CString chongzhiPage = "http://www.cppentry.com/gb/chongzhi.html" ;
CString shiyijianPage= "http://www.cppentry.com/gb/shiyijian.html" ;
CString caipiaoPage = "http://www.cppentry.com/gb/caipiao.html" ;
CString xianhuaPage = "http://www.cppentry.com/gb/xianhua.html" ;
CString lvyouPage = "http://www.cppentry.com/gb/lvyou.html" ;
CString tushuPage = "http://www.cppentry.com/gb/tushu.html" ;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CGroupbuyV2Dlg dialog

CGroupbuyV2Dlg::CGroupbuyV2Dlg(CWnd* pParent /*=NULL*/)
: CDialog(CGroupbuyV2Dlg::IDD, pParent)
, m_flags(SW_SHOWDEFAULT)

{
	//{{AFX_DATA_INIT(CGroupbuyV2Dlg)
	m_autoRun = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGroupbuyV2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGroupbuyV2Dlg)
	DDX_Control(pDX, IDC_LOAD_PROGRESS, m_loadProcess);
	DDX_Control(pDX, IDC_LIST, m_websites);
	DDX_Control(pDX, IDC_EXPLORER, m_webbrowser);
	DDX_Check(pDX, IDC_CHECK_AUTORUN, m_autoRun);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGroupbuyV2Dlg, CDialog)
//{{AFX_MSG_MAP(CGroupbuyV2Dlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
ON_BN_CLICKED(IDC_BUTTON_BACK, OnButtonBack)
ON_BN_CLICKED(IDC_BUTTON_FORWARD, OnButtonForward)
ON_BN_CLICKED(IDC_BUTTON_HOMEPAGE, OnButtonHomepage)
ON_BN_CLICKED(IDC_BUTTON_RELOAD, OnButtonReload)
ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
ON_WM_SIZE()
ON_BN_CLICKED(IDC_CHECK_AUTORUN, OnCheckAutorun)
ON_BN_CLICKED(IDC_BUTTON_HIDE, OnButtonHide)
ON_WM_DESTROY()
ON_MESSAGE(MYWM_NOTIFYICON,OnNOTIFYICON)
ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
ON_BN_CLICKED(IDC_ABOUT, OnAbout)
ON_BN_CLICKED(IDC_BUTTON_chongzhi, OnBUTTONchongzhi)
ON_BN_CLICKED(IDC_BUTTON_shiyijian, OnBUTTONshiyijian)
ON_COMMAND(ID_EXIT_EX, OnExitEx)
ON_BN_CLICKED(IDC_BUTTON_CAIPIAO, OnButtonCaipiao)
ON_BN_CLICKED(IDC_BUTTON_XIANHUA, OnButtonXianhua)
ON_BN_CLICKED(IDC_BUTTON_LVYOU, OnButtonLvyou)
ON_BN_CLICKED(IDC_BUTTON_TUSHU, OnButtonTushu)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGroupbuyV2Dlg message handlers

void CGroupbuyV2Dlg::AddSystrayIcon()
{
	// 将图标放入系统托盘
	g_nd.cbSize = sizeof (NOTIFYICONDATA);
	g_nd.hWnd = m_hWnd;
	g_nd.uID = IDR_MAINFRAME;
	g_nd.uFlags = NIF_ICON|NIF_MESSAGE|NIF_TIP;
	g_nd.uCallbackMessage= MYWM_NOTIFYICON;
	g_nd.hIcon = m_hIcon;
	//strcpy(g_nd.szTip, "知天下娱乐中心[V1.1]");
	Shell_NotifyIcon(NIM_ADD, &g_nd);
}

void CGroupbuyV2Dlg::DelSystrayIcon()
{
	Shell_NotifyIcon(NIM_DELETE, &g_nd);
}

void CGroupbuyV2Dlg::OnNOTIFYICON(WPARAM wParam, LPARAM lParam) 
{
	if(lParam==WM_LBUTTONDBLCLK)
	{
		if (m_flags == SW_SHOWDEFAULT)
		{
			m_flags = SW_HIDE ;
		}
		else 
		{
			m_flags = SW_SHOWDEFAULT ;
		}
		AfxGetApp()->m_pMainWnd->ShowWindow(m_flags);
//		if (SW_SHOW == m_flags )
//		{
//			AfxGetApp()->m_pMainWnd->ShowWindow(SW_SHOWDEFAULT);
//		}
	}
	else if(lParam==WM_RBUTTONDOWN)		
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



BOOL CGroupbuyV2Dlg::OnInitDialog()
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
	getWebSites() ;
	m_webbrowser.SetSilent(TRUE) ;
	m_webbrowser.Navigate(homepage,NULL,NULL,NULL,NULL) ;
	CRect m_rect ;
	GetClientRect(&m_rect) ;
	Old.x=m_rect.right - m_rect.left;
	Old.y=m_rect.bottom - m_rect.top;
	AddSystrayIcon();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGroupbuyV2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGroupbuyV2Dlg::OnPaint() 
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
HCURSOR CGroupbuyV2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGroupbuyV2Dlg::getWebSites()
{
	//get websites
	string remoteWebSites = "http://www.cppentry.com/gb/websites.txt" ;
	string locateWebSites = "newWebSites" ;
	const char * websites = "websites" ;
	if ( downloadFile(remoteWebSites ,locateWebSites ) )
	{
		websites = locateWebSites.c_str() ;
	}
	
	ifstream is(websites) ;
	if ( !is.is_open())
	{
		exit(0) ;
	}
	char website[8096]={0} ;
	int i = 0 ;
	m_websites.InsertColumn(0 , "团购",LVCFMT_CENTER,150) ;
	while(is.getline(website , sizeof(website) -1 ))
	{
		char* p = strchr(website , '=') ;
		if ( NULL == p ) 
		{
			continue ;
		}
		*p= NULL ;
		p++ ;
		this->m_WetSites.insert(std::make_pair<string , string>(website ,p)) ;
		CString itemname = website ;
		m_websites.InsertItem(i++ , itemname) ;
		memset(website , 0 , sizeof(website)) ;
	}
}

void CGroupbuyV2Dlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	string str = m_websites.GetItemText(m_websites.GetNextItem(-1,LVNI_SELECTED), 0 ) ;
	
	if (str.empty())
		return  ;
	
	map<string , string>::iterator iter = this->m_WetSites.find(str)  ;
	if ( iter == this->m_WetSites.end() )
		return  ;
	
	m_webbrowser.Navigate(iter->second.c_str(),NULL,NULL,NULL,NULL) ;	
	*pResult = 0;
}

void CGroupbuyV2Dlg::OnButtonBack() 
{
	this->m_webbrowser.GoBack() ;
}

void CGroupbuyV2Dlg::OnButtonForward() 
{
	this->m_webbrowser.GoForward() ;
	
}

void CGroupbuyV2Dlg::OnButtonHomepage() 
{
	this->m_webbrowser.Navigate(homepage,NULL,NULL,NULL,NULL) ;
}

void CGroupbuyV2Dlg::OnButtonReload() 
{
	this->m_webbrowser.Refresh() ;
	
}

void CGroupbuyV2Dlg::OnButtonSearch() 
{
	
}

void CGroupbuyV2Dlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	if ( SIZE_MINIMIZED == nType ) 
	{
		OnButtonHide() ;
	}
	else 
	{
		float fsp[2];
		POINT Newp; //获取现在对话框的大小
		CRect recta;  
		GetClientRect(&recta);     //取客户区大小
		Newp.x=recta.right-recta.left;
		Newp.y=recta.bottom-recta.top;
		fsp[0]=(float)Newp.x/Old.x;
		fsp[1]=(float)Newp.y/Old.y;
		CRect Rect;
		int woc;
		CPoint OldTLPoint,TLPoint; //左上角
		CPoint OldBRPoint,BRPoint; //右下角
		HWND  hwndChild=::GetWindow(m_hWnd,GW_CHILD);  //列出所有控件
		while(hwndChild)  
		{  
			woc=::GetDlgCtrlID(hwndChild);//取得ID
			GetDlgItem(woc)->GetWindowRect(Rect);
			ScreenToClient(Rect);
			OldTLPoint = Rect.TopLeft();
			TLPoint.x = long(OldTLPoint.x*fsp[0]);
			TLPoint.y = long(OldTLPoint.y*fsp[1]);
			OldBRPoint = Rect.BottomRight();
			BRPoint.x = long(OldBRPoint.x *fsp[0]);
			BRPoint.y = long(OldBRPoint.y *fsp[1]);
			Rect.SetRect(TLPoint,BRPoint);
			GetDlgItem(woc)->MoveWindow(Rect,TRUE);
			hwndChild=::GetWindow(hwndChild, GW_HWNDNEXT);  
		}
		Old=Newp;
	}
}

void CGroupbuyV2Dlg::OnCheckAutorun() 
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

void CGroupbuyV2Dlg::OnButtonHide() 
{
	m_flags = SW_HIDE ;
	this->ShowWindow(m_flags) ;	
}

void CGroupbuyV2Dlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	DelSystrayIcon( );	
}

void CGroupbuyV2Dlg::OnButtonStop() 
{
	this->m_webbrowser.Stop() ;
}

void CGroupbuyV2Dlg::OnAbout() 
{
	CAboutDlg aboutDlg ;
	aboutDlg.DoModal() ;
}

void CGroupbuyV2Dlg::OnBUTTONchongzhi() 
{
	this->m_webbrowser.Navigate(chongzhiPage , NULL , NULL , NULL , NULL ) ;
	
}

void CGroupbuyV2Dlg::OnBUTTONshiyijian() 
{
	this->m_webbrowser.Navigate(shiyijianPage , NULL , NULL , NULL , NULL ) ;
	
}

void CGroupbuyV2Dlg::OnExitEx() 
{
	this->SendNotifyMessage(WM_CLOSE,NULL,NULL) ;
	
}

void CGroupbuyV2Dlg::OnButtonCaipiao() 
{
	this->m_webbrowser.Navigate(caipiaoPage, NULL , NULL , NULL , NULL ) ;
	
}

void CGroupbuyV2Dlg::OnButtonXianhua() 
{
	this->m_webbrowser.Navigate(xianhuaPage, NULL , NULL , NULL , NULL ) ;
}

void CGroupbuyV2Dlg::OnButtonLvyou() 
{
	this->m_webbrowser.Navigate(lvyouPage, NULL , NULL , NULL , NULL ) ;
}

void CGroupbuyV2Dlg::OnButtonTushu() 
{
	this->m_webbrowser.Navigate(tushuPage, NULL , NULL , NULL , NULL ) ;	
}

void CGroupbuyV2Dlg::resetProcess()
{
	this->m_loadProcess.SetPos(0) ;
	this->m_loadProcess.StepIt() ;
}


BEGIN_EVENTSINK_MAP(CGroupbuyV2Dlg, CDialog)
//{{AFX_EVENTSINK_MAP(CGroupbuyV2Dlg)
ON_EVENT(CGroupbuyV2Dlg, IDC_EXPLORER, 259 /* DocumentComplete */, OnDocumentCompleteExplorer, VTS_DISPATCH VTS_PVARIANT)
	ON_EVENT(CGroupbuyV2Dlg, IDC_EXPLORER, 250 /* BeforeNavigate2 */, OnBeforeNavigate2Explorer, VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PBOOL)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CGroupbuyV2Dlg::OnDocumentCompleteExplorer(LPDISPATCH pDisp, VARIANT FAR* URL) 
{
	this->m_loadProcess.SetPos((m_loadProcess.GetPos() + 5)%100) ;
	IUnknown* pUnk;   
	LPDISPATCH lpWBDisp;   	
	HRESULT hr;   
	pUnk = m_webbrowser.GetControlUnknown();  
	ASSERT(pUnk);   
	hr = pUnk->QueryInterface(IID_IDispatch, (void**)&lpWBDisp);   
	ASSERT(SUCCEEDED(hr));   
	if (pDisp == lpWBDisp )   
	{
		this->m_loadProcess.SetPos(100) ;
	}   
	lpWBDisp->Release();
}

void CGroupbuyV2Dlg::OnBeforeNavigate2Explorer(LPDISPATCH pDisp, VARIANT FAR* URL, VARIANT FAR* Flags, VARIANT FAR* TargetFrameName, VARIANT FAR* PostData, VARIANT FAR* Headers, BOOL FAR* Cancel) 
{
	//resetProcess() ;	
}
