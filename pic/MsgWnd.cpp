// MsgWnd.cpp : implementation file
//

#include "stdafx.h"
#include "MsgWnd.h"
#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//---------------------------------------------------------------------------
#define ID_TIMER_POP_WINDOW		10
#define ID_TIMER_CLOSE_WINDOW	11
#define ID_TIMER_DISPLAY_DELAY	12
static int WIN_WIDTH =	400;//181
static int WIN_HEIGHT = 300;//116
static int cTimeselay = 3000;
/////////////////////////////////////////////////////////////////////////////
// CMsgWnd

static int nHeight=0;

CMsgWnd::CMsgWnd()
:m_bFlag(false) 
{
	
}

CMsgWnd::~CMsgWnd()
{
}


BEGIN_MESSAGE_MAP(CMsgWnd, CWnd)
	//{{AFX_MSG_MAP(CMsgWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMsgWnd message handlers
void CMsgWnd::CreateMsgWindow(int iWidth,int iHeight,int iTime,CString sUrl)
{

	WIN_WIDTH = iWidth;
	WIN_HEIGHT = iHeight;
	cTimeselay = iTime*1000;
	CreateEx(0,
		     AfxRegisterWndClass(
			 0,
			 ::LoadCursor(
				AfxGetInstanceHandle(),
				MAKEINTRESOURCE(IDC_HAND_1)),
				(HBRUSH)(COLOR_DESKTOP+1),
				NULL),
			 "",
			 WS_POPUP|WS_EX_TOOLWINDOW,
			 0,
			 0,
			 0,//bmBitmap.bmWidth,  //Bitmap Width = Splash Window Width
			 0,//bmBitmap.bmHeight, //Bitmap Height = Splash Window Height
			 NULL,//AfxGetMainWnd()->GetSafeHwnd(),
			 NULL,
			 NULL
			 );

	RECT rc = {0 , 0 , 800 , 660};
	m_wndWeb.Create(NULL,WS_CHILD | WS_VISIBLE |WS_EX_TOOLWINDOW , rc,this,1234);
	m_wndWeb.Navigate(sUrl,NULL,NULL,NULL,NULL);//设置IE内容
	MoveWindow(0 , 0 , 800 , 660, true) ;
	CenterWindow(NULL);
}


void CMsgWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CDC dcMemory;
    dcMemory.CreateCompatibleDC(NULL);
	dcMemory.SelectObject(&m_Bitmap);
	dc.StretchBlt(0,
		0,
		800,//bmBitmap.bmWidth,
		680,//bmBitmap.bmHeight,    
		&dcMemory, 
		0,
		0,
		bmBitmap.bmWidth,    
		bmBitmap.bmHeight,
		SRCCOPY);
}

void CMsgWnd::OnTimer(UINT nIDEvent) 
{	
	RECT rc;
	GetClientRect(&rc);
	m_wndWeb.MoveWindow(&rc);
    ::SetWindowPos( m_hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE|SWP_NOACTIVATE); 

 	int cy=GetSystemMetrics(SM_CYSCREEN);
	int cx=GetSystemMetrics(SM_CXSCREEN);
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA,0,&rect,0);
	int y=rect.bottom-rect.top;
	int x=rect.right-rect.left;
	x=x-WIN_WIDTH;
	
	switch(nIDEvent)
	{
	case ID_TIMER_POP_WINDOW:
		if(nHeight<=WIN_HEIGHT)
		{
		//	++nHeight;		
			nHeight= nHeight+5;
			MoveWindow(x,
				y-nHeight,
				WIN_WIDTH,
				WIN_HEIGHT);
			
		    Invalidate(FALSE);
		}
		else
		{
			KillTimer(ID_TIMER_POP_WINDOW);
			SetTimer(ID_TIMER_DISPLAY_DELAY,cTimeselay,NULL);
		}
		break;
	case ID_TIMER_CLOSE_WINDOW:
		if(nHeight>=0)
		{
			nHeight=nHeight-5;
			MoveWindow(x,
				y-nHeight,
				WIN_WIDTH,
				nHeight);
		}
		else
		{
			KillTimer(ID_TIMER_CLOSE_WINDOW);
			SendMessage(WM_CLOSE);
		}
		break;
	case ID_TIMER_DISPLAY_DELAY:
		KillTimer(ID_TIMER_DISPLAY_DELAY);
		break;
	}
	
	CWnd::OnTimer(nIDEvent);
}

int CMsgWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{

	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	/////隐藏任务栏的标题
	 ModifyStyleEx(0,WS_EX_TOOLWINDOW );
	::SetWindowPos( m_hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE|SWP_NOACTIVATE); 
	return 0;
}


void CMsgWnd::OnMouseMove(UINT nFlags, CPoint point) 
{
	CRect rect;
	GetClientRect(&rect);
	if(rect.PtInRect(point))
	{	m_bFlag=true;
		KillTimer(ID_TIMER_DISPLAY_DELAY);
	}	
	CWnd::OnMouseMove(nFlags, point);
}

void 
CMsgWnd::SetWindowUrl(CString sUrl)
{
	if ( this ->m_wndWeb.GetSafeHwnd() != NULL )
	{
		this ->m_wndWeb.Navigate(sUrl,NULL,NULL,NULL,NULL);
		this ->m_wndWeb.UpdateWindow() ;
	}
}

void
CMsgWnd::OnClose()
{
}