// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "testborder.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
END_MESSAGE_MAP()


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ������
	// ��ʽ

	cs.style &= ~WS_BORDER;
    if(cs.hMenu!=NULL)       
    {       
        ::DestroyMenu(cs.hMenu);  
        cs.hMenu = NULL;  
    }   
    //ȥ���˵��� 
    //cs.x=0;   //�ı��ʼλ��   
    //cs.y=0;   
    cs.cx=480;     //�ı��ʼ��С   
    cs.cy=760; 
    cs.style=WS_POPUP;//�ı䵯������ޱ�����

	return TRUE;
}


// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame ��Ϣ�������

