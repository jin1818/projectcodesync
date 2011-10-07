// RisingUiDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RisingUi.h"
#include "RisingUiDlg.h"

#include "skin/ZvLib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CSkinDialog
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
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CSkinDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CSkinDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CSkinDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRisingUiDlg dialog

CRisingUiDlg::CRisingUiDlg(CWnd* pParent /*=NULL*/)
	: CSkinDialog(CRisingUiDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRisingUiDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRisingUiDlg::DoDataExchange(CDataExchange* pDX)
{
	CSkinDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRisingUiDlg)
	DDX_Control(pDX, IDC_TAB1, m_tabViews);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRisingUiDlg, CSkinDialog)
	//{{AFX_MSG_MAP(CRisingUiDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDM_EXIT, OnExit)
	ON_WM_SIZE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_COMMAND(IDM_ABOUT, OnAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRisingUiDlg message handlers

BOOL CRisingUiDlg::OnInitDialog()
{
	CSkinDialog::OnInitDialog();

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
	// ModifyStyle(0, WS_CLIPCHILDREN);
	SetCurrentDirectory(CZvLib::GetAppPath().c_str());
	
	int i=0;
	m_tabViews.InsertItem(i++, "信息中心");
	m_tabViews.InsertItem(i++, "快捷方式");
	m_tabViews.InsertItem(i++, "工具列表");
	m_tabViews.InsertItem(i++, "监控中心");

	LoadSkin("./skin/skin1.xml");
	m_tabViews.LoadSkin("./skin/skin1.xml");

	AddAnchor(IDC_TAB1,  ANCHOR_TOPLEFT|ANCHOR_TOPRIGHT);
	AddAnchor(IDC_RECT_CHILD,  ANCHOR_TOPLEFT|ANCHOR_BOTTOMRIGHT);

	m_dlgInfo.Create(CDlgInfo::IDD, this);
	m_dlgLink.Create(CDlgLink::IDD, this);
	m_vtPDlg.push_back(&m_dlgInfo);
	m_vtPDlg.push_back(&m_dlgLink);

	ShowChildDlg(0);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRisingUiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{

	}
	else
	{
		CSkinDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRisingUiDlg::OnPaint() 
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
		CSkinDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRisingUiDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRisingUiDlg::OnExit() 
{
	// TODO: Add your command handler code here
	SendMessage(WM_CLOSE);
}

void CRisingUiDlg::ShowChildDlg(int nIndex)
{
	if(m_nCurDlg>=0 && m_nCurDlg<m_vtPDlg.size())
	{
		m_vtPDlg[m_nCurDlg]->ShowWindow(SW_HIDE);
	}

	m_nCurDlg = nIndex;

	if(m_nCurDlg>=0 && m_nCurDlg<m_vtPDlg.size())
	{
		RECT rect;
		GetDlgItem(IDC_RECT_CHILD)->GetWindowRect(&rect);
		rect.top--;
		rect.right+=7;
		ScreenToClient(&rect);
		
		m_vtPDlg[m_nCurDlg]->MoveWindow(&rect,FALSE);
		m_vtPDlg[m_nCurDlg]->ShowWindow(SW_SHOW);
	}
}

void CRisingUiDlg::OnSize(UINT nType, int cx, int cy) 
{
	CSkinDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	ShowChildDlg(m_nCurDlg);
}

void CRisingUiDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	ShowChildDlg(m_tabViews.GetCurSel());

	*pResult = 0;
}

void CRisingUiDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}

BOOL CAboutDlg::OnInitDialog() 
{
	CSkinDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	LoadSkin("./skin/skin1.xml", "DialogAbout");

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
