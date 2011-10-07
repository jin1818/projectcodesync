// RisingUiDlg.h : header file
//

#if !defined(AFX_RISINGUIDLG_H__86EE656B_4885_4D32_A7F4_759A22162DF6__INCLUDED_)
#define AFX_RISINGUIDLG_H__86EE656B_4885_4D32_A7F4_759A22162DF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRisingUiDlg dialog
#include "skin/SkinDialog.h"
#include "skin/SkinTabCtrl.h"
#include "DlgInfo.h"
#include "DlgLink.h"
#include "InternetShop.h"
#include "DeskTopLinks.h"

#include <vector>

class CRisingUiDlg : public CSkinDialog
{
// Construction
public:
	CRisingUiDlg(CWnd* pParent = NULL);	// standard constructor

	CDlgInfo m_dlgInfo;
	CDlgLink m_dlgLink;
	CInternetShop m_dlgInternetShop ;
	CDeskTopLinks m_dlgDeskTopLinks ;
	int m_nCurDlg;
	std::vector<CDialog *> m_vtPDlg;

	void ShowChildDlg(int nIndex);
	afx_msg void OnRun();
// Dialog Data
	//{{AFX_DATA(CRisingUiDlg)
	enum { IDD = IDD_RISINGUI_DIALOG };
	CSkinTabCtrl	m_tabViews;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRisingUiDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	void AddSystrayIcon() ;
	void DelSystrayIcon() ;

	// Generated message map functions
	//{{AFX_MSG(CRisingUiDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAbout();
	afx_msg void OnDelete();
	afx_msg LRESULT OnNOTIFYICON(WPARAM wParam, LPARAM lParam) ;
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RISINGUIDLG_H__86EE656B_4885_4D32_A7F4_759A22162DF6__INCLUDED_)
