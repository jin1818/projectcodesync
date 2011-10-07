// LinkMgrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LinkMgr.h"
#include "LinkMgrDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinkMgrDlg dialog

CLinkMgrDlg::CLinkMgrDlg(CWnd* pParent /*=NULL*/)
: CPropertyPage(CLinkMgrDlg::IDD)
{
	//{{AFX_DATA_INIT(CLinkMgrDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
}

void CLinkMgrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinkMgrDlg)
	DDX_Control(pDX, IDC_LIST, m_show);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLinkMgrDlg, CDialog)
//{{AFX_MSG_MAP(CLinkMgrDlg)
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_IMPORT, OnImport)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	ON_WM_DESTROY()
	ON_COMMAND(ID_RUN, OnRun)
	ON_NOTIFY(NM_RCLICK, IDC_LIST, OnRclickList)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinkMgrDlg message handlers

BOOL CLinkMgrDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	m_ImageList.Create(20, 20, ILC_COLORDDB|ILC_MASK, 20, 1); 
	m_show.SetImageList(&m_ImageList,LVSIL_NORMAL);
	LoadLinks() ;
	return TRUE;  // return TRUE  unless you set the focus to a control
}


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLinkMgrDlg::OnPaint() 
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
HCURSOR CLinkMgrDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLinkMgrDlg::OnFindFile() 
{
	char Filter[]="所有文件(*.*)|*.*||";
    CFileDialog dlgOpen(TRUE,0,0,OFN_HIDEREADONLY|OFN_FILEMUSTEXIST|OFN_NODEREFERENCELINKS,(LPCTSTR)Filter,NULL);
    if(dlgOpen.DoModal() !=IDOK)
    {
		return ;
    }
	CString m_fileName = dlgOpen.GetPathName() ;
	SHFILEINFO   shFileInfo; 
	SHGetFileInfo(m_fileName,0,&shFileInfo,sizeof(SHFILEINFO), 
		SHGFI_DISPLAYNAME|SHGFI_ICON|SHGFI_SMALLICON|SHGFI_TYPENAME|SHGFI_ATTRIBUTES);
	if(shFileInfo.dwAttributes&SFGAO_LINK) 
	{
		MessageBox("ok") ;
	}
}

void CLinkMgrDlg::OnImport() 
{
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


void CLinkMgrDlg::makeLink(CString fileName, CString shortName) 
{
	CString dstFileName ;
	dstFileName = getLinksDir() + shortName ;
	CopyFile(fileName , dstFileName , FALSE) ;
}

CString CLinkMgrDlg::getLinksDir() 
{
	CString dstFileName ;
	CString strAppPath; 
	::GetModuleFileName(NULL,   strAppPath.GetBuffer(MAX_PATH),   MAX_PATH); 
	strAppPath.ReleaseBuffer(); 
	int   nPos   =   strAppPath.ReverseFind('\\'); 
	dstFileName = strAppPath.Left(nPos   +   1) + "links\\";
	return dstFileName ;
}

void CLinkMgrDlg::LoadLinks() 
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

void CLinkMgrDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	OnRun() ;
	*pResult = 0;
}


void CLinkMgrDlg::OnRun() 
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

void CLinkMgrDlg::OnRclickList(NMHDR* pNMHDR, LRESULT* pResult) 
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
