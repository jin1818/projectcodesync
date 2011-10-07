#include ".\webcrawler.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "ext_string.h"
#include <windows.h>

webCrawler::webCrawler(updateViewCallBack callback_)
: callback(callback_)
{
}

webCrawler::~webCrawler(void)
{
}



int webCrawler::saveLinks(WebCrawlerResult& resultList)
{
	std::ifstream ins("booktemple.htm") ;
	if (!ins.is_open())
	{
		return -1 ;
	}

	std::stringstream inss ;
	inss << ins.rdbuf() ;
	
	std::string content ;
	WebCrawlerResult::iterator iter = resultList.begin() ;
	for( ; iter != resultList.end() ; iter++)
	{
		std::ext_string itemContent(inss.str()) ;
		itemContent.replace("$LinkPage$" , iter->szLinkPage ) ;
		itemContent.replace("$MarkPRICE$" , iter->szMarkSalePrice ) ;
		itemContent.replace("$PAYMONEY$" , iter->szPrice ) ;
		content += itemContent ;
		OutputDebugString(itemContent.c_str()) ;
	}


	std::ofstream os(getTargetFile().c_str()) ;
	os.write(content.c_str() , content.size() ) ;
	os.close() ;
	callback(getTargetFile().c_str() , this->getTargetFrame().c_str()) ;
	return 0 ;
}

int webCrawler::showDefaultPage(const char* page)
{
	return callback(page , this->getTargetFrame().c_str()) ;
}
