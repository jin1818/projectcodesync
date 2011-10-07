#ifndef ERROR_H
#define ERROR_H


class CError
{
public:

	CError();
	~CError();

	void SetErr(const char * szErr = NULL, ...);
	virtual void MsgErr(const char * szErr = NULL, ...);
	virtual void MsgInfo(const char * szErr = NULL, ...);
	virtual void MsgWarning(const char * szErr = NULL, ...);

	const char * GetErr();

	virtual void msg(const char * szMsg = NULL, DWORD dwMsgType = MB_ICONERROR , int nTime = -1 );
	void SetWinErr(const char * szPre, ...);
public:
	static CRITICAL_SECTION m_csErrMsg;
	static CString m_szErrMsg;
	static bool m_bCsInited;
};

#endif