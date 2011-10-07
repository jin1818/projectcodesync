// testborderDoc.cpp :  CtestborderDoc 类的实现
//

#include "stdafx.h"
#include "testborder.h"

#include "testborderDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestborderDoc

IMPLEMENT_DYNCREATE(CtestborderDoc, CDocument)

BEGIN_MESSAGE_MAP(CtestborderDoc, CDocument)
END_MESSAGE_MAP()


// CtestborderDoc 构造/析构

CtestborderDoc::CtestborderDoc()
{
	// TODO: 在此添加一次性构造代码

}

CtestborderDoc::~CtestborderDoc()
{
}

BOOL CtestborderDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CtestborderDoc 序列化

void CtestborderDoc::Serialize(CArchive& ar)
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


// CtestborderDoc 诊断

#ifdef _DEBUG
void CtestborderDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CtestborderDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CtestborderDoc 命令
