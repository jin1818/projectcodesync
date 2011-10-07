#if !defined(AFX_MAINDLG_H__4E116AB9_FDC3_4C04_B00E_222EAE965D94__INCLUDED_)
#define AFX_MAINDLG_H__4E116AB9_FDC3_4C04_B00E_222EAE965D94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainDlg.h : header file
//

#include "LinkMgrDlg.h"
#include "WeatherDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog

class CMainDlg : public CDialog
{
// Construction
public:
	CMainDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMainDlg)
	enum { IDD = IDD_MAIN };
	BOOL	m_autoRun;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CPropertySheet m_sheet ;
	CLinkMgrDlg m_pageLinkMgr ;
	CWeatherDlg m_pageWeather ;
	HICON m_hIcon;
	int m_flags ;
	void AddSystrayIcon() ;
	void DelSystrayIcon() ;
	// Generated message map functions
	//{{AFX_MSG(CMainDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFindFile();
	afx_msg void OnImport();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	afx_msg void OnHide();
	afx_msg void OnAutorun();
	afx_msg void OnRun();
	afx_msg void OnCheckAutorun();
	afx_msg void OnNOTIFYICON(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDLG_H__4E116AB9_FDC3_4C04_B00E_222EAE965D94__INCLUDED_)
