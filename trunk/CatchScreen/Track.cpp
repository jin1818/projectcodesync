// Track.cpp : implementation file
//

#include "stdafx.h"
#include "Track.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CTrack

//IMPLEMENT_DYNCREATE(CTrack, CFrameWnd)

CTrack::CTrack()
{

}

CTrack::~CTrack()
{
}


void CTrack::DrawTrackerRect( LPCRECT lpRect, CWnd* pWndClipTo,CDC* pDC, CWnd* pWnd )
{	    
    //���´���,����TRACKʱ�����߿�
    ((CCatchScreenDlg *)pWnd)->PaintWindow();
	((CCatchScreenDlg *)pWnd)->SendMessage(WM_MOUSEMOVE);		
}

