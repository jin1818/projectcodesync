// FormRight.cpp : implementation file
//

#include "stdafx.h"
#include "SplitDemo.h"
#include "FormRight.h"


// CFormRight

IMPLEMENT_DYNCREATE(CFormRight, CFormView)

CFormRight::CFormRight()
	: CFormView(CFormRight::IDD)
{

}

CFormRight::~CFormRight()
{
}

void CFormRight::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_HELLO, m_hello);
}

BEGIN_MESSAGE_MAP(CFormRight, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_HELLO, &CFormRight::OnBnClickedButtonHello)
END_MESSAGE_MAP()


// CFormRight diagnostics

#ifdef _DEBUG
void CFormRight::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormRight::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormRight message handlers

void CFormRight::OnBnClickedButtonHello()
{
	// TODO: Add your control notification handler code here
	m_hello.SetWindowText("Hello Window Splitter!");
}
