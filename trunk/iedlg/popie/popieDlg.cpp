// popieDlg.cpp : implementation file
//

#include "stdafx.h"
#include "popie.h"
#include "popieDlg.h"



#define ID_TIMER_CHANGE_PICTURE 1
#define CONFIG_LOCAL_PAHT "IMG_Local_Path_%d"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopieDlg dialog

CPopieDlg::CPopieDlg(CWnd* pParent /*=NULL*/)
: CDialog(CPopieDlg::IDD, pParent)
,m_iChangeInterval(1)
,pMsgWindow(NULL)
{
	//{{AFX_DATA_INIT(CPopieDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_cmdLine = AfxGetApp()->m_lpCmdLine ;
}

void CPopieDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPopieDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPopieDlg, CDialog)
//{{AFX_MSG_MAP(CPopieDlg)
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_WM_TIMER()
ON_WM_CREATE()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopieDlg message handlers

BOOL CPopieDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    ::SetWindowLong(GetSafeHwnd(), GWL_EXSTYLE, WS_EX_TOOLWINDOW); 
	
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	

	int iImgCount = GetPrivateProfileInt("PIC_CONFIG" , "IMGCOUNT" , 0 , m_cmdLine) ;

	char szLocalFile[MAX_PATH] ;

	char configKey[MAX_PATH] ;
	
	for(int i = 1 ; i <= iImgCount ; i++)
	{
		memset(szLocalFile , 0 , sizeof(szLocalFile)) ;
		memset(configKey , 0 , sizeof(configKey)) ;
		sprintf(configKey , CONFIG_LOCAL_PAHT , i) ;
		GetPrivateProfileString("PIC_CONFIG" , configKey , NULL , szLocalFile , sizeof(szLocalFile) , m_cmdLine) ;
		this ->_piclist.AddTail(szLocalFile) ;
	}
	
	
	
	this -> m_iChangeInterval = GetPrivateProfileInt("PIC_CONFIG" , "IMG_CHANGE_INTERVAL" , 1 , m_cmdLine) ;



	SetTimer(ID_TIMER_CHANGE_PICTURE , 5 * 1000  ,NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPopieDlg::OnPaint() 
{
	SetWindowPos(NULL,0,0,0,0,SWP_NOZORDER|SWP_NOMOVE);
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = 0;//(rect.Width() - cxIcon + 1) / 2;
		int y = 0;//(rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
		
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CPopieDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


BOOL CPopieDlg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::Create(IDD, pParentWnd);
}

BOOL CPopieDlg::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (CDialog::PreCreateWindow(cs)) {
		cs.style =WS_POPUP;//使主窗口不可见；
		cs.dwExStyle |= WS_EX_TOOLWINDOW;
		return TRUE;
	}
	return FALSE;
}

int CPopieDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetWindowLong(m_hWnd, GWL_EXSTYLE, WS_EX_TOOLWINDOW);//隐藏任务栏上条
	return 0;
}

void
CPopieDlg::OnTimer(UINT nIDEvent)
{
	
	switch(nIDEvent)
	{
	case ID_TIMER_CHANGE_PICTURE:
		{
			if ( this ->_piclist.GetCount() <= 0 )
			{
				return ;
			}


			CString picPath = this ->_piclist.RemoveHead() ;
			this ->_piclist.AddTail(picPath) ;

			try
			{
				if ( NULL == pMsgWindow )
				{
					pMsgWindow = new CMsgWnd ;
					CMsgWnd& msgWindow=*pMsgWindow;
					msgWindow.CreateMsgWindow( 190 ,260 ,20 ,"DestTopPic", picPath );
					msgWindow.ShowWindow(SW_SHOW);
					msgWindow.UpdateWindow();
				}
				else
				{
					pMsgWindow->SetWindowUrl(picPath) ;
				}
			}
			catch(...)
			{

			}

			KillTimer(ID_TIMER_CHANGE_PICTURE) ;
			SetTimer(ID_TIMER_CHANGE_PICTURE , this->m_iChangeInterval * 1000  ,NULL);
		}
		break ;
	default:
		break ;
	}
	
	CDialog::OnTimer(nIDEvent) ;
}

