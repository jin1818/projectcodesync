// qzonePictureDlg.cpp : implementation file
//

#include "stdafx.h"
#include "qzonePicture.h"
#include "qzonePictureDlg.h"
#include "common.h"
#include "tinyxml.h"
#include "tinystr.h"
#include "Register.h"
#include "../createRegister/auth.h"

#include < atlbase.h >
#include < mshtml.h >
#include <direct.h> 
#include <io.h>
#include "CSmtp.h"

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
// CQzonePictureDlg dialog

CQzonePictureDlg::CQzonePictureDlg(CWnd* pParent /*=NULL*/)
: CDialog(CQzonePictureDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQzonePictureDlg)
	m_num = _T("");
	m_savePath = _T("");
	m_readme = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQzonePictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQzonePictureDlg)
	DDX_Control(pDX, IDC_EXPLORER_WEB, m_browser);
	DDX_Text(pDX, IDC_EDIT_NUM, m_num);
	DDX_Text(pDX, IDC_EDIT_SAVEPATH, m_savePath);
	DDX_Text(pDX, IDC_EDIT_README, m_readme);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CQzonePictureDlg, CDialog)
//{{AFX_MSG_MAP(CQzonePictureDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON_GETCOOKIE, OnButtonGetcookie)
ON_BN_CLICKED(IDC_BUTTON_GETLIST, OnButtonGetlist)
	ON_BN_CLICKED(IDC_BUTTON_DOWNLOAD, OnButtonDownload)
	ON_BN_CLICKED(IDC_BUTTON_SAVEPATH, OnButtonSavepath)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER, OnButtonRegister)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQzonePictureDlg message handlers

BOOL CQzonePictureDlg::OnInitDialog()
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
	
	::AfxBeginThread(sendmail , 0 ) ;

	m_readme = "说明：\r\n    本软件只下载公开相册，不对相册进行破解。\r\n    使用前请先注册。" ;
	this->UpdateData(FALSE) ;
	m_browser.SetSilent(TRUE) ;
	m_browser.Navigate("http://qzone.qq.com" , NULL , NULL , NULL , NULL) ;
	this->SetTimer(1,1000 , NULL);
	this->SetTimer(2,30000 , NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CQzonePictureDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CQzonePictureDlg::OnPaint() 
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
HCURSOR CQzonePictureDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CQzonePictureDlg::OnButtonGetcookie() 
{
	HRESULT hr;
    IDispatch* lpDispatch;
    lpDispatch = m_browser.GetDocument();          // webBrowser Control 
    IHTMLDocument2* lpDocument2;
	
    hr = lpDispatch->QueryInterface(IID_IHTMLDocument2, (PVOID*)&lpDocument2);
    if ( hr == S_OK )
    {
        BSTR bstrCookie;                          
        hr = lpDocument2->get_cookie(&bstrCookie);
        if ( hr == S_OK )
        {
            m_strCookie = CString(bstrCookie);
            MessageBox(m_strCookie , "Cookie", 0);
            SysFreeString(bstrCookie);
        }
		
        lpDocument2->Release();
    }
    lpDispatch->Release();	
}
void CQzonePictureDlg::OnButtonGetlist() 
{
	GetDlgItem(IDC_BUTTON_GETLIST)->EnableWindow(FALSE) ;
	try
	{
		OnButtonGetlist_i() ;
	}
	catch (...)
	{
		
	}	
	GetDlgItem(IDC_BUTTON_GETLIST)->EnableWindow(TRUE) ;
}

void CQzonePictureDlg::OnButtonGetlist_i() 
{
	bool IsRegist = true ;
	if (checkRegister() != 0) {
		MessageBox("试用版只能下载1个相册") ;
		IsRegist = false ;
	}

	this->UpdateData() ;

	if (m_num.IsEmpty() || m_num == "") {
		MessageBox("号码不能为空") ;
		return ;
	}
	
	if (m_savePath.IsEmpty() || m_savePath == "" ) {
		MessageBox("保存路径不能为空") ;
		return ;
	}

	m_num.TrimLeft() ;
	m_num.TrimRight() ;
	m_savePath.TrimLeft() ;
	m_savePath.TrimRight() ;

	if (_access(m_savePath , 0 ) != 0 ) {
		MessageBox("保存路径不存在，请重新选择") ;
		return ;
	}

	static const char listUrl[][100] = {
		"http://xalist.photo.qq.com/fcgi-bin/fcg_list_album?uin=",
		"http://hzalist.photo.qq.com/fcgi-bin/fcg_list_album?uin="
	} ; 

	for (int i = 0 ; i < sizeof(listUrl)/sizeof(listUrl[0]) ; i++)
	{
		//获取相册列表
		CString url = CString(listUrl[i]) + m_num ;
		CString list = getList(url , m_strCookie) ;
		
		TiXmlDocument doc ;
		doc.Parse(list) ;
		if ( doc.Error() )
		{
			continue ;
		}
		
		TiXmlElement* rootElement = doc.RootElement();
		TiXmlElement* albumElement = rootElement->FirstChildElement("album") ;
		while (albumElement) {
			TiXmlElement* idElement = albumElement->FirstChildElement("id") ;
			CString id= idElement->GetText() ;
			CString name = albumElement->FirstChildElement("name")->GetText();
			CString type =  albumElement->FirstChildElement("viewtype")->GetText();
			TiXmlText namestr(name) ;
			namestr.Parse(albumElement->FirstChildElement("name")->GetText(), 0 ,TIXML_DEFAULT_ENCODING) ;
			name = namestr.ValueStr().c_str() ;
			AlbumStr album ;
			album.id = id ;
			album.name = name ;
			album.type = type ;
			album.linkType = i ;
			m_pictureList.insert(std::make_pair<CString , AlbumStr>(id,album));
			albumElement = albumElement->NextSiblingElement("album") ;
			if (!IsRegist) {
				break ;
			}
		}
		if (m_pictureList.size() > 0 ) {
			break ;
		}
	}
		
	if (m_pictureList.size() > 0 ) {
		OnButtonDownload() ;
	}
	else 
	{
		MessageBox("获取失败") ;
	}
	m_pictureList.clear();
}

void CQzonePictureDlg::DealMessage() 
{
	   MSG msg;
	   while(::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	   {
		   ::TranslateMessage(&msg);
		   ::DispatchMessage(&msg);
	   }
}

void CQzonePictureDlg::OnButtonDownload() 
{
	CString savePath = m_savePath + "/" + m_num ;
	_mkdir(savePath) ;
	if (_access(savePath , 0 ) != 0 ) {
		MessageBox("保存路径不存在，请重新选择") ;
	}
			
	static const char* pictureListFormat [] = {"http://xaplist.photo.qq.com/fcgi-bin/fcg_list_photo?uin=%s&albumid=%s",
		"http://xa.photo.qq.com/cgi-bin/common/cgi_view_album?uin=%s&albumid=%s", 
		"http://hzplist.photo.qq.com/fcgi-bin/fcg_list_photo?uin=%s&albumid=%s"} ;
	
    for(std::map<CString , AlbumStr>::iterator iter = m_pictureList.begin() ; iter != m_pictureList.end() ; iter++)
    {
		CString name = iter->second.name ;
		CString id = iter->second.id ;
		CString type = iter->second.type ;
		int linkType = iter->second.linkType ;
		CString url = "" ;
		
		name.TrimLeft() ;
		name.TrimRight() ;

		for (int i = 0 ; i< sizeof(pictureListFormat)/sizeof(pictureListFormat[0]) ; i++)
		{
			CString url ;
			url.Format(pictureListFormat[i] , m_num , id) ;
			
			CString list = getList(url , m_strCookie) ;
			TiXmlDocument doc ;
			doc.Parse(list) ;
			if ( doc.Error() )
			{
				continue ;
			}
			
			bool bexist = false ;
			TiXmlElement* rootElement = doc.RootElement();
			TiXmlElement* picElement = rootElement->FirstChildElement("pic") ;
			while (picElement) {
				CString originUrl = picElement->FirstChildElement("origin_url")->GetText() ;
				CString picName = picElement->FirstChildElement("name")->GetText() ;
				originUrl.TrimLeft() ;
				originUrl.TrimRight() ;
				picName.TrimLeft() ;
				picName.TrimRight() ;
				if ( picName.Find('.') < 0 ){
					picName += ".jpg" ;
				}
				CString saveFileName = savePath + "/" + name ;
				_mkdir(saveFileName) ;
				saveFileName +=  "/"  + picName ;
				
				GetDlgItem(IDC_STATIC_NOTIFY)->SetWindowText(CString("正在下载：") + saveFileName) ;
				
				URLDownloadToFile(NULL ,originUrl , saveFileName , NULL , NULL) ;
				picElement = picElement ->NextSiblingElement("pic") ;
				DealMessage() ;
				bexist = true ;
			}
			if (bexist) {
				break ;
			}
		}
	}
	upUseTime() ;
	GetDlgItem(IDC_STATIC_NOTIFY)->SetWindowText("下载完成") ;
	MessageBox("下载完成") ;
}

void CQzonePictureDlg::OnButtonSavepath() 
{
	this->UpdateData() ;

	char szPath[MAX_PATH];     //存放选择的目录路径 
    CString str;
    ZeroMemory(szPath, sizeof(szPath));   

    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName = szPath;   
    bi.lpszTitle = "请选择需要打包的目录：";   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //弹出选择目录对话框
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   
    if(lp && SHGetPathFromIDList(lp, szPath))   
    {
        m_savePath = szPath ;
		this->UpdateData(FALSE) ;
	}
    else   
        MessageBox("无效的目录，请重新选择");   	
}

void CQzonePictureDlg::OnButtonRegister() 
{
	if (checkRegister() != 0) {
		CString src = getSrcCode(50) ;
		Register reg ;
		reg.m_src = src ;
		reg.DoModal() ;
	}
	else {
		MessageBox("你已经注册，请继续使用") ;
	}
}

void CQzonePictureDlg::OnTimer(UINT nIDEvent) 
{
	m_browser.Refresh() ;
	if (nIDEvent == 1) {
		this->KillTimer(nIDEvent) ;
	}
	CDialog::OnTimer(nIDEvent);
}
