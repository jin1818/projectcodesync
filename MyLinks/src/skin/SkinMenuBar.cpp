// SkinMenuBar.cpp: implementation of the CSkinMenuBar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SkinMenuBar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "SkinTheme.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSkinMenuBar::CSkinMenuBar()
{

}

CSkinMenuBar::~CSkinMenuBar()
{

}

bool CSkinMenuBar::LoadSkin(const char * szSkinPath /* = NULL */)
{
	GetDC()->SetBkMode(TRANSPARENT);
	
	CSkinTheme * pTheme = new CSkinTheme(szSkinPath);

	CXTPPaintManager::SetCustomTheme(pTheme);

	RECT rc;
	GetWindowRect(&rc);
	ScreenToClient(&rc);
	rc.bottom = rc.top+pTheme->m_mapRect["Background"].Height;
	MoveWindow(&rc);

	return true;
}
