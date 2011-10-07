// SkinMenuBar.h: interface for the CSkinMenuBar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKINMENUBAR_H__69441EC9_0D4B_4926_A2E8_753A60293E47__INCLUDED_)
#define AFX_SKINMENUBAR_H__69441EC9_0D4B_4926_A2E8_753A60293E47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgSkin.h"
#include <XTToolkitPro.h>

class CSkinMenuBar : public CXTPMenuBar
{
public:
	CSkinMenuBar();
	virtual ~CSkinMenuBar();
	
	bool LoadSkin(const char * szSkinPath = NULL);
};

#endif // !defined(AFX_SKINMENUBAR_H__69441EC9_0D4B_4926_A2E8_753A60293E47__INCLUDED_)
