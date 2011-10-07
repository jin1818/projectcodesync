//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES
#if !defined(AFX_WEATHERDLG_H__3217D4F7_C2DF_470B_8748_6E02680730D4__INCLUDED_)
#define AFX_WEATHERDLG_H__3217D4F7_C2DF_470B_8748_6E02680730D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WeatherDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWeatherDlg dialog

class CWeatherDlg : public CPropertyPage
{
// Construction
public:
	CWeatherDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWeatherDlg)
	enum { IDD = IDD_DIALOG_WEATHER };
	CWebBrowser2	m_ie;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeatherDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWeatherDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEATHERDLG_H__3217D4F7_C2DF_470B_8748_6E02680730D4__INCLUDED_)
