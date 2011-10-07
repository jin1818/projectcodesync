
#include "impl.h"
#include "amazoncrawler.h"
#include ".\dangdangcrawler.h"
#include <afxinet.h>
#include <afx.h>

#ifdef __cpluscplus
extern "C"
{
#endif 

int __stdcall getResult(const char* pKey , updateViewCallBack callback)
{
	WebCrawlerResult amazonResult ;
	CAmazonCrawler * amazonCrawler = new CAmazonCrawler(callback) ;
	amazonCrawler->getResult(pKey , amazonResult) ;
	delete amazonCrawler ;

	WebCrawlerResult dangdangResult ;
	CDangDangCrawler* cdangDangCrawler = new CDangDangCrawler(callback) ;
	cdangDangCrawler->getResult(pKey , dangdangResult) ;
	delete cdangDangCrawler ;

	return 0 ;
}

std::string urlGet(const char* pUrl)
{
	CInternetSession session(__argv[0]);
	CHttpFile *file = NULL; 	
	CString strHtml = "";   //存放网页数据
	char* headers = "User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1;)" ;
	try
	{
		file = (CHttpFile*)session.OpenURL(pUrl , 1 , INTERNET_FLAG_TRANSFER_ASCII , headers , strlen(headers)) ;	
	}
	catch(CInternetException * m_pException){
		file = NULL;
		m_pException->Delete();
		session.Close();	
		return "" ;
	}

	CString strLine;
	
	if(file != NULL)
	{
		while(file->ReadString(strLine) != NULL)
		{	
			strHtml += strLine;	
			//strHtml +="\n" ;
		}
		file->Close();
		delete file;
		file = NULL;
	}
	
	session.Close();
	return std::string(strHtml) ;
}

std::string GetCurrWorkingDir()
{
     CString strPath;
     GetCurrentDirectory(MAX_PATH,strPath.GetBuffer(MAX_PATH));
     strPath.ReleaseBuffer();
     return std::string(strPath);
}

std::string utf82gbk(const char*s)
{
	s = s?s:"";
	std::wstring unicodestr;
	std::string gbkstr;
	//utf8转换成utf16
	int n = MultiByteToWideChar(CP_UTF8, 0, s, -1, NULL, 0);

	unicodestr.resize(n);
	MultiByteToWideChar(CP_UTF8, 0, s, -1, (wchar_t *)unicodestr.c_str(), (int)unicodestr.length());

	//从utf16转gbk
	n = WideCharToMultiByte(936, 0, unicodestr.c_str(), -1, 0, 0, 0, 0 );
	gbkstr.resize(n);
	WideCharToMultiByte(936, 0, unicodestr.c_str(), -1, (char*)gbkstr.c_str(), (int)gbkstr.length(), 0, 0 );

	return gbkstr;
}

std::string gbk2utf8(const char*s)
{
	s = s?s:"";
	std::wstring unicodestr;
	std::string utf8str;
	//gbk转换成utf16
	int n = MultiByteToWideChar(936, 0, s, -1, NULL, 0);

	unicodestr.resize(n);
	MultiByteToWideChar(936, 0, s, -1, (wchar_t *)unicodestr.c_str(), (int)unicodestr.length());
	
	//从utf16转utf8
	n = WideCharToMultiByte(CP_UTF8, 0, unicodestr.c_str(), -1, 0, 0, 0, 0 );
	utf8str.resize(n);
	WideCharToMultiByte(CP_UTF8, 0, unicodestr.c_str(), -1, (char*)utf8str.c_str(), (int)utf8str.length(), 0, 0 );
	
	return utf8str;
}



#ifdef __cpluscplus
}
#endif 

