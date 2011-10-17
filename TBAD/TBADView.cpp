// TBADView.cpp : implementation of the CTBADView class
//

#include "stdafx.h"
#include "TBAD.h"

#include "TBADDoc.h"
#include "TBADView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTBADView

IMPLEMENT_DYNCREATE(CTBADView, CHtmlView)

BEGIN_MESSAGE_MAP(CTBADView, CHtmlView)
	//{{AFX_MSG_MAP(CTBADView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_WM_PARENTNOTIFY() 
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTBADView construction/destruction

CTBADView::CTBADView()
{
	// TODO: add construction code here

}

CTBADView::~CTBADView()
{
}

BOOL CTBADView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style &= ~WS_BORDER;
	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTBADView drawing

void CTBADView::OnDraw(CDC* pDC)
{
	CTBADDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CTBADView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	this->LoadFromResource(IDR_TBAD) ;
}

void CTBADView::OnParentNotify( UINT message, LPARAM lParam )
{
	if ((LOWORD(message) == WM_DESTROY) && ((HWND)lParam == m_wndBrowser)) 	
	{ 	
		// Close the parent frame window.
		GetParentFrame()->PostMessage(WM_CLOSE, 0, 0); 
	} 	
	else 		
		CHtmlView::OnParentNotify(message, lParam ); 
}

/////////////////////////////////////////////////////////////////////////////
// CTBADView printing


/////////////////////////////////////////////////////////////////////////////
// CTBADView diagnostics

#ifdef _DEBUG
void CTBADView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CTBADView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CTBADDoc* CTBADView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTBADDoc)));
	return (CTBADDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTBADView message handlers
