// TBADDoc.cpp : implementation of the CTBADDoc class
//

#include "stdafx.h"
#include "TBAD.h"

#include "TBADDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTBADDoc

IMPLEMENT_DYNCREATE(CTBADDoc, CDocument)

BEGIN_MESSAGE_MAP(CTBADDoc, CDocument)
	//{{AFX_MSG_MAP(CTBADDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTBADDoc construction/destruction

CTBADDoc::CTBADDoc()
{
	// TODO: add one-time construction code here

}

CTBADDoc::~CTBADDoc()
{
}

BOOL CTBADDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTBADDoc serialization

void CTBADDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTBADDoc diagnostics

#ifdef _DEBUG
void CTBADDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTBADDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTBADDoc commands
