// TimerSnapSet.cpp : implementation file
//

#include "stdafx.h"
#include "snapscreen.h"
#include "TimerSnapSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TimerSnapSet dialog


TimerSnapSet::TimerSnapSet(CWnd* pParent /*=NULL*/)
	: CDialog(TimerSnapSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(TimerSnapSet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void TimerSnapSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TimerSnapSet)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TimerSnapSet, CDialog)
	//{{AFX_MSG_MAP(TimerSnapSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TimerSnapSet message handlers

void TimerSnapSet::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
