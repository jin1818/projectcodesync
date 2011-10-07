
#ifndef __WEB_CRAWLER_IMPL_H__
#define __WEB_CRAWLER_IMPL_H__

#include <list>
#include <string>

#define MAX_RESULT_URL_LEN 1024 * 8

#ifndef MAX_PATH
#define MAX_PATH 260
#endif 

struct tgWebCrawlerResult 
{
	char szWebSiteName[32] ;
	char szResultName[MAX_RESULT_URL_LEN] ;
	char szResultLink[MAX_RESULT_URL_LEN] ;
	char szPrice[32] ;
	char szMarkSalePrice[32] ;
	char szLinkPage[MAX_RESULT_URL_LEN] ;
} ;

typedef std::list<tgWebCrawlerResult> WebCrawlerResult ;
typedef int (*updateViewCallBack)(const char* pUrl , const char* pFrame) ;

#ifdef WEBCRAWLERDLL_EXPORTS
#define MYLIBAPI __declspec(dllexport)
#else
#define MYLIBAPI __declspec(dllimport)
#endif

#ifdef __cpluscplus
extern "C"
{
#endif 


	MYLIBAPI  int __stdcall getResult(const char* pKey , updateViewCallBack callback) ;

	std::string urlGet(const char* pUrl) ;

	std::string GetCurrWorkingDir() ;

	std::string utf82gbk(const char*s) ;

	std::string gbk2utf8(const char*s) ;

#ifdef __cpluscplus
}
#endif 

#endif //__WEB_CRAWLER_IMPL_H__

