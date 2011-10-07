#if !defined(AFX_DESKTOPLINKS_H__8AEB1BE6_1910_49B6_ABB6_45F0589428CF__INCLUDED_)
#define AFX_DESKTOPLINKS_H__8AEB1BE6_1910_49B6_ABB6_45F0589428CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeskTopLinks.h : header file
//

#include "./skin/SkinDialog.h"
#include "skin/SkinButton.h"

/////////////////////////////////////////////////////////////////////////////
// CDeskTopLinks dialog

class CDeskTopLinks : public CSkinDialog
{
// Construction
public:
	CDeskTopLinks(CWnd* pParent = NULL);   // standard constructor
	void MoveWindow(LPCRECT lpRect, BOOL bRepaint = TRUE);
// Dialog Data
	//{{AFX_DATA(CDeskTopLinks)
	enum { IDD = IDD_DeskTopLinks };
	CSkinButton	m_add;
	CSkinButton	m_import;
	CListCtrl	m_show;
	//}}AFX_DATA

	void makeLink(CString fileName, CString shortName)  ;
	
	CString getLinksDir() ;
	
	void LoadLinks() ;
	
	afx_msg void OnRun();
	afx_msg void OnDelete();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeskTopLinks)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	CImageList m_ImageList;
	// Generated message map functions
	//{{AFX_MSG(CDeskTopLinks)
	afx_msg void OnLinksImport();
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkLinksList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickLinksList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLinksAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESKTOPLINKS_H__8AEB1BE6_1910_49B6_ABB6_45F0589428CF__INCLUDED_)
