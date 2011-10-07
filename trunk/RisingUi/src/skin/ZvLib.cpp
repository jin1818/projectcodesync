#include "stdafx.h"
#include "ZvLib.h"

CZvLib::CZvLib()
{

}

CZvLib::~CZvLib()
{

}

void CZvLib::DebugLog(const char * szLog, bool bTime)
{
#ifdef _DEBUG_LOG
	CFile fh;
	if(fh.Open("debug.txt", CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite))
	{
		CString str1;
		if(bTime)
		{
			CTime curTime = CTime::GetCurrentTime();
			str1 = curTime.Format("[%H:%M:%S] ");
		}
		str1+= szLog;
		str1+= "\r\n";
		fh.SeekToEnd();
		fh.Write(str1,str1.GetLength());
		fh.Close();
	}
#endif
}

string CZvLib::GetAppPath()
{
	char buf[MAX_PATH];

	GetModuleFileName(NULL, buf ,MAX_PATH);
	strcpy(strrchr(buf,'\\')+1,"");

	return buf;
}

string CZvLib::GetFileDirPath(const char * szFilePath)
{
	char buf[MAX_PATH];

	strcpy(buf, szFilePath);
	if(strrchr(buf,'\\')!=NULL)
		strcpy(strrchr(buf,'\\')+1,"");
	else
		strcpy(strrchr(buf,'/')+1,"");

	return buf;
}

string CZvLib::GetFileName(const char * szFilePath)
{
	char buf[MAX_PATH];
	
	strcpy(buf, szFilePath);
	if(strrchr(buf,'\\')!=NULL)
		return strrchr(buf,'\\')+1;
	else if(strrchr(buf,'/')!=NULL)
		return strrchr(buf,'/')+1;
	else
		return szFilePath;
}

string CZvLib::GetExeName()
{
	char buf[MAX_PATH];

	GetModuleFileName(NULL, buf ,MAX_PATH);
	strcpy(buf, strrchr(buf,'\\')+1);

	return buf;
}

BOOL CZvLib::DeleteTree(CString fileName)
{
	CFileFind ff;
	BOOL r;

	if(fileName.Right(1)=="\\")
		fileName.SetAt(fileName.GetLength()-1, 0);

	r = ff.FindFile(fileName);

	while(r)
	{	
		r = ff.FindNextFile();
		if(!ff.IsDots())
		{
			if(ff.IsDirectory())
			{
				if(!DeleteTree(ff.GetFilePath()+"\\*.*"))
					return FALSE;
				if(!RemoveDirectory(ff.GetFilePath()))
					return FALSE;
			}
			else
			{
				if(!DeleteFile(ff.GetFilePath()))
					return FALSE;
			}
		}
	}
	return TRUE;	
}

void CZvLib::SplitString(const char * szStr, const char * szSplitter, vector<string> & vtStr, const char * szEndStr)
{
	string str = szStr;
	string strSplitter = szSplitter;

	size_t i,j;
	size_t l=strSplitter.size();

	i = j = 0;
	string strSub;
	size_t k = szEndStr==NULL?str.npos:str.find(szEndStr);

	vtStr.clear();

	while(1)
	{
		j = str.find(szSplitter, i);
		if(j>k)
			j=k;
		strSub = str.substr(i,j-i);
		if(strSub.size()>0)
			vtStr.push_back(strSub);
		i=j+l;
		if(j==str.npos || j>=k)
			break;
	}
}

void CZvLib::SplitString(const char * szStr, const char * szSplitter, vector<CString> & vtStr, const char * szEndStr)
{
	string str = szStr;
	string strSplitter = szSplitter;

	size_t i,j;
	size_t l=strSplitter.size();

	i = j = 0;
	string strSub;
	size_t k = szEndStr==NULL?str.npos:str.find(szEndStr);

	vtStr.clear();

	while(1)
	{
		j = str.find(szSplitter, i);
		if(j>k)
			j=k;
		strSub = str.substr(i,j-i);
		if(strSub.size()>0)
			vtStr.push_back(strSub.c_str());
		i=j+l;
		if(j==str.npos || j>=k)
			break;
	}
}

CTime CZvLib::SecondsToTime(int nSecs)
{
	int nHour, nMin, nSec;
	nHour = nSecs/3600;
	nMin = (nSecs-nHour*3600)/60;
	nSec = nSecs-nHour*3600-nMin*60;
	return CTime(2007, 7, 26, nHour, nMin, nSec);	
}

int CZvLib::TimeToSeconds(CTime & tm)
{
	return tm.GetHour()*3600+tm.GetMinute()*60+tm.GetSecond();
}

bool CZvLib::StringContainChars(string & szStr, string & szChars)
{
	int len = szChars.size();

	for(int i=0; i<len; i++)
	{
		if(szStr.find(szChars[i])!=szChars.npos)
			return true;
	}
	return false;
}

bool CZvLib::StringIsChar(string & szStr)
{
	int len = szStr.size();

	for(int i=0; i<len; i++)
	{
		if(!((szStr[i]>='0'&&szStr[i]<='9')||
			(szStr[i]>='a'&&szStr[i]<='z')||
			(szStr[i]>='A'&&szStr[i]<='Z')))
			return false;
	}
	return true;
}

bool CZvLib::SetAutoRun(bool bEnable /* = true */)
{
	char FilePath[MAX_PATH];
	GetModuleFileName(NULL,FilePath,MAX_PATH);
	
	string str = CZvLib::GetExeName();

	CRegistry reg;
	if(reg.Open("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"))
	{
		reg.DeleteKey(reg.m_hKey, str.c_str());
		
		if(bEnable)
		{
			reg.Write(str.c_str(), FilePath);
		}

		return true;
	}
	
	return false;
}

bool CZvLib::IsAutoRun()
{
	CString szStr;
	string str = CZvLib::GetExeName();
	szStr = str.c_str();
	
	CRegistry reg;
	if(reg.Open("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"))
	{
		if(reg.Read(szStr, &szStr))
			return true;
	}
	
	return false;
}

bool CZvLib::MakeDirectory(const char * szPath)
{
	int index, start = 0;
	CString strTmp;  
	CString strPath = szPath;
	strPath.Replace("/","\\");
	
	while((index = strPath.Find('\\', start)) != -1)
	{  
		strTmp = strPath.Left(index);
		CreateDirectory(strTmp,   NULL);  
		start = index + 1;
	}  
	
	if(strPath.GetLength() != strTmp.GetLength()+1)
		CreateDirectory(strPath, NULL);

	if(GetFileAttributes(szPath)==0xFFFFFFFF)
		return false;

	return true;
}

bool CZvLib::FileExists(const char * szPath)
{
	return  GetFileAttributes(szPath)!=0xFFFFFFFF;
}

CString CZvLib::GuidToString(const GUID & guid)
{
	CString str;
	str.Format("{%08lX-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X}", 		
		guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
		guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);
	return str;
}

void CZvLib::MsgWaitThread(CWinThread * pThread, DWORD dwTimeout)
{
	if(pThread==NULL)
		return;

	DWORD dwTickEnd;
	DWORD dwTickCur;

	if(dwTimeout!=INFINITE)
		dwTickEnd = GetTickCount()+dwTimeout;
	else 
		dwTickEnd = INFINITE;

	while(1)
	{	
		dwTickCur = GetTickCount();

		if(dwTickCur>dwTickEnd)
		{
			TerminateThread(pThread->m_hThread, 0);
			break;
		}

		DWORD result ;
		MSG msg ;
		result = MsgWaitForMultipleObjects(1, &pThread->m_hThread, FALSE, dwTickEnd-dwTickCur, QS_ALLINPUT);
		if (result == WAIT_OBJECT_0)
		{
			break;
		}
		else
		{
			PeekMessage (&msg, NULL, 0, 0, PM_REMOVE);
			DispatchMessage(&msg);
		} 
	}
}

void CZvLib::WaitThread(CWinThread * pThread, DWORD dwTimeout)
{
	if(pThread==NULL)
		return;

	if(WaitForSingleObject(pThread->m_hThread, dwTimeout)!=WAIT_OBJECT_0)
	{
		TerminateThread(pThread->m_hThread, 0);
	}
}