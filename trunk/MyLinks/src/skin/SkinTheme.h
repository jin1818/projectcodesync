// SkinTheme.h: interface for the CSkinTheme class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKINTHEME_H__2E799901_89FB_4014_97AC_6F24FB92C1DB__INCLUDED_)
#define AFX_SKINTHEME_H__2E799901_89FB_4014_97AC_6F24FB92C1DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgSkin.h"

class CSkinTheme : public CXTPDefaultTheme, public CImgSkin
{
public:
	CSkinTheme(const char * szSkinPath);
	virtual ~CSkinTheme();

	virtual void FillCommandBarEntry(CDC* pDC, CXTPCommandBar* pBar);
	virtual CRect GetCommandBarBorders(CXTPCommandBar* pBar);
	virtual CSize DrawControlToolBarParent(CDC* pDC, CXTPControl* pButton, BOOL bDraw);
	virtual void DrawControlEntry(CDC* pDC, CRect rc, BOOL bEnabled, BOOL bSelected, BOOL bPressed, BOOL bChecked, BOOL bPopuped, XTPBarPosition barPosition);
	virtual CSize DrawControlPopupParent(CDC* pDC, CXTPControl* pButton, BOOL bDraw);
	bool LoadSkin(const char * szSkinPath = NULL);
};

#endif // !defined(AFX_SKINTHEME_H__2E799901_89FB_4014_97AC_6F24FB92C1DB__INCLUDED_)
