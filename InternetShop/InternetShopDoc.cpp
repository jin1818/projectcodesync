// InternetShopDoc.cpp :  CInternetShopDoc 类的实现
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


// CInternetShopDoc 构造/析构

CInternetShopDoc::CInternetShopDoc()
{
	// TODO: 在此添加一次性构造代码

}

CInternetShopDoc::~CInternetShopDoc()
{
}

BOOL CInternetShopDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CInternetShopDoc 序列化

void CInternetShopDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CInternetShopDoc 诊断

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


// CInternetShopDoc 命令
