#include "StdAfx.h"
#include "CSLock.h"
#include "Error.h"


CString CError::m_szErrMsg = "";
CRITICAL_SECTION CError::m_csErrMsg = {0};
bool CError::m_bCsInited = false;

CError::CError(void)
{
	if(!m_bCsInited)
	{
		InitializeCriticalSection(&m_csErrMsg);
		m_bCsInited = true;
	}
}

CError::~CError(void)
{
	// DeleteCriticalSection(&m_csErrMsg);
}

void CError::SetWinErr(const char * szPre, ...)
{
	CCSLock lock(&m_csErrMsg);

	va_list args;
	va_start(args, szPre);
	m_szErrMsg.FormatV(szPre, args);

	m_szErrMsg+=":";

	LPVOID lpMsgBuf;
	FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM | 
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0,
		NULL );
	m_szErrMsg += (char*)lpMsgBuf;
	LocalFree( lpMsgBuf );
	return;
}

void CError::SetErr(const char * szErr, ...)
{
	CCSLock Lock(&m_csErrMsg);

	if(szErr==NULL)
	{
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR) &lpMsgBuf,
			0,
			NULL );
		m_szErrMsg = (char*)lpMsgBuf;
		LocalFree( lpMsgBuf );
		return;
	}
	
	va_list args;
	va_start(args, szErr);
	m_szErrMsg.FormatV(szErr, args);

}

void CError::MsgErr(const char * szErr /* = NULL */, ...)
{
	CString str;
	if(szErr!=NULL)
	{
		va_list args;
		va_start(args, szErr);
		str.FormatV(szErr, args);
	}
	else
		str = GetErr();

	SetErr(str);

	msg(str);
}


void CError::MsgWarning(const char * szErr /* = NULL */, ...)
{
	CString str;
	if(szErr!=NULL)
	{
		va_list args;
		va_start(args, szErr);
		str.FormatV(szErr, args);
	}
	else
		str = GetErr();

	SetErr(str);

	msg(str, MB_ICONWARNING);
}


void CError::MsgInfo(const char * szErr /* = NULL */, ...)
{
	CString str;
	if(szErr!=NULL)
	{
		va_list args;
		va_start(args, szErr);
		str.FormatV(szErr, args);
	}
	else
		str = GetErr();

	SetErr(str);

	msg(str, MB_ICONINFORMATION);
}


const char * CError::GetErr()
{
	CCSLock Lock(&m_csErrMsg);

	return m_szErrMsg.GetBuffer(m_szErrMsg.GetLength());
}

void CError::msg(const char * StrMsg, DWORD dwMsgType, int Time)
{
	AfxMessageBox(StrMsg, dwMsgType);
}
