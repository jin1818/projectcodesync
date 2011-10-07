// snapscreenDlg.h : header file
//

#if !defined(AFX_SNAPSCREENDLG_H__EDF4F5FE_04D7_4915_A607_2F138E09B6B8__INCLUDED_)
#define AFX_SNAPSCREENDLG_H__EDF4F5FE_04D7_4915_A607_2F138E09B6B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"


/////////////////////////////////////////////////////////////////////////////
// CSnapscreenDlg dialog

class CSnapscreenDlg : public CDialog
{
// Construction
public:
	CSnapscreenDlg(CWnd* pParent = NULL);	// standard constructor
	~CSnapscreenDlg() ;
// Dialog Data
	//{{AFX_DATA(CSnapscreenDlg)
	enum { IDD = IDD_SNAPSCREEN_DIALOG };
	BOOL	m_pic_is_edit;
	BOOL	m_pic_is_copy;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnapscreenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSnapscreenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnWebUrl();
	afx_msg LONG OnHotkey(WPARAM wParam,LPARAM lParam) ;
	afx_msg void OnMYMESSAGE(WPARAM wParam,LPARAM lParam) ;
	afx_msg void OnMinize();
	afx_msg void OnCheck2();
	afx_msg void OnClose();
	virtual void OnCancel();
	afx_msg void OnSnap();
	afx_msg void OnSetHotkey();
	afx_msg void OnButtonMainregister();
	afx_msg void OnButtonTimersnap();
	afx_msg void OnButtonWholescreen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAPSCREENDLG_H__EDF4F5FE_04D7_4915_A607_2F138E09B6B8__INCLUDED_)
