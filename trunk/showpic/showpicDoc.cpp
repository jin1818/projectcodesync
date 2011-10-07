// showpicDoc.cpp : implementation of the CShowpicDoc class
//

#include "stdafx.h"
#include "showpic.h"

#include "showpicDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowpicDoc

IMPLEMENT_DYNCREATE(CShowpicDoc, CDocument)

BEGIN_MESSAGE_MAP(CShowpicDoc, CDocument)
	//{{AFX_MSG_MAP(CShowpicDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowpicDoc construction/destruction

CShowpicDoc::CShowpicDoc()
{
	// TODO: add one-time construction code here

}

CShowpicDoc::~CShowpicDoc()
{
}

BOOL CShowpicDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShowpicDoc serialization

void CShowpicDoc::Serialize(CArchive& ar)
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
// CShowpicDoc diagnostics

#ifdef _DEBUG
void CShowpicDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShowpicDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowpicDoc commands
