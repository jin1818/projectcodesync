// SkinButton.h: interface for the CSkinButton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKINBUTTON_H__7F53EB28_37C2_4854_A2B2_17E4B202BE56__INCLUDED_)
#define AFX_SKINBUTTON_H__7F53EB28_37C2_4854_A2B2_17E4B202BE56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgSkin.h"

class CSkinButton : public CBitmapButton , public CImgSkin 
{
	DECLARE_DYNAMIC(CSkinButton);

	int m_nStyle;
	int m_nState;

	// Construction
public:
	CSkinButton();
	void SetToolTipText(const char * spText, BOOL bActivate = TRUE);
	void SetToolTipText(int nId, BOOL bActivate = TRUE);

// Attributes
protected:
	void ActivateTooltip(BOOL bActivate = TRUE);
	BOOL m_bHover;						// indicates if mouse is over the button
	CSize m_ButtonSize;					// width and height of the button
	CBitmap mybitmap;
	BOOL m_bTracking;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinButton)
	protected:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL LoadSkin(const char * szSkinPath, const char * szControlName="Button");
	virtual ~CSkinButton();

	// Generated message map functions
protected:
	CToolTipCtrl m_ToolTip;
	void InitToolTip();
	//{{AFX_MSG(CSkinButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wparam, LPARAM lparam);
	afx_msg LRESULT OnMouseHover(WPARAM wparam, LPARAM lparam);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};

#endif // !defined(AFX_SKINBUTTON_H__7F53EB28_37C2_4854_A2B2_17E4B202BE56__INCLUDED_)
