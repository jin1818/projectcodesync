#ifndef ZVLIB_H
#define ZVLIB_H

#pragma warning(disable:4786) 
#include <vector>
#include <iostream>
#include <string>
using namespace std;

#include "Registry.h"

class CZvLib  
{
public:
	CZvLib();
	virtual ~CZvLib();

	static string GetFileDirPath(const char * szFilePath);
	static string GetFileName(const char * szFilePath);
	static string GetExeName();
	static string GetAppPath();
	static void DebugLog(const char * szLog, bool bTime=true);
	static void SplitString(const char * szStr, const char * szSplitter, vector<string> & vtStr, const char * szEndStr=NULL);
	static void SplitString(const char * szStr, const char * szSplitter, vector<CString> & vtStr, const char * szEndStr=NULL);
	static CTime SecondsToTime(int nSec);
	static int TimeToSeconds(CTime & tm);
	static bool StringContainChars(string & szStr, string & szChars);
	static bool StringIsChar(string & szStr);
	static BOOL DeleteTree(CString fileName);

	static bool SetAutoRun(bool bEnable = true);
	static bool IsAutoRun();
	static bool MakeDirectory(const char * szPath);
	static bool FileExists(const char * szPath);
	static CString GuidToString(const GUID & guid);

	static void MsgWaitThread(CWinThread * pThread, DWORD dwTimeout = 2000);
	static void WaitThread(CWinThread * pThread, DWORD dwTimeout = 2000);
};

#endif