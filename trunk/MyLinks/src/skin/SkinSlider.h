#if !defined(AFX_SKINSLIDER_H__93B87D58_37C7_487E_B98F_32EAE3153A7E__INCLUDED_)
#define AFX_SKINSLIDER_H__93B87D58_37C7_487E_B98F_32EAE3153A7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkinSlider.h : header file
//

#include "ImgSkin.h"

/////////////////////////////////////////////////////////////////////////////
// CSkinSlider window

class CSkinSlider : public CSliderCtrl, public CImgSkin
{
// Construction
public:
	CSkinSlider();

	bool m_bDragging;

	void SetPosByPoint(CPoint & Point);
	void SetPos(int nPos);

	bool LoadSkin(const char * szSkinPath /* = NULL */, const char * szControlName="Slider");

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinSlider)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSkinSlider();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinSlider)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINSLIDER_H__93B87D58_37C7_487E_B98F_32EAE3153A7E__INCLUDED_)
