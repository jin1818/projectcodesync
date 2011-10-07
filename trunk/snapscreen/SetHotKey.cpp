// SetHotKey.cpp : implementation file
//

#include "stdafx.h"
#include "snapscreen.h"
#include "SetHotKey.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SetHotKey dialog


SetHotKey::SetHotKey(CWnd* pParent /*=NULL*/)
	: CDialog(SetHotKey::IDD, pParent)
{
	//{{AFX_DATA_INIT(SetHotKey)
	m_key = _T("");
	//}}AFX_DATA_INIT
}


void SetHotKey::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SetHotKey)
	DDX_Text(pDX, IDC_EDIT1, m_key);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SetHotKey, CDialog)
	//{{AFX_MSG_MAP(SetHotKey)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SetHotKey message handlers
