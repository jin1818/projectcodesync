#pragma once

#include "impl.h"
#include <string>

class webCrawler
{
public:
	webCrawler(updateViewCallBack callback_);
	~webCrawler(void);
protected :
	virtual int saveLinks(WebCrawlerResult& resultList) ;

	virtual int showDefaultPage(const char* page) ;

	virtual std::string getTargetFrame() = 0 ;
	virtual std::string getTargetFile() = 0 ;  

private :
	updateViewCallBack callback ;
};
