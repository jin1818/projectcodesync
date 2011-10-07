// wallpaperDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "wallpaper.h"
#include "wallpaperDlg.h"


#include "Shlobj.h" 
#include ".\wallpaperdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CwallpaperDlg 对话框



CwallpaperDlg::CwallpaperDlg(CWnd* pParent /*=NULL*/)
: CDialog(CwallpaperDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CwallpaperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CwallpaperDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CwallpaperDlg 消息处理程序


BOOL CwallpaperDlg::SetWallPaper(CString strPath)
{
	HRESULT hr;
	IActiveDesktop* pIAD;

	hr = CoCreateInstance( CLSID_ActiveDesktop, NULL, CLSCTX_INPROC_SERVER,
		IID_IActiveDesktop, (void**)&pIAD);
	if ( !SUCCEEDED(hr) )
		return FALSE;

	// 设置墙纸前先打开活动桌面开关
	COMPONENTSOPT co = {0};
	co.dwSize = sizeof(COMPONENTSOPT);
	co.fEnableComponents = TRUE;
	co.fActiveDesktop = TRUE;
	hr = pIAD->SetDesktopItemOptions(&co, 0);
	if ( !SUCCEEDED(hr) ) 
		return FALSE;

	//做以下宽字符的转换是因为SetWallpaper的参数是用的LPCWSTR
	WCHAR wszPath[MAX_PATH];
	LPTSTR lpStr = strPath.GetBuffer(strPath.GetLength());
	MultiByteToWideChar(CP_ACP, 0, lpStr, -1, wszPath, MAX_PATH);
	strPath.ReleaseBuffer();

	// 设置墙纸
	hr = pIAD->SetWallpaper(wszPath, 0);
	if ( !SUCCEEDED(hr) )
		return FALSE;

	// 设置墙纸风格
	WALLPAPEROPT wp = {0};
	wp.dwSize = sizeof(WALLPAPEROPT);
	wp.dwStyle |= WPSTYLE_CENTER;
	hr = pIAD->SetWallpaperOptions(&wp, 0);
	if ( !SUCCEEDED(hr) )
		return FALSE;

	// 应用改变
	hr = pIAD->ApplyChanges(AD_APPLY_ALL);
	if ( !SUCCEEDED(hr) )
		return FALSE;

	// 最后释放接口，不要忘了
	pIAD->Release(); 
	return TRUE;      
}

BOOL CwallpaperDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将\“关于...\”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	GetFilePath("I:\\吴宇航\\吴宇航相册\\图片\\风景壁纸\\") ;
	SetTimer(1 , 10000 , NULL) ;

	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void CwallpaperDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CwallpaperDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CwallpaperDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CwallpaperDlg::OnTimer(UINT nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s = picPathList.RemoveHead() ;
	SetWallPaper(s) ;
	picPathList.AddTail(s) ;
	CDialog::OnTimer(nIDEvent);
}

void CwallpaperDlg::GetFilePath(CString szPath) 
{
	 WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(szPath + "\\*.*", &fd);
	if(hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			picPathList.AddTail(szPath + "\\" + CString(fd.cFileName));
		}
		while(::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
}
