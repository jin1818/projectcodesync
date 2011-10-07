
#ifndef __HTTP_DOWNLOAD_H__
#define __HTTP_DOWNLOAD_H__

#ifdef DOWNLOAD_EXPORTS
#define DOWNLOAD_API __declspec(dllexport)
#else
#define DOWNLOAD_API //__declspec(dllimport)
#endif


#include <afxinet.h>
#include <string>
#include <memory>

using namespace std ;

#ifdef __cpluscplus
extern "C" {
#endif

bool downloadFileFromSession (CHttpFile* fileGet, const string & strWriteFile)
{
	bool rval =false ;
	DWORD dwStatus;
	DWORD dwBuffLen = sizeof(dwStatus);
	BOOL bSuccess = fileGet->QueryInfo (HTTP_QUERY_STATUS_CODE|HTTP_QUERY_FLAG_NUMBER, &dwStatus, &dwBuffLen);
	if (bSuccess && dwStatus >= 200 && dwStatus < 300)
	{
		CStdioFile fileWrite;
		if (fileWrite.Open (strWriteFile.c_str (), CFile::modeWrite|CFile::modeCreate|CFile::typeBinary))
		{
			UINT uCountRead = 0;
			char szBuf[1024] = {0};
			while ((uCountRead = fileGet->Read (szBuf, sizeof (szBuf))) > 0)
			{
				fileWrite.Write (szBuf, uCountRead);
			}
			fileWrite.Close();
			rval =true ;
		}
	}
	return rval ;
}

DOWNLOAD_API bool downloadFile(const string & strURL, const string & strWriteFile)
{
    CInternetSession sess("gb");
    CHttpFile * fileGet = NULL;
	bool rval =false ;
	try
	{
    fileGet = (CHttpFile *)sess.OpenURL (
		strURL.c_str (),
		1,
		INTERNET_FLAG_TRANSFER_BINARY | INTERNET_FLAG_DONT_CACHE | INTERNET_FLAG_RELOAD
		);
	}
	catch(...)
	{
	}
    if (fileGet == NULL) return rval ;

	std::auto_ptr<CHttpFile> apfileGet(fileGet) ;

	rval =downloadFileFromSession(fileGet, strWriteFile) ;    

	fileGet->Close() ;
	delete apfileGet.release() ;
    sess.Close();

    return rval ;
}

#ifdef __cpluscplus
}
#endif


#endif //__HTTP_DOWNLOAD_H__
