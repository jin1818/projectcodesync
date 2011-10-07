#if !defined(AFX_SKINHEADERCTRL_H__9063A767_6202_49AF_BCE8_E51D0C383EA8__INCLUDED_)
#define AFX_SKINHEADERCTRL_H__9063A767_6202_49AF_BCE8_E51D0C383EA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkinHeaderCtrl.h : header file
//

#include "ImgSkin.h"

/////////////////////////////////////////////////////////////////////////////
// CSkinHeaderCtrl window

class CSkinHeaderCtrl : public CXTHeaderCtrl, public CImgSkin
{
// Construction
public:
	CSkinHeaderCtrl();

// Attributes
public:

// Operations
public:
	bool LoadSkin(const char * szSkinPath = NULL, const char * szControlName = "HeaderCtrl");

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinHeaderCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSkinHeaderCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinHeaderCtrl)
		// NOTE - the ClassWizard will add and remove member functions here.
	LRESULT OnLayout( WPARAM wParam, LPARAM lParam );
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINHEADERCTRL_H__9063A767_6202_49AF_BCE8_E51D0C383EA8__INCLUDED_)
