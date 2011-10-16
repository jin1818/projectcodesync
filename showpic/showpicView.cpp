// showpicView.cpp : implementation of the CShowpicView class
//

#include "stdafx.h"
#include "showpic.h"

#include "showpicDoc.h"
#include "showpicView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowpicView

IMPLEMENT_DYNCREATE(CShowpicView, CHtmlView)

BEGIN_MESSAGE_MAP(CShowpicView, CHtmlView)
	//{{AFX_MSG_MAP(CShowpicView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowpicView construction/destruction

CShowpicView::CShowpicView()
{
	// TODO: add construction code here

}

CShowpicView::~CShowpicView()
{
}

BOOL CShowpicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShowpicView drawing

void CShowpicView::OnDraw(CDC* pDC)
{
	CShowpicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

}

void CShowpicView::OnInitialUpdate()
{

	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	Navigate2(_T("I:\\ÎâÓîº½\\ÎâÓîº½Ïà²á\\Í¼Æ¬\\·ç¾°±ÚÖ½\\001.jpg"),NULL,NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CShowpicView printing


/////////////////////////////////////////////////////////////////////////////
// CShowpicView diagnostics

#ifdef _DEBUG
void CShowpicView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CShowpicView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CShowpicDoc* CShowpicView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowpicDoc)));
	return (CShowpicDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowpicView message handlers
