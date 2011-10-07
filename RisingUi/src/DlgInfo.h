#if !defined(AFX_DLGINFO_H__E618E67F_166E_4FF2_9AC7_C6EB280453E4__INCLUDED_)
#define AFX_DLGINFO_H__E618E67F_166E_4FF2_9AC7_C6EB280453E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgInfo.h : header file
//

#include "skin/SkinDialog.h"
#include "skin/CxStatic.h"
#include "skin/SkinSlider.h"
#include "skin/SkinButton.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgInfo dialog

class CDlgInfo : public CSkinDialog
{
// Construction
public:
	CDlgInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgInfo)
	enum { IDD = IDD_Info };
	CSkinButton	m_btnUpdate;
	CSkinButton	m_btnPro;
	CSkinButton	m_btnKill;
	CSkinSlider	m_slider;
	CxStatic	m_txtTarget;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnKill();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINFO_H__E618E67F_166E_4FF2_9AC7_C6EB280453E4__INCLUDED_)
