// AmazonCrawler.h: interface for the CAmazonCrawler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AMAZONCRAWLER_H__E13639B8_816D_41DF_A152_D6E867CF1A15__INCLUDED_)
#define AFX_AMAZONCRAWLER_H__E13639B8_816D_41DF_A152_D6E867CF1A15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "webCrawler.h"

class CAmazonCrawler  : public webCrawler 
{
public:
	CAmazonCrawler(updateViewCallBack callback_);
	virtual ~CAmazonCrawler();

	int getResult(const char* key , WebCrawlerResult& result ) ;

protected:
	int getResult_i(std::string& pContent , WebCrawlerResult& result) ;

	virtual std::string getTargetFrame()
	{
		return "amazon" ;
	}
	virtual std::string getTargetFile() 
	{
		return GetCurrWorkingDir() + "/amazon.htm" ;
	}

private :
	static std::string reqFormat ;
	static std::string targetUrl ;
};

#endif // !defined(AFX_AMAZONCRAWLER_H__E13639B8_816D_41DF_A152_D6E867CF1A15__INCLUDED_)
