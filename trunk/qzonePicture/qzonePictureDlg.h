// qzonePictureDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_QZONEPICTUREDLG_H__ABD071DC_0F64_45F8_97C8_41AF026518D1__INCLUDED_)
#define AFX_QZONEPICTUREDLG_H__ABD071DC_0F64_45F8_97C8_41AF026518D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include   <afxtempl.h> 
#include <list>

/////////////////////////////////////////////////////////////////////////////
// CQzonePictureDlg dialog

class CQzonePictureDlg : public CDialog
{
// Construction
public:
	CQzonePictureDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CQzonePictureDlg)
	enum { IDD = IDD_QZONEPICTURE_DIALOG };
	CWebBrowser2	m_browser;
	CString	m_num;
	CString m_strCookie ;
	CString	m_savePath;
	CString	m_readme;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQzonePictureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	struct AlbumStr {
		CString name ;
		CString id ;
		CString type ;
	};
	std::list<AlbumStr> m_pictureList ;
	void DealMessage() ;
	void OnButtonGetlist_i() ;

	// Generated message map functions
	//{{AFX_MSG(CQzonePictureDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonGetcookie();
	afx_msg void OnButtonGetlist();
	afx_msg void OnButtonDownload();
	afx_msg void OnButtonSavepath();
	afx_msg void OnButtonRegister();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QZONEPICTUREDLG_H__ABD071DC_0F64_45F8_97C8_41AF026518D1__INCLUDED_)
