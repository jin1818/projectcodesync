// InternetShopDoc.cpp :  CInternetShopDoc ���ʵ��
//

#include "stdafx.h"
#include "InternetShop.h"

#include "InternetShopDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInternetShopDoc

IMPLEMENT_DYNCREATE(CInternetShopDoc, CDocument)

BEGIN_MESSAGE_MAP(CInternetShopDoc, CDocument)
END_MESSAGE_MAP()


// CInternetShopDoc ����/����

CInternetShopDoc::CInternetShopDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CInternetShopDoc::~CInternetShopDoc()
{
}

BOOL CInternetShopDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CInternetShopDoc ���л�

void CInternetShopDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CInternetShopDoc ���

#ifdef _DEBUG
void CInternetShopDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CInternetShopDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CInternetShopDoc ����
