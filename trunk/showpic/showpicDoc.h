// showpicDoc.h : interface of the CShowpicDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWPICDOC_H__84141380_FD29_45D6_8849_77F004CCDC83__INCLUDED_)
#define AFX_SHOWPICDOC_H__84141380_FD29_45D6_8849_77F004CCDC83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowpicDoc : public CDocument
{
protected: // create from serialization only
	CShowpicDoc();
	DECLARE_DYNCREATE(CShowpicDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowpicDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowpicDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowpicDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWPICDOC_H__84141380_FD29_45D6_8849_77F004CCDC83__INCLUDED_)
