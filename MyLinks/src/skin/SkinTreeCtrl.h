#if !defined(AFX_SKINTREECTRL_H__6E54B950_944C_485F_8D2F_10D94F6FF195__INCLUDED_)
#define AFX_SKINTREECTRL_H__6E54B950_944C_485F_8D2F_10D94F6FF195__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkinTreeCtrl.h : header file
//

#include "ImgSkin.h"

/////////////////////////////////////////////////////////////////////////////
// CSkinTreeCtrl window

class CSkinTreeCtrl : public CTreeCtrl, public CImgSkin
{
// Construction
public:
	CSkinTreeCtrl();

	HTREEITEM FindItemByData(HTREEITEM hItem, DWORD dwData);
	HTREEITEM FindItemByPoint(HTREEITEM hItem, CPoint pnt);
	HTREEITEM ExpandAllItem(HTREEITEM hItemStart, UINT nCode);

	bool IsForder(HTREEITEM hItem);

	bool LoadSkin(const char * szPath, const char * szType = "TreeCtrl");

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinTreeCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSkinTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinTreeCtrl)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINTREECTRL_H__6E54B950_944C_485F_8D2F_10D94F6FF195__INCLUDED_)
