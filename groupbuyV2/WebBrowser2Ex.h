// WebBrowser2Ex.h: interface for the CWebBrowser2Ex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WEBBROWSER2EX_H__21EF441D_BE98_47F3_8C88_2412B3D0ED54__INCLUDED_)
#define AFX_WEBBROWSER2EX_H__21EF441D_BE98_47F3_8C88_2412B3D0ED54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "WebBrowser2.h"

class CWebBrowser2Ex : public CWebBrowser2 
{
public:
	CWebBrowser2Ex();
	virtual ~CWebBrowser2Ex();
public :
	void Navigate(LPCTSTR URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers)
	{
		CString currUrl = GetLocationURL() ;
		slForward.RemoveAll(); // empty forward list
		if (!currUrl.IsEmpty()) 
		{
			slBackward.AddHead(currUrl); // add the url that you were just on
		}
		resetProcess() ;
		CWebBrowser2::Navigate(URL,Flags,TargetFrameName,PostData,Headers);
	}
	void GoBack()
	{
		if (slBackward.GetCount()>0)
		{
			slForward.AddHead(GetLocationURL()); // add current to forward list
			CWebBrowser2::GoBack();
			slBackward.RemoveHead();
		}
	}
	
	void GoForward()
	{
		if (slForward.GetCount()>0)
		{
			slBackward.AddHead(GetLocationURL()); // add current to forward list
			CWebBrowser2::GoForward();
			slForward.RemoveHead();
		}
	}

	void resetProcess() ;
private :
	CStringList slBackward,slForward; // a list for forward and backward used for the menus etc 
};

#endif // !defined(AFX_WEBBROWSER2EX_H__21EF441D_BE98_47F3_8C88_2412B3D0ED54__INCLUDED_)
