// CatchScreenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CatchScreen.h"
#include "CatchScreenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

bool   SaveBitmapToFile(HBITMAP   hBitmap,   CString szfilename) ;
int StartupChildProcess(const char * szCmdLine,int nSync ) ;

/////////////////////////////////////////////////////////////////////////////
// CCatchScreenDlg dialog

CCatchScreenDlg::CCatchScreenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCatchScreenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCatchScreenDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
//*******************************************************************************
    //初始化像皮筋类
	m_rectTracker.m_nStyle=CRectTracker::resizeInside|CRectTracker::solidLine;  
	m_rectTracker.m_rect.SetRect(-1,-1,-1,-1);

    m_hCursor=AfxGetApp()->LoadCursor(IDC_CURSOR1);  
    
	
	m_bDraw=FALSE;
	m_bFirstDraw=FALSE;
	m_bQuit=FALSE;
	m_bShowMsg=FALSE;
    m_startPt=0;
    
	//获取屏幕分辩率
	m_xScreen = GetSystemMetrics(SM_CXSCREEN);
	m_yScreen = GetSystemMetrics(SM_CYSCREEN);

	//截取屏幕到位图中
	CRect rect(0, 0,m_xScreen,m_yScreen);
	m_pBitmap=CBitmap::FromHandle(CopyScreenToBitmap(&rect));
    
	//一定要初始化m_rgn，
    m_rgn.CreateRectRgn(0,0,50,50);
//*******************************************************************************

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCatchScreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCatchScreenDlg)
	DDX_Control(pDX, IDC_EDIT1, m_tipEdit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCatchScreenDlg, CDialog)
	//{{AFX_MSG_MAP(CCatchScreenDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCatchScreenDlg message handlers

BOOL CCatchScreenDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	if(__argc > 2) {
		if( atoi(__argv[2]) ){
			SnapWholeScreen() ;
		}
	}

//**************************************************************************
	//把对化框设置成全屏顶层窗口
	SetWindowPos(&wndTopMost,0,0,m_xScreen,m_yScreen,SWP_SHOWWINDOW);
    
	//移动操作提示窗口
	CRect rect;
	m_tipEdit.GetWindowRect(&rect);
    m_tipEdit.MoveWindow(10,10,rect.Width(),rect.Height());
    
	//显示操作提示窗口文字
	DrawTip();
	
	//捕获按键消息窗口,将对话框的句柄传递到CCatchScreenApp中
	((CCatchScreenApp *)AfxGetApp())->m_hwndDlg=m_hWnd;
//**************************************************************************

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here


	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCatchScreenDlg::OnPaint() 
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
//**************************************************************************
		CPaintDC dc(this);
         
		//显示截取矩形大小信息
		if(m_bShowMsg&&m_bFirstDraw)
		{
			CRect rect;
			m_rectTracker.GetTrueRect(&rect);
			DrawMessage(rect);
		}

		//画出像皮筋矩形
		if(m_bFirstDraw)
		{
			m_rectTracker.Draw(&dc);
		}
		//DrawTip();
//*************************************************************************
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCatchScreenDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCatchScreenDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CCatchScreenDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
//***************************************************************
	if(m_bFirstDraw)
	{
		m_bFirstDraw=FALSE;
		m_bDraw=FALSE;
		m_rectTracker.m_rect.SetRect(-1,-1,-1,-1);
		PaintWindow();
	}
	else
	{
		CDialog::OnCancel();
	}
//*******************************************************************
}

void CCatchScreenDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//**************************************************************************************
	   if(m_bDraw)
	   {
			m_rectTracker.m_rect.SetRect(m_startPt.x+1,m_startPt.y+1,point.x,point.y);
			m_bFirstDraw=TRUE;

			PaintWindow();
	   }
	   DrawTip();
//*****************************************************************************************
	CDialog::OnMouseMove(nFlags, point);
}

void CCatchScreenDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//*****************************************************************************************
	int nHitTest;
	nHitTest=m_rectTracker.HitTest(point);

	m_bShowMsg=TRUE;
	//PaintWindow();
	PaintWindow();

    //判断击中位置
	if(nHitTest<0)
	{
		if(!m_bFirstDraw)
		{
			m_startPt=point;
			m_bDraw=TRUE;
						
			PaintWindow();
		}
	}
	else
	{
		if(m_bFirstDraw)
		{
			m_rectTracker.Track(this,point,TRUE);
			SendMessage(WM_LBUTTONUP,NULL,NULL);
			PaintWindow();

		}
	}
//****************************************************************************************
	CDialog::OnLButtonDown(nFlags, point);
}

void CCatchScreenDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//****************************************************************************************

	m_bShowMsg=FALSE;
	m_bDraw=FALSE;

	PaintWindow();
//****************************************************************************************
	CDialog::OnLButtonUp(nFlags, point);
}

void CCatchScreenDlg::SnapWholeScreen()
{
	//截取屏幕到位图中
	CRect rect(0, 0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
	char szTempPath[MAX_PATH]={0} ;
	char filename[1024]={0} ;
	GetTempPath(sizeof(szTempPath), szTempPath) ;
	sprintf(filename, "%s/snapscreen.bmp" , szTempPath ) ;
	SaveBitmapToFile(CopyScreenToBitmap(rect,TRUE) , filename) ;
	
	if( atoi(__argv[1]) )
	{
		char szCmd[1024]={0} ;
		sprintf(szCmd,"mspaint.exe %s" , filename) ;
		WinExec(szCmd,1) ;
	}
	PostQuitMessage(0);
}

void CCatchScreenDlg::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int nHitTest;
	nHitTest=m_rectTracker.HitTest(point);
	
	if(nHitTest==8)
	{
		char szTempPath[MAX_PATH]={0} ;
		char filename[1024]={0} ;
       	GetTempPath(sizeof(szTempPath), szTempPath) ;
		sprintf(filename, "%s/snapscreen.bmp" , szTempPath ) ;
		SaveBitmapToFile(CopyScreenToBitmap(m_rectTracker.m_rect,TRUE) , filename) ;
		
		if( atoi(__argv[1]) )
		{
			char szCmd[1024]={0} ;
			sprintf(szCmd,"mspaint.exe %s" , filename) ;
			WinExec(szCmd,1) ;
		}
		PostQuitMessage(0);
	}
	CDialog::OnLButtonDblClk(nFlags, point);
}

void CCatchScreenDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//****************************************************************************************
	if(m_bFirstDraw)
	{
		//如果已经截取矩则清除截取矩形
		m_bFirstDraw=FALSE;
		m_rectTracker.m_rect.SetRect(-1,-1,-1,-1);
		PaintWindow();
	}
	else
	{
		 //关闭程序
		//ShowWindow(SW_HIDE);
		 PostQuitMessage(0);
	}
//****************************************************************************************
	CDialog::OnRButtonDown(nFlags, point);
}

BOOL CCatchScreenDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
//**************************************************************************************
	//用整个桌面填充全屏对话框背景
	BITMAP bmp;
	m_pBitmap->GetBitmap(&bmp);

	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);

	dcCompatible.SelectObject(m_pBitmap);

	CRect rect;
	GetClientRect(&rect);
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&dcCompatible,0,0,SRCCOPY);

	return TRUE;
//**************************************************************************************
	//return CDialog::OnEraseBkgnd(pDC);
}

BOOL CCatchScreenDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
//***********************************************************************
	//设置改变截取矩形大小时光标
	if (pWnd == this && m_rectTracker.SetCursor(this, nHitTest)) 
    {
		
		return TRUE; 
	}
	else
	{
		//设置彩色光标
		SetCursor(m_hCursor);
		return TRUE;
	}
//*******************************************************************
	//return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


//*********************增加的函数**********************************************************
//考贝屏幕,这段代码是拿来主义 呵呵
HBITMAP CCatchScreenDlg::CopyScreenToBitmap(LPRECT lpRect,BOOL bSave)
//lpRect 代表选定区域
{
	HDC       hScrDC, hMemDC;      
	// 屏幕和内存设备描述表
	HBITMAP    hBitmap, hOldBitmap;   
	// 位图句柄
	int       nX, nY, nX2, nY2;      
	// 选定区域坐标
	int       nWidth, nHeight;
	
	// 确保选定区域不为空矩形
	if (IsRectEmpty(lpRect))
		return NULL;
	//为屏幕创建设备描述表
	hScrDC = CreateDC("DISPLAY", NULL, NULL, NULL);

	//为屏幕设备描述表创建兼容的内存设备描述表
	hMemDC = CreateCompatibleDC(hScrDC);
	// 获得选定区域坐标
	nX = lpRect->left;
	nY = lpRect->top;
	nX2 = lpRect->right;
	nY2 = lpRect->bottom;

	//确保选定区域是可见的
	if (nX < 0)
		nX = 0;
	if (nY < 0)
		nY = 0;
	if (nX2 > m_xScreen)
		nX2 = m_xScreen;
	if (nY2 > m_yScreen)
		nY2 = m_yScreen;
	nWidth = nX2 - nX;
	nHeight = nY2 - nY;
	// 创建一个与屏幕设备描述表兼容的位图
	hBitmap = CreateCompatibleBitmap
		(hScrDC, nWidth, nHeight);
	// 把新位图选到内存设备描述表中
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);
	// 把屏幕设备描述表拷贝到内存设备描述表中
	if(bSave)
	{
		CDC dcCompatible;
		dcCompatible.CreateCompatibleDC(CDC::FromHandle(hMemDC));
		dcCompatible.SelectObject(m_pBitmap);
        
		BitBlt(hMemDC, 0, 0, nWidth, nHeight,
			dcCompatible, nX, nY, SRCCOPY);
	
	}
	else
	{
		BitBlt(hMemDC, 0, 0, nWidth, nHeight,
			hScrDC, nX, nY, SRCCOPY);
	}

	hBitmap = (HBITMAP)SelectObject(hMemDC, hOldBitmap);
	//得到屏幕位图的句柄
	//清除 
	DeleteDC(hScrDC);
	DeleteDC(hMemDC);
	// 返回位图句柄
	if(bSave)
	{
				
		if (OpenClipboard()) 
		{
        //清空剪贴板
        EmptyClipboard();
        //把屏幕内容粘贴到剪贴板上,
        //hBitmap 为刚才的屏幕位图句柄
        SetClipboardData(CF_BITMAP, hBitmap);
        //关闭剪贴板
        CloseClipboard();
      }
	}
	return hBitmap;
}

//显示操作提示信息
void CCatchScreenDlg::DrawTip()
{
    
    //得当前坐标像素,
	CPoint pt;
	GetCursorPos(&pt);
	
	//pt.x+=3;
	//pt.y+=3;

	//当到当前R,G,B,各像素值
	COLORREF color;
	CClientDC dc(this);
	color=dc.GetPixel(pt);
	BYTE rValue,gValue,bValue;
	rValue=GetRValue(color);
	gValue=GetGValue(color);
	bValue=GetGValue(color);
	
	//按格式排放字符串
/*	CString string;
	CString strTemp;
	string.Format("\r\n\r\n\r\n ·当前像素RGB (%d,%d,%d)\r\n",rValue,gValue,bValue);
    
	if(!m_bDraw&&!m_bFirstDraw)
	{
		strTemp="\r\n ·按下鼠标左键不放选择截取\r\n 范围\r\n\r\n ·按ESC键或鼠标右键退出";
	}
	else
	if(m_bDraw&&m_bFirstDraw)
	{
		strTemp="\r\n ·松开鼠标左键确定截取范围\r\n\r\n ·按ESC键退出";
	}
	else
	if(m_bFirstDraw)
	{
		strTemp="\r\n ·用鼠标左键调整截取范围的\r\n 大小和位置\r\n\r\n·截取范围内双击鼠标左键保存\r\n 图像，结束操作\r\n\r\n·点击鼠标右键重新选择";
	}
	string+=strTemp;
	//显示到编缉框中,操作提示窗口
	m_tipEdit.SetWindowText(string);
*/
}

//显示截取矩形信息
void CCatchScreenDlg::DrawMessage(CRect &inRect)
{
	//截取矩形大小信息离鼠标间隔
	const int space=3;
    
	//设置字体颜色大小
	CClientDC dc(this);
	CPoint pt;
	CPen pen(PS_SOLID,1,RGB(147,147,147));
	dc.SetTextColor(RGB(147,147,147));
	CFont font;
	font.CreatePointFont(90,"宋体");
	dc.SelectObject(&font);

	//得到字体宽度和高度
	GetCursorPos(&pt);
	dc.SetBkMode(TRANSPARENT);
	TEXTMETRIC tm;
	int charHeight;
	CSize size;
	int	lineLength;
	dc.GetTextMetrics(&tm);
	charHeight = tm.tmHeight+tm.tmExternalLeading;
	size=dc.GetTextExtent("顶点位置  ",strlen("顶点位置  "));
	lineLength=size.cx;
    
	//初始化矩形, 以保证写下六行文字
	CRect rect(pt.x+space,pt.y-charHeight*6-space,pt.x+lineLength+space,pt.y-space);

	int x = GetDeviceCaps(dc, HORZRES);
	int y = GetDeviceCaps(dc, VERTRES);

    //创建临时矩形
    CRect rectTemp;
	//当矩形到达桌面边缘时调整方向和大小
	if((pt.x+rect.Width())>=x)
	{
		//桌面上方显示不下矩形
		rectTemp=rect;
		rectTemp.left=rect.left-rect.Width()-space*2;
		rectTemp.right=rect.right-rect.Width()-space*2;;
		rect=rectTemp;
	}

	if((pt.y-rect.Height())<=0)
	{
		//桌面右方显示不下矩形
		rectTemp=rect;
		rectTemp.top=rect.top+rect.Height()+space*2;;
		rectTemp.bottom=rect.bottom+rect.Height()+space*2;;
		rect=rectTemp;
		
	}
    
	//创建空画刷画矩形
	dc.SelectObject((HBRUSH)GetStockObject(NULL_BRUSH));
	dc.Rectangle(rect);
   	rect.top+=2;
	//在矩形中显示文字
	CString string(" 顶点位置 ");
    dc.TextOut(rect.left,rect.top,string);

	string.Format(" (%d,%d)",inRect.left,inRect.top);
	dc.TextOut(rect.left,rect.top+charHeight,string);

	string=" 矩形大小 ";
	dc.TextOut(rect.left,rect.top+charHeight*2,string);

	string.Format(" (%d,%d)",inRect.Width(),inRect.Height());
	dc.TextOut(rect.left,rect.top+charHeight*3,string);

	string=" 光标坐标 ";
	dc.TextOut(rect.left,rect.top+charHeight*4,string);

	string.Format(" (%d,%d)",pt.x,pt.y);
	dc.TextOut(rect.left,rect.top+charHeight*5,string);
	
}
//重画窗口
void CCatchScreenDlg::PaintWindow()
{
	//获取当全屏对话框窗口大小
	CRect rect1;
	GetWindowRect(rect1);

	//获取编辑框窗口大小
	CRect rect2;
	m_tipEdit.GetWindowRect(rect2);

	CRgn rgn1,rgn2;
	rgn1.CreateRectRgnIndirect(rect1);
	rgn2.CreateRectRgnIndirect(rect2);

	//获取更新区域,就是除了编辑框窗口不更新
	m_rgn.CombineRgn(&rgn1,&rgn2,RGN_DIFF);
	
	InvalidateRgn(&m_rgn);
}

bool   SaveBitmapToFile(HBITMAP   hBitmap,   CString szfilename)   

 {   

       HDC hDC; //   设备描述表        

       int iBits; //   当前显示分辨率下每个像素所占字节数  

       WORD wBitCount; //   位图中每个像素所占字节数    

       DWORD dwPaletteSize   =   0   ; //   定义调色板大小，  位图中像素字节大小  ，  

       //   位图文件大小  ，  写入文件字节数

       DWORD dwBmBitsSize   ;   

       DWORD dwDIBSize,   dwWritten   ;   

       BITMAP Bitmap;                   

       BITMAPFILEHEADER bmfHdr; //位图属性结构  

       BITMAPINFOHEADER bi; //位图文件头结构   

       LPBITMAPINFOHEADER lpbi;   //位图信息头结构    

       HANDLE                     fh,   hDib,   hPal,hOldPal   =   NULL   ; //指向位图信息头结构,定义文件，分配内存句柄，调色板句柄

       //计算位图文件每个像素所占字节数  

       hDC   =   CreateDC(   "DISPLAY"   ,   NULL   ,   NULL   ,   NULL   )   ;   

       iBits   =   GetDeviceCaps(   hDC   ,   BITSPIXEL   )   *   GetDeviceCaps(   hDC   ,   PLANES   )   ;   

       DeleteDC(   hDC   )   ;   

       if   (   iBits   <=   1   )   

       { 

         wBitCount   =   1;   

       }  

       else   if   (   iBits   <=   4   )   

       { 

         wBitCount   =   4;   

       } 

       else   if   (   iBits   <=   8   )   

       {

         wBitCount   =   8;   

       }   

       else   if   (   iBits   <=   24   )   

       { 

         wBitCount   =   24;   

       }  

       else   if   (   iBits   <=   32   )   

       {   

         wBitCount   =   32;   

       }   

       //计算调色板大小  

       if   (   wBitCount   <=   8   )   

       {

         dwPaletteSize   =   (   1   <<   wBitCount   )   *   sizeof(   RGBQUAD   )   ;   

       }  

       //设置位图信息头结构  

       GetObject(   hBitmap   ,   sizeof(   BITMAP   )   ,   (   LPSTR   )   &   Bitmap   )   ;   

       bi.biSize                         =   sizeof(   BITMAPINFOHEADER   );   

       bi.biWidth                       =   Bitmap.bmWidth;      

       bi.biHeight                     =   Bitmap.bmHeight;    

       bi.biPlanes                     =   1;      

       bi.biBitCount                 =   wBitCount;      

       bi.biCompression           =   BI_RGB;   

       bi.biSizeImage               =   0;   

       bi.biXPelsPerMeter       =   0;   

       bi.biYPelsPerMeter       =   0;   

       bi.biClrUsed                   =   0;   

       bi.biClrImportant         =   0;   

       dwBmBitsSize   =   (   (   Bitmap.bmWidth   *   wBitCount   +   31   )   /   32   )   *   4   *   Bitmap.bmHeight   ;   

       //为位图内容分配内存  

       hDib     =   GlobalAlloc(   GHND   ,dwBmBitsSize   +   dwPaletteSize   +   sizeof(   BITMAPINFOHEADER   )   )   ;   

       lpbi   =   (   LPBITMAPINFOHEADER   )GlobalLock(   hDib   )   ; 

       *lpbi   =   bi;   

       //   处理调色板      

       hPal   =   GetStockObject(   DEFAULT_PALETTE   );   

       if   (   hPal   )   

       {   

              hDC =   ::GetDC(   NULL   );   

              hOldPal   =   SelectPalette(   hDC,   (HPALETTE   )   hPal   ,   FALSE   )   ;   

              RealizePalette(   hDC   )   ;   

       }  

       //   获取该调色板下新的像素值  

 

       GetDIBits(   hDC,   hBitmap,   0,   (   UINT   )   Bitmap.bmHeight,    

       (   LPSTR   )lpbi   +   sizeof(   BITMAPINFOHEADER   )   +   dwPaletteSize,   

       (   LPBITMAPINFO   )lpbi,   DIB_RGB_COLORS   );   

 

       //恢复调色板    

       if   (   hOldPal   )   

       {   

              SelectPalette(   hDC,   (   HPALETTE   )hOldPal,   TRUE   );   

              RealizePalette(   hDC   )   ;    

              ::ReleaseDC(   NULL,   hDC   )   ;   

       }  

       //创建位图文件

       fh   =   CreateFile(   szfilename   ,   GENERIC_WRITE,     

       0   ,   NULL   ,   CREATE_ALWAYS   ,   

       FILE_ATTRIBUTE_NORMAL   |   FILE_FLAG_SEQUENTIAL_SCAN   ,   NULL   )   ;  

       if   (   fh   ==   INVALID_HANDLE_VALUE   )   

       {   

              return   false;   

       }    

 

       //   设置位图文件头  

       bmfHdr.bfType   =   0x4D42;     //   "BM"     

       dwDIBSize =   sizeof(   BITMAPFILEHEADER   )   +   sizeof(   BITMAPINFOHEADER   )   +   dwPaletteSize   +   dwBmBitsSize;        

       bmfHdr.bfSize =   dwDIBSize;   

       bmfHdr.bfReserved1 =   0;   

       bmfHdr.bfReserved2 =   0;   

       bmfHdr.bfOffBits =   (   DWORD   )sizeof(   BITMAPFILEHEADER   )     

       +   (   DWORD   )sizeof(   BITMAPINFOHEADER   )   

       +   dwPaletteSize;   

       //   写入位图文件头  

       WriteFile(   fh,   (   LPSTR   )&bmfHdr,   sizeof    

       (   BITMAPFILEHEADER   ),   &dwWritten,   NULL);   

       //   写入位图文件其余内容  

       WriteFile(   fh,   (   LPSTR   )lpbi,   dwDIBSize,     

       &dwWritten   ,   NULL   );   

       //消除内存分配      

       GlobalUnlock(   hDib   );    

       GlobalFree(   hDib   );   

       CloseHandle(   fh   );   

       return   true;   

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

//*******************************************************************************************

