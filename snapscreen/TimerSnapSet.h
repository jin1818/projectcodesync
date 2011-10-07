#if !defined(AFX_TIMERSNAPSET_H__14D2018E_13E9_4F0A_841E_DA7090EFC17F__INCLUDED_)
#define AFX_TIMERSNAPSET_H__14D2018E_13E9_4F0A_841E_DA7090EFC17F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TimerSnapSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TimerSnapSet dialog

class TimerSnapSet : public CDialog
{
// Construction
public:
	TimerSnapSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TimerSnapSet)
	enum { IDD = IDD_DIALOG_TIMERSNAP_SET };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TimerSnapSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TimerSnapSet)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMERSNAPSET_H__14D2018E_13E9_4F0A_841E_DA7090EFC17F__INCLUDED_)
