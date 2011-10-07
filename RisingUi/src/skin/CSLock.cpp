// CSLock.cpp: implementation of the CCSLock class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CSLock.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCSLock::CCSLock(LPCRITICAL_SECTION lpCs)
{
	m_lpCs = lpCs;
	Lock();
}

CCSLock::~CCSLock()
{
	Unlock();
}

void CCSLock::Lock()
{
	EnterCriticalSection(m_lpCs);
}

void CCSLock::Unlock()
{
	LeaveCriticalSection(m_lpCs);
}
