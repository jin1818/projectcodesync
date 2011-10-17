// TBADView.h : interface of the CTBADView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TBADVIEW_H__1C1A2F3E_7CB3_45DA_8BF6_C43CB8520DBE__INCLUDED_)
#define AFX_TBADVIEW_H__1C1A2F3E_7CB3_45DA_8BF6_C43CB8520DBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTBADView : public CHtmlView
{
protected: // create from serialization only
	CTBADView();
	DECLARE_DYNCREATE(CTBADView)

// Attributes
public:
	CTBADDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTBADView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct

	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTBADView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTBADView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnParentNotify( UINT message, LPARAM lParam ); 
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TBADView.cpp
inline CTBADDoc* CTBADView::GetDocument()
   { return (CTBADDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TBADVIEW_H__1C1A2F3E_7CB3_45DA_8BF6_C43CB8520DBE__INCLUDED_)
