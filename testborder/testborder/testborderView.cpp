// testborderView.cpp : CtestborderView ���ʵ��
//

#include "stdafx.h"
#include "testborder.h"

#include "testborderDoc.h"
#include "testborderView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestborderView

IMPLEMENT_DYNCREATE(CtestborderView, CView)

BEGIN_MESSAGE_MAP(CtestborderView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CtestborderView ����/����

CtestborderView::CtestborderView()
{
	// TODO: �ڴ˴���ӹ������

}

CtestborderView::~CtestborderView()
{
}

BOOL CtestborderView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ������
	// ��ʽ

	return CView::PreCreateWindow(cs);
}

// CtestborderView ����

void CtestborderView::OnDraw(CDC* /*pDC*/)
{
	CtestborderDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CtestborderView ��ӡ

BOOL CtestborderView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CtestborderView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��ӡǰ��Ӷ���ĳ�ʼ��
}

void CtestborderView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��ӡ������������
}


// CtestborderView ���

#ifdef _DEBUG
void CtestborderView::AssertValid() const
{
	CView::AssertValid();
}

void CtestborderView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtestborderDoc* CtestborderView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtestborderDoc)));
	return (CtestborderDoc*)m_pDocument;
}
#endif //_DEBUG


// CtestborderView ��Ϣ�������
