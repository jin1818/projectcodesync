// testborderDoc.cpp :  CtestborderDoc ���ʵ��
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


// CtestborderDoc ����/����

CtestborderDoc::CtestborderDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CtestborderDoc::~CtestborderDoc()
{
}

BOOL CtestborderDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CtestborderDoc ���л�

void CtestborderDoc::Serialize(CArchive& ar)
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


// CtestborderDoc ���

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


// CtestborderDoc ����
