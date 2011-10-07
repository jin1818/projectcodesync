#pragma once



// CFormLeft form view

class CFormLeft : public CFormView
{
	DECLARE_DYNCREATE(CFormLeft)

protected:
	CFormLeft();           // protected constructor used by dynamic creation
	virtual ~CFormLeft();

public:
	enum { IDD = IDD_FORM_LEFT };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	CWnd* m_target;
public:
	void SetTarget(CWnd* m_cwnd);
};


