// testborderView.cpp : CtestborderView 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CtestborderView 构造/析构

CtestborderView::CtestborderView()
{
	// TODO: 在此处添加构造代码

}

CtestborderView::~CtestborderView()
{
}

BOOL CtestborderView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或
	// 样式

	return CView::PreCreateWindow(cs);
}

// CtestborderView 绘制

void CtestborderView::OnDraw(CDC* /*pDC*/)
{
	CtestborderDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CtestborderView 打印

BOOL CtestborderView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CtestborderView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 打印前添加额外的初始化
}

void CtestborderView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 打印后添加清除过程
}


// CtestborderView 诊断

#ifdef _DEBUG
void CtestborderView::AssertValid() const
{
	CView::AssertValid();
}

void CtestborderView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtestborderDoc* CtestborderView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtestborderDoc)));
	return (CtestborderDoc*)m_pDocument;
}
#endif //_DEBUG


// CtestborderView 消息处理程序
