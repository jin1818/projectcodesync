// SkinCfg.h: interface for the CSkinCfg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKINCFG_H__902EBED1_0E2D_4BCE_A8A6_232DFC9F1A63__INCLUDED_)
#define AFX_SKINCFG_H__902EBED1_0E2D_4BCE_A8A6_232DFC9F1A63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4786) 
#include <string>
#include <map>
using namespace std;

class CSkinCfg  
{
public:
	CSkinCfg();
	virtual ~CSkinCfg();

	map<string, RECT> m_mapRect;
};

#endif // !defined(AFX_SKINCFG_H__902EBED1_0E2D_4BCE_A8A6_232DFC9F1A63__INCLUDED_)
