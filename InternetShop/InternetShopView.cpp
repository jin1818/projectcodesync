// InternetShopView.cpp : CInternetShopView ���ʵ��
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

// CInternetShopView ����/����

CInternetShopView::CInternetShopView()
{
	// TODO: �ڴ˴���ӹ������

}

CInternetShopView::~CInternetShopView()
{
}

BOOL CInternetShopView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ������
	// ��ʽ

	return CHtmlView::PreCreateWindow(cs);
}

void CInternetShopView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();
	Navigate2(_T("F:\\project\\InternetShop\\internetshop.html"),NULL,NULL);
	
}


// CInternetShopView ���

#ifdef _DEBUG
void CInternetShopView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CInternetShopView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CInternetShopDoc* CInternetShopView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CInternetShopDoc)));
	return (CInternetShopDoc*)m_pDocument;
}
#endif //_DEBUG


// CInternetShopView ��Ϣ�������
