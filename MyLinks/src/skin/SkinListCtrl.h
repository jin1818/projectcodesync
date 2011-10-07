#if !defined(AFX_SKINLISTCTRL_H__D3CFCB79_0C15_478C_9FD7_AB4707A56692__INCLUDED_)
#define AFX_SKINLISTCTRL_H__D3CFCB79_0C15_478C_9FD7_AB4707A56692__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkinListCtrl.h : header file
//

#include "ImgSkin.h"
#include "SkinHeaderCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CSkinListCtrl window

class CSkinHeaderTheme : public CXTHeaderTheme , public CImgSkin
{
public:
	CSkinHeaderTheme();
	virtual ~CSkinHeaderTheme();
	
	virtual void DrawHeader(CDC* pDC, CXTHeaderCtrl* pHeaderCtrl);
};

class CSkinListCtrl : public CXTListCtrl
{
// Construction
public:
	CSkinListCtrl();

	bool LoadSkin(const char * szSkinPath = NULL, const char * szControlName="ListCtrl");

	CXTHeaderCtrl m_header;
	CFont m_sizingFont;
	CFont m_normalFont;
	CSkinHeaderCtrl m_skinHeader;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSkinListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinListCtrl)
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINLISTCTRL_H__D3CFCB79_0C15_478C_9FD7_AB4707A56692__INCLUDED_)
