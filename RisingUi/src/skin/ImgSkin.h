// ImgSkin.h: interface for the CImgSkin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMGSKIN_H__8882817A_8CFF_4DE2_8FCF_5DA2D3628DA4__INCLUDED_)
#define AFX_IMGSKIN_H__8882817A_8CFF_4DE2_8FCF_5DA2D3628DA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "./GDIPlus/Includes/GdiPlus.h"
// #pragma comment(lib, "./GDIPlus/Lib/GdiPlus.lib")
using namespace Gdiplus;

#pragma warning(disable:4786) 
#include <string>
#include <map>
//using namespace std;

#include "tinyxml/tinyxml.h"
#include "Error.h"

class CImgSkin : virtual public CError
{
public:
	CImgSkin();
	virtual ~CImgSkin();

	bool Load(const char * szPath, const char * szControlType);
	void Unload();
	bool IsLoaded();

	static Image * m_pImg;
	std::map<std::string, Rect> m_mapRect;
	std::map<std::string, COLORREF> m_mapColor;
	CString m_szSkinPath;
};

#endif // !defined(AFX_IMGSKIN_H__8882817A_8CFF_4DE2_8FCF_5DA2D3628DA4__INCLUDED_)
