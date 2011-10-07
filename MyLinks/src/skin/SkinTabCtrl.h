#if !defined(AFX_SKINTABCTRL_H__8C7D6A0B_FCA3_429E_94F7_D46E4743C7DE__INCLUDED_)
#define AFX_SKINTABCTRL_H__8C7D6A0B_FCA3_429E_94F7_D46E4743C7DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkinTabCtrl.h : header file
//

#include "ImgSkin.h"

/////////////////////////////////////////////////////////////////////////////
// CSkinTabCtrl window

class CSkinTabCtrl : public CTabCtrl , public CImgSkin
{
// Construction
public:
	CSkinTabCtrl();

	void CalcItemWidth();

	int m_CurMouseOvr;

// Attributes
public:

// Operations
public:

	bool LoadSkin(const char * szSkinPath /* = NULL */, const char * szControlName="Tab");

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinTabCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSkinTabCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinTabCtrl)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LONG OnMouseLeave(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
		
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINTABCTRL_H__8C7D6A0B_FCA3_429E_94F7_D46E4743C7DE__INCLUDED_)
