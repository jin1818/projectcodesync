// LinkMgrDlg.h : header file
//

#if !defined(AFX_LINKMGRDLG_H__C62A6BF6_BE9E_4B19_9CEA_5F32E2953C22__INCLUDED_)
#define AFX_LINKMGRDLG_H__C62A6BF6_BE9E_4B19_9CEA_5F32E2953C22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLinkMgrDlg dialog

class CLinkMgrDlg : public CPropertyPage
{
// Construction
public:
	CLinkMgrDlg(CWnd* pParent = NULL);	// standard constructor
	
	afx_msg void OnRun();

// Dialog Data
	//{{AFX_DATA(CLinkMgrDlg)
	enum { IDD = IDD_LINKMGR_DIALOG };
	CListCtrl	m_show;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkMgrDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
	


// Implementation
protected:
	HICON m_hIcon;
	CImageList m_ImageList;
	int	m_flags ;

	void makeLink(CString fileName, CString shortName)  ;

	CString getLinksDir() ;

	void LoadLinks() ;

	void AddSystrayIcon() ;
	void DelSystrayIcon() ;
	// Generated message map functions
	//{{AFX_MSG(CLinkMgrDlg)
	virtual BOOL OnInitDialog();

	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFindFile();
	afx_msg void OnImport();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKMGRDLG_H__C62A6BF6_BE9E_4B19_9CEA_5F32E2953C22__INCLUDED_)
