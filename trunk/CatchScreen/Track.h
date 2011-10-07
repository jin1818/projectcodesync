
#if !defined(AFX_TRACK_H__D6A25C36_6F34_42F2_A083_037D8115D8C9__INCLUDED_)
#define AFX_TRACK_H__D6A25C36_6F34_42F2_A083_037D8115D8C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Track.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CTrack frame

class CTrack : public CRectTracker
{
	//DECLARE_DYNCREATE(CTrack)
public:
	CTrack();           // protected constructor used by dynamic creation

// Attributes
public:

		virtual void DrawTrackerRect( LPCRECT lpRect, CWnd* pWndClipTo,
										CDC* pDC, CWnd* pWnd );




// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrack)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTrack();

	// Generated message map functions
	//{{AFX_MSG(CTrack)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRACK_H__D6A25C36_6F34_42F2_A083_037D8115D8C9__INCLUDED_)
