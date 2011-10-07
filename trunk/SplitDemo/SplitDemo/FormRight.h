#pragma once
#include "afxwin.h"



// CFormRight form view

class CFormRight : public CFormView
{
	DECLARE_DYNCREATE(CFormRight)

protected:
	CFormRight();           // protected constructor used by dynamic creation
	virtual ~CFormRight();

public:
	enum { IDD = IDD_FORM_RIGHT };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_hello;
public:
	afx_msg void OnBnClickedButtonHello();
};


