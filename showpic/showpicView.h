// showpicView.h : interface of the CShowpicView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWPICVIEW_H__D679A234_EAF8_455F_8267_64DEB1606DEE__INCLUDED_)
#define AFX_SHOWPICVIEW_H__D679A234_EAF8_455F_8267_64DEB1606DEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowpicView : public CHtmlView
{
protected: // create from serialization only
	CShowpicView();
	DECLARE_DYNCREATE(CShowpicView)

// Attributes
public:
	CShowpicDoc* GetDocument();


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowpicView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowpicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowpicView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in showpicView.cpp
inline CShowpicDoc* CShowpicView::GetDocument()
   { return (CShowpicDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWPICVIEW_H__D679A234_EAF8_455F_8267_64DEB1606DEE__INCLUDED_)
