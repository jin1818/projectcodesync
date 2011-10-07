// MainFrm.cpp : CMainFrame 类的实现
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


// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或
	// 样式

	cs.style &= ~WS_BORDER;
    if(cs.hMenu!=NULL)       
    {       
        ::DestroyMenu(cs.hMenu);  
        cs.hMenu = NULL;  
    }   
    //去掉菜单栏 
    //cs.x=0;   //改变初始位置   
    //cs.y=0;   
    cs.cx=480;     //改变初始大小   
    cs.cy=760; 
    cs.style=WS_POPUP;//改变弹出风格，无标题栏

	return TRUE;
}


// CMainFrame 诊断

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


// CMainFrame 消息处理程序

