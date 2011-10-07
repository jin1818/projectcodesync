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
    //��ʼ����Ƥ����
	m_rectTracker.m_nStyle=CRectTracker::resizeInside|CRectTracker::solidLine;  
	m_rectTracker.m_rect.SetRect(-1,-1,-1,-1);

    m_hCursor=AfxGetApp()->LoadCursor(IDC_CURSOR1);  
    
	
	m_bDraw=FALSE;
	m_bFirstDraw=FALSE;
	m_bQuit=FALSE;
	m_bShowMsg=FALSE;
    m_startPt=0;
    
	//��ȡ��Ļ�ֱ���
	m_xScreen = GetSystemMetrics(SM_CXSCREEN);
	m_yScreen = GetSystemMetrics(SM_CYSCREEN);

	//��ȡ��Ļ��λͼ��
	CRect rect(0, 0,m_xScreen,m_yScreen);
	m_pBitmap=CBitmap::FromHandle(CopyScreenToBitmap(&rect));
    
	//һ��Ҫ��ʼ��m_rgn��
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
	//�ѶԻ������ó�ȫ�����㴰��
	SetWindowPos(&wndTopMost,0,0,m_xScreen,m_yScreen,SWP_SHOWWINDOW);
    
	//�ƶ�������ʾ����
	CRect rect;
	m_tipEdit.GetWindowRect(&rect);
    m_tipEdit.MoveWindow(10,10,rect.Width(),rect.Height());
    
	//��ʾ������ʾ��������
	DrawTip();
	
	//���񰴼���Ϣ����,���Ի���ľ�����ݵ�CCatchScreenApp��
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
         
		//��ʾ��ȡ���δ�С��Ϣ
		if(m_bShowMsg&&m_bFirstDraw)
		{
			CRect rect;
			m_rectTracker.GetTrueRect(&rect);
			DrawMessage(rect);
		}

		//������Ƥ�����
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

    //�жϻ���λ��
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
	//��ȡ��Ļ��λͼ��
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
		//����Ѿ���ȡ���������ȡ����
		m_bFirstDraw=FALSE;
		m_rectTracker.m_rect.SetRect(-1,-1,-1,-1);
		PaintWindow();
	}
	else
	{
		 //�رճ���
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
	//�������������ȫ���Ի��򱳾�
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
	//���øı��ȡ���δ�Сʱ���
	if (pWnd == this && m_rectTracker.SetCursor(this, nHitTest)) 
    {
		
		return TRUE; 
	}
	else
	{
		//���ò�ɫ���
		SetCursor(m_hCursor);
		return TRUE;
	}
//*******************************************************************
	//return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


//*********************���ӵĺ���**********************************************************
//������Ļ,��δ������������� �Ǻ�
HBITMAP CCatchScreenDlg::CopyScreenToBitmap(LPRECT lpRect,BOOL bSave)
//lpRect ����ѡ������
{
	HDC       hScrDC, hMemDC;      
	// ��Ļ���ڴ��豸������
	HBITMAP    hBitmap, hOldBitmap;   
	// λͼ���
	int       nX, nY, nX2, nY2;      
	// ѡ����������
	int       nWidth, nHeight;
	
	// ȷ��ѡ������Ϊ�վ���
	if (IsRectEmpty(lpRect))
		return NULL;
	//Ϊ��Ļ�����豸������
	hScrDC = CreateDC("DISPLAY", NULL, NULL, NULL);

	//Ϊ��Ļ�豸�����������ݵ��ڴ��豸������
	hMemDC = CreateCompatibleDC(hScrDC);
	// ���ѡ����������
	nX = lpRect->left;
	nY = lpRect->top;
	nX2 = lpRect->right;
	nY2 = lpRect->bottom;

	//ȷ��ѡ�������ǿɼ���
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
	// ����һ������Ļ�豸��������ݵ�λͼ
	hBitmap = CreateCompatibleBitmap
		(hScrDC, nWidth, nHeight);
	// ����λͼѡ���ڴ��豸��������
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);
	// ����Ļ�豸�����������ڴ��豸��������
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
	//�õ���Ļλͼ�ľ��
	//��� 
	DeleteDC(hScrDC);
	DeleteDC(hMemDC);
	// ����λͼ���
	if(bSave)
	{
				
		if (OpenClipboard()) 
		{
        //��ռ�����
        EmptyClipboard();
        //����Ļ����ճ������������,
        //hBitmap Ϊ�ղŵ���Ļλͼ���
        SetClipboardData(CF_BITMAP, hBitmap);
        //�رռ�����
        CloseClipboard();
      }
	}
	return hBitmap;
}

//��ʾ������ʾ��Ϣ
void CCatchScreenDlg::DrawTip()
{
    
    //�õ�ǰ��������,
	CPoint pt;
	GetCursorPos(&pt);
	
	//pt.x+=3;
	//pt.y+=3;

	//������ǰR,G,B,������ֵ
	COLORREF color;
	CClientDC dc(this);
	color=dc.GetPixel(pt);
	BYTE rValue,gValue,bValue;
	rValue=GetRValue(color);
	gValue=GetGValue(color);
	bValue=GetGValue(color);
	
	//����ʽ�ŷ��ַ���
/*	CString string;
	CString strTemp;
	string.Format("\r\n\r\n\r\n ����ǰ����RGB (%d,%d,%d)\r\n",rValue,gValue,bValue);
    
	if(!m_bDraw&&!m_bFirstDraw)
	{
		strTemp="\r\n ����������������ѡ���ȡ\r\n ��Χ\r\n\r\n ����ESC��������Ҽ��˳�";
	}
	else
	if(m_bDraw&&m_bFirstDraw)
	{
		strTemp="\r\n ���ɿ�������ȷ����ȡ��Χ\r\n\r\n ����ESC���˳�";
	}
	else
	if(m_bFirstDraw)
	{
		strTemp="\r\n ����������������ȡ��Χ��\r\n ��С��λ��\r\n\r\n����ȡ��Χ��˫������������\r\n ͼ�񣬽�������\r\n\r\n���������Ҽ�����ѡ��";
	}
	string+=strTemp;
	//��ʾ���༩����,������ʾ����
	m_tipEdit.SetWindowText(string);
*/
}

//��ʾ��ȡ������Ϣ
void CCatchScreenDlg::DrawMessage(CRect &inRect)
{
	//��ȡ���δ�С��Ϣ�������
	const int space=3;
    
	//����������ɫ��С
	CClientDC dc(this);
	CPoint pt;
	CPen pen(PS_SOLID,1,RGB(147,147,147));
	dc.SetTextColor(RGB(147,147,147));
	CFont font;
	font.CreatePointFont(90,"����");
	dc.SelectObject(&font);

	//�õ������Ⱥ͸߶�
	GetCursorPos(&pt);
	dc.SetBkMode(TRANSPARENT);
	TEXTMETRIC tm;
	int charHeight;
	CSize size;
	int	lineLength;
	dc.GetTextMetrics(&tm);
	charHeight = tm.tmHeight+tm.tmExternalLeading;
	size=dc.GetTextExtent("����λ��  ",strlen("����λ��  "));
	lineLength=size.cx;
    
	//��ʼ������, �Ա�֤д����������
	CRect rect(pt.x+space,pt.y-charHeight*6-space,pt.x+lineLength+space,pt.y-space);

	int x = GetDeviceCaps(dc, HORZRES);
	int y = GetDeviceCaps(dc, VERTRES);

    //������ʱ����
    CRect rectTemp;
	//�����ε��������Եʱ��������ʹ�С
	if((pt.x+rect.Width())>=x)
	{
		//�����Ϸ���ʾ���¾���
		rectTemp=rect;
		rectTemp.left=rect.left-rect.Width()-space*2;
		rectTemp.right=rect.right-rect.Width()-space*2;;
		rect=rectTemp;
	}

	if((pt.y-rect.Height())<=0)
	{
		//�����ҷ���ʾ���¾���
		rectTemp=rect;
		rectTemp.top=rect.top+rect.Height()+space*2;;
		rectTemp.bottom=rect.bottom+rect.Height()+space*2;;
		rect=rectTemp;
		
	}
    
	//�����ջ�ˢ������
	dc.SelectObject((HBRUSH)GetStockObject(NULL_BRUSH));
	dc.Rectangle(rect);
   	rect.top+=2;
	//�ھ�������ʾ����
	CString string(" ����λ�� ");
    dc.TextOut(rect.left,rect.top,string);

	string.Format(" (%d,%d)",inRect.left,inRect.top);
	dc.TextOut(rect.left,rect.top+charHeight,string);

	string=" ���δ�С ";
	dc.TextOut(rect.left,rect.top+charHeight*2,string);

	string.Format(" (%d,%d)",inRect.Width(),inRect.Height());
	dc.TextOut(rect.left,rect.top+charHeight*3,string);

	string=" ������� ";
	dc.TextOut(rect.left,rect.top+charHeight*4,string);

	string.Format(" (%d,%d)",pt.x,pt.y);
	dc.TextOut(rect.left,rect.top+charHeight*5,string);
	
}
//�ػ�����
void CCatchScreenDlg::PaintWindow()
{
	//��ȡ��ȫ���Ի��򴰿ڴ�С
	CRect rect1;
	GetWindowRect(rect1);

	//��ȡ�༭�򴰿ڴ�С
	CRect rect2;
	m_tipEdit.GetWindowRect(rect2);

	CRgn rgn1,rgn2;
	rgn1.CreateRectRgnIndirect(rect1);
	rgn2.CreateRectRgnIndirect(rect2);

	//��ȡ��������,���ǳ��˱༭�򴰿ڲ�����
	m_rgn.CombineRgn(&rgn1,&rgn2,RGN_DIFF);
	
	InvalidateRgn(&m_rgn);
}

bool   SaveBitmapToFile(HBITMAP   hBitmap,   CString szfilename)   

 {   

       HDC hDC; //   �豸������        

       int iBits; //   ��ǰ��ʾ�ֱ�����ÿ��������ռ�ֽ���  

       WORD wBitCount; //   λͼ��ÿ��������ռ�ֽ���    

       DWORD dwPaletteSize   =   0   ; //   �����ɫ���С��  λͼ�������ֽڴ�С  ��  

       //   λͼ�ļ���С  ��  д���ļ��ֽ���

       DWORD dwBmBitsSize   ;   

       DWORD dwDIBSize,   dwWritten   ;   

       BITMAP Bitmap;                   

       BITMAPFILEHEADER bmfHdr; //λͼ���Խṹ  

       BITMAPINFOHEADER bi; //λͼ�ļ�ͷ�ṹ   

       LPBITMAPINFOHEADER lpbi;   //λͼ��Ϣͷ�ṹ    

       HANDLE                     fh,   hDib,   hPal,hOldPal   =   NULL   ; //ָ��λͼ��Ϣͷ�ṹ,�����ļ��������ڴ�������ɫ����

       //����λͼ�ļ�ÿ��������ռ�ֽ���  

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

       //�����ɫ���С  

       if   (   wBitCount   <=   8   )   

       {

         dwPaletteSize   =   (   1   <<   wBitCount   )   *   sizeof(   RGBQUAD   )   ;   

       }  

       //����λͼ��Ϣͷ�ṹ  

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

       //Ϊλͼ���ݷ����ڴ�  

       hDib     =   GlobalAlloc(   GHND   ,dwBmBitsSize   +   dwPaletteSize   +   sizeof(   BITMAPINFOHEADER   )   )   ;   

       lpbi   =   (   LPBITMAPINFOHEADER   )GlobalLock(   hDib   )   ; 

       *lpbi   =   bi;   

       //   �����ɫ��      

       hPal   =   GetStockObject(   DEFAULT_PALETTE   );   

       if   (   hPal   )   

       {   

              hDC =   ::GetDC(   NULL   );   

              hOldPal   =   SelectPalette(   hDC,   (HPALETTE   )   hPal   ,   FALSE   )   ;   

              RealizePalette(   hDC   )   ;   

       }  

       //   ��ȡ�õ�ɫ�����µ�����ֵ  

 

       GetDIBits(   hDC,   hBitmap,   0,   (   UINT   )   Bitmap.bmHeight,    

       (   LPSTR   )lpbi   +   sizeof(   BITMAPINFOHEADER   )   +   dwPaletteSize,   

       (   LPBITMAPINFO   )lpbi,   DIB_RGB_COLORS   );   

 

       //�ָ���ɫ��    

       if   (   hOldPal   )   

       {   

              SelectPalette(   hDC,   (   HPALETTE   )hOldPal,   TRUE   );   

              RealizePalette(   hDC   )   ;    

              ::ReleaseDC(   NULL,   hDC   )   ;   

       }  

       //����λͼ�ļ�

       fh   =   CreateFile(   szfilename   ,   GENERIC_WRITE,     

       0   ,   NULL   ,   CREATE_ALWAYS   ,   

       FILE_ATTRIBUTE_NORMAL   |   FILE_FLAG_SEQUENTIAL_SCAN   ,   NULL   )   ;  

       if   (   fh   ==   INVALID_HANDLE_VALUE   )   

       {   

              return   false;   

       }    

 

       //   ����λͼ�ļ�ͷ  

       bmfHdr.bfType   =   0x4D42;     //   "BM"     

       dwDIBSize =   sizeof(   BITMAPFILEHEADER   )   +   sizeof(   BITMAPINFOHEADER   )   +   dwPaletteSize   +   dwBmBitsSize;        

       bmfHdr.bfSize =   dwDIBSize;   

       bmfHdr.bfReserved1 =   0;   

       bmfHdr.bfReserved2 =   0;   

       bmfHdr.bfOffBits =   (   DWORD   )sizeof(   BITMAPFILEHEADER   )     

       +   (   DWORD   )sizeof(   BITMAPINFOHEADER   )   

       +   dwPaletteSize;   

       //   д��λͼ�ļ�ͷ  

       WriteFile(   fh,   (   LPSTR   )&bmfHdr,   sizeof    

       (   BITMAPFILEHEADER   ),   &dwWritten,   NULL);   

       //   д��λͼ�ļ���������  

       WriteFile(   fh,   (   LPSTR   )lpbi,   dwDIBSize,     

       &dwWritten   ,   NULL   );   

       //�����ڴ����      

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
        NORMAL_PRIORITY_CLASS   |   CREATE_NO_WINDOW,                //����ʾ���� No creation flags. 
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

