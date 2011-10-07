// CSLock.h: interface for the CCSLock class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CSLOCK_H__03E993E1_0881_4442_9C49_50E93E7451CC__INCLUDED_)
#define AFX_CSLOCK_H__03E993E1_0881_4442_9C49_50E93E7451CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCSLock
{
public:
	CCSLock();
	CCSLock(LPCRITICAL_SECTION lpCs);
	virtual ~CCSLock();

	LPCRITICAL_SECTION m_lpCs;

	void Lock();
	void Unlock();
};

#endif // !defined(AFX_CSLOCK_H__03E993E1_0881_4442_9C49_50E93E7451CC__INCLUDED_)
