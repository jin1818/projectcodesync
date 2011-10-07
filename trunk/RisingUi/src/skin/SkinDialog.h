#if !defined(AFX_SKINDIALOG_H__A1057FB5_582E_409D_A7C1_13A5F9A73FEF__INCLUDED_)
#define AFX_SKINDIALOG_H__A1057FB5_582E_409D_A7C1_13A5F9A73FEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkinDialog.h : header file
//

#include "ImgSkin.h"
#include "anchor.h"
#include "SkinMenuBar.h"

/////////////////////////////////////////////////////////////////////////////
// CSkinDialog dialog

class CSkinDialog : public CXTPDialog, public CImgSkin, public CXTResize
{
// Construction
public:
	// CSkinDialog(CWnd* pParent = NULL);   // standard constructor
	CSkinDialog(UINT uResourceID, CWnd* pParent = NULL, bool bIgnoreCancelKey = true);

	bool LoadSkin(const char * szSkinPath = NULL, const char * szControlName="Dialog");

	bool AddAnchor(UINT nID, UINT nFlag);
	bool AddAnchor(HWND hwnd, UINT nFlag);

	virtual void OnPressOkCancel();

	int GetSysButtonsHitTest(CPoint point);
	void DrawFrame(Graphics & graphics);
	bool HasStyle(DWORD dwStyle);

	void InitMenuBar();

	CSkinMenuBar m_wndMenuBar;

	CDlgAnchor m_anchor;
	bool m_bActive;
	bool m_bIgnoreCancelKey;

	CRect m_rcClient;

	DWORD m_dwStyle;

	int m_nButtonMove;
	int m_nButtonDown;

	enum
	{
		HT_CLOSE = 0,
		HT_MIN,
		HT_MAX
	};

public:

// Dialog Data
	//{{AFX_DATA(CSkinDialog)
	//enum { IDD = _UNKNOWN_RESOURCE_ID_ };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinDialog)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSkinDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnNcPaint();
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg UINT OnNcHitTest(CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINDIALOG_H__A1057FB5_582E_409D_A7C1_13A5F9A73FEF__INCLUDED_)
