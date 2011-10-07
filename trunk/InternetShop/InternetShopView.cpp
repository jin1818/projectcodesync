// InternetShopView.cpp : CInternetShopView 类的实现
//

#include "stdafx.h"
#include "InternetShop.h"

#include "InternetShopDoc.h"
#include "InternetShopView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInternetShopView

IMPLEMENT_DYNCREATE(CInternetShopView, CHtmlView)

BEGIN_MESSAGE_MAP(CInternetShopView, CHtmlView)
END_MESSAGE_MAP()

// CInternetShopView 构造/析构

CInternetShopView::CInternetShopView()
{
	// TODO: 在此处添加构造代码

}

CInternetShopView::~CInternetShopView()
{
}

BOOL CInternetShopView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或
	// 样式

	return CHtmlView::PreCreateWindow(cs);
}

void CInternetShopView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();
	Navigate2(_T("F:\\project\\InternetShop\\internetshop.html"),NULL,NULL);
	
}


// CInternetShopView 诊断

#ifdef _DEBUG
void CInternetShopView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CInternetShopView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CInternetShopDoc* CInternetShopView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CInternetShopDoc)));
	return (CInternetShopDoc*)m_pDocument;
}
#endif //_DEBUG


// CInternetShopView 消息处理程序
