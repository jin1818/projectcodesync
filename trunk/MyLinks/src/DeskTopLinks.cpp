// DeskTopLinks.cpp : implementation file
//

#include "stdafx.h"
#include "risingui.h"
#include "DeskTopLinks.h"
#include <direct.h>

BOOL fnCreateLink (CString src , CString dst ) ;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeskTopLinks dialog


CDeskTopLinks::CDeskTopLinks(CWnd* pParent /*=NULL*/)
	: CSkinDialog(CDeskTopLinks::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeskTopLinks)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDeskTopLinks::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeskTopLinks)
	DDX_Control(pDX, IDC_Links_Add, m_add);
	DDX_Control(pDX, IDC_Links_Import, m_import);
	DDX_Control(pDX, IDC_LinksList, m_show);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeskTopLinks, CDialog)
	//{{AFX_MSG_MAP(CDeskTopLinks)
	ON_BN_CLICKED(IDC_Links_Import, OnLinksImport)
	ON_NOTIFY(NM_DBLCLK, IDC_LinksList, OnDblclkLinksList)
	ON_NOTIFY(NM_RCLICK, IDC_LinksList, OnRclickLinksList)
	ON_COMMAND(ID_RUN, OnRun)
	ON_COMMAND(ID_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_Links_Add, OnLinksAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeskTopLinks message handlers

void CDeskTopLinks::OnLinksImport() 
{
	// TODO: Add your control notification handler code here
	char szPath[MAX_PATH] = {'\0'} ;	
	SHGetSpecialFolderPath(0,szPath,CSIDL_DESKTOPDIRECTORY,0);
	if (strlen(szPath) <=0 ) 
	{
		MessageBox("获取桌面路径失败") ;
		return ;
	}
	
	WIN32_FIND_DATA fd;
	CString findPath = szPath ;
	
    HANDLE hFind = ::FindFirstFile(findPath + "\\*.*" , &fd);
    if(hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
			if (strcmp(fd.cFileName,".") ==0 || strcmp(fd.cFileName,"..")==0) {
				continue ;
			}
			CString m_fileName = szPath ;
			m_fileName += "\\" ;
			m_fileName += fd.cFileName ;
			SHFILEINFO   shFileInfo; 
			SHGetFileInfo(m_fileName,0,&shFileInfo,sizeof(SHFILEINFO), 
				SHGFI_DISPLAYNAME|SHGFI_ICON|SHGFI_SMALLICON|SHGFI_TYPENAME|SHGFI_ATTRIBUTES);
			if(shFileInfo.dwAttributes&SFGAO_LINK) 
			{
				makeLink(m_fileName,fd.cFileName) ;
			}
        }
        while(::FindNextFile(hFind, &fd));
        ::FindClose(hFind);
    }
	LoadLinks() ;
}

void CDeskTopLinks::makeLink(CString fileName, CString shortName) 
{
	CString dstFileName ;
	dstFileName = getLinksDir() + shortName ;
	CopyFile(fileName , dstFileName , FALSE) ;
}


CString CDeskTopLinks::getLinksDir() 
{
	CString dstFileName ;
	CString strAppPath; 
	::GetModuleFileName(NULL,   strAppPath.GetBuffer(MAX_PATH),   MAX_PATH); 
	strAppPath.ReleaseBuffer(); 
	int   nPos   =   strAppPath.ReverseFind('\\'); 
	dstFileName = strAppPath.Left(nPos   +   1) + "links\\";
	mkdir(dstFileName) ;
	return dstFileName ;
}

void CDeskTopLinks::LoadLinks() 
{
	m_show.DeleteAllItems() ;
	WIN32_FIND_DATA fd;
	CString szPath = getLinksDir() ;
    HANDLE hFind = ::FindFirstFile(szPath + "*.*" , &fd);
    if(hFind != INVALID_HANDLE_VALUE)
    { 
		int i =0 ;
        do
        {
			if (strcmp(fd.cFileName,".") ==0 || strcmp(fd.cFileName,"..")==0) {
				continue ;
			}
			CString m_fileName = szPath ;
			m_fileName += fd.cFileName ;
			SHFILEINFO   shFileInfo; 
			SHGetFileInfo(m_fileName,0,&shFileInfo,sizeof(SHFILEINFO), 
				SHGFI_DISPLAYNAME|SHGFI_ICON|SHGFI_SMALLICON|SHGFI_TYPENAME|SHGFI_ATTRIBUTES);
			if(shFileInfo.dwAttributes&SFGAO_LINK) 
			{
				m_ImageList.Add(shFileInfo.hIcon);
				m_show.InsertItem(i,fd.cFileName,m_ImageList.GetImageCount() - 1);
				i++ ;
			}
			
        }
        while(::FindNextFile(hFind, &fd));
        ::FindClose(hFind);
    }
}

void CDeskTopLinks::MoveWindow(LPCRECT lpRect, BOOL bRepaint /* = TRUE */) {
	RECT re;
	re.top = lpRect->top;
	re.left = lpRect->left ;
	re.right = lpRect->right ;
	re.bottom= lpRect->bottom ;

	CSkinDialog::MoveWindow(lpRect , bRepaint) ;
	
//	m_show.MoveWindow(&re , bRepaint) ;
}

BOOL CDeskTopLinks::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ImageList.Create(20, 20, ILC_COLORDDB|ILC_MASK, 20, 1); 
	m_show.SetImageList(&m_ImageList,LVSIL_NORMAL);
	LoadLinks() ;
	LoadSkin("./skin/skin1.xml","DlgDeskTopLink") ;
	m_import.LoadSkin("./skin/skin1.xml","BtnImport") ;
	m_add.LoadSkin("./skin/skin1.xml","BtnImport") ;
	AddAnchor(IDC_Links_Import, ANCHOR_BOTTOMLEFT|ANCHOR_BOTTOMLEFT);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDeskTopLinks::OnRun() 
{
	POSITION pos = m_show.GetFirstSelectedItemPosition();
	int nIndex = m_show.GetNextSelectedItem(pos); // 得到项目索引
	if (nIndex<0)
	{
		MessageBox("请先选择运行目标","") ;
		return ;
	}
	CString fineName = m_show.GetItemText(nIndex,0);
	CString fullName = getLinksDir() + fineName ;
	CString run ;
	run.Format("cmd /c \"%s\" " , fullName) ;
	WinExec(run ,SW_HIDE); 		
}

void CDeskTopLinks::OnDblclkLinksList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	OnRun() ;
	*pResult = 0;
}

void CDeskTopLinks::OnRclickLinksList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMenu menu;
	
	//载入事先定义的选单
	
	menu.LoadMenu(IDR_RUNMENU);
	
	CMenu*pMenu=menu.GetSubMenu(0);
	
	CPoint pos;
	
	GetCursorPos(&pos);
	
	//加入SetForegroundWindow的目的为使用户点菜单之外时菜单可以消失
	
	::SetForegroundWindow(m_hWnd);
	
	pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,pos.x,pos.y,AfxGetMainWnd());
		
	*pResult = 0;
}


void CDeskTopLinks::OnDelete() 
{
	POSITION pos = m_show.GetFirstSelectedItemPosition();
	int nIndex = m_show.GetNextSelectedItem(pos); // 得到项目索引
	if (nIndex<0)
	{
		MessageBox("请先选择运行目标","") ;
		return ;
	}
	CString fineName = m_show.GetItemText(nIndex,0);
	CString fullName = getLinksDir() + fineName ;
	remove(fullName) ;
	LoadLinks() ;
}

void CDeskTopLinks::OnLinksAdd() 
{
	char Filter[]="所有文件(*.*)|*.*||";
    CFileDialog dlgOpen(TRUE,0,0,OFN_HIDEREADONLY|OFN_FILEMUSTEXIST|OFN_NODEREFERENCELINKS,(LPCTSTR)Filter,NULL);
    if(dlgOpen.DoModal() !=IDOK)
    {
		return ;
    }
	CString pathName = dlgOpen.GetPathName() ;
	SHFILEINFO   shFileInfo; 
	SHGetFileInfo(pathName,0,&shFileInfo,sizeof(SHFILEINFO), 
		SHGFI_DISPLAYNAME|SHGFI_ICON|SHGFI_SMALLICON|SHGFI_TYPENAME|SHGFI_ATTRIBUTES);
	if(shFileInfo.dwAttributes&SFGAO_LINK) 
	{
		makeLink(pathName,dlgOpen.GetFileName()) ;
	}
	else {
		fnCreateLink(pathName , getLinksDir() + dlgOpen.GetFileName() + ".lnk" ) ;
	}
	LoadLinks() ;	
}

BOOL fnCreateLink (CString src , CString dst )
{
	
    LPCSTR pszPath,pszLink;
	
    pszPath=src ;//目标程序名
	
    pszLink=dst ;//快捷方式名
	
    HRESULT hres=NULL;
	
    IShellLink * psl = NULL ;
	
    IPersistFile* ppf = NULL ;
	
    WCHAR   wsz[MAX_PATH]; //   buffer   for   Unicode   string 
	
	CoInitialize(NULL) ;

    hres = CoCreateInstance( CLSID_ShellLink, NULL , CLSCTX_ALL, IID_IShellLink,(void **)&psl) ;
	
    if(FAILED(hres))        return FALSE ;
    
    psl->SetPath(pszPath) ;//设置路径
	
    psl->SetHotkey(MAKEWORD('A',HOTKEYF_CONTROL)) ;  //设置快捷键、热键
	
    hres = psl -> QueryInterface( IID_IPersistFile,    (void**)&ppf);//获取IPersistFile接口
	
    if(FAILED(hres))        return FALSE ;
	
    MultiByteToWideChar(CP_ACP,0,pszLink,-1,wsz,MAX_PATH);
	
    hres = ppf -> Save(wsz, STGM_READWRITE) ;//保存快捷方式
	
    ppf->Release();//释放IPersistFile和IShellLink接口
	
	psl->Release();
	
	// 通知SHELL变化
	//SHChangeNotify( ....) ;//从略，具体可以参考该函数定义，一般创建后通知本目录和父目录即可。
	
	return TRUE;
}


