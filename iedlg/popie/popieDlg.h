// popieDlg.h : header file
//

#if !defined(AFX_POPIEDLG_H__383F4D34_81FD_4A75_8657_79E95A5727BF__INCLUDED_)
#define AFX_POPIEDLG_H__383F4D34_81FD_4A75_8657_79E95A5727BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "msgwnd.h"

/////////////////////////////////////////////////////////////////////////////
// CPopieDlg dialog

class CPopieDlg : public CDialog
{
// Construction
public:
	CPopieDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPopieDlg)
	enum { IDD = IDD_POPIE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopieDlg)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CString m_cmdLine ;
	CList<CString>	_piclist ;
	int	m_iChangeInterval ;	
	CMsgWnd *pMsgWindow ;


	// Generated message map functions
	//{{AFX_MSG(CPopieDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPIEDLG_H__383F4D34_81FD_4A75_8657_79E95A5727BF__INCLUDED_)
