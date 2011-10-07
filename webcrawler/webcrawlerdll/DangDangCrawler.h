#pragma once

#include "webCrawler.h"

class CDangDangCrawler : public webCrawler 
{
public:
	CDangDangCrawler(updateViewCallBack callback_);
	~CDangDangCrawler(void);

	int getResult(const char* key , WebCrawlerResult& result ) ;

protected:
	int getResult_i(std::string& pContent , WebCrawlerResult& result) ;

	std::string doReSearch(std::string& strSearchResult) ;
	
	virtual std::string getTargetFrame()
	{
		return "dangdangwang" ;
	}
	virtual std::string getTargetFile() 
	{
		return GetCurrWorkingDir() + "/dangdangwang.htm" ;
	}
private :
	static std::string reqFormat ;
	static std::string targetUrl ;
	static std::string reSearchUrlFormat ;
};
