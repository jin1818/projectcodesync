#include ".\dangdangcrawler.h"
#include "urlcodec.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "ext_string.h"

#include <boost/regex.hpp>

std::string CDangDangCrawler::reqFormat ="http://search.dangdang.com/search.php?key=%s" ;

std::string CDangDangCrawler::reSearchUrlFormat="<script>window.location.href='(.*?)'</script>" ;


std::string CDangDangCrawler::targetUrl ="<a href=\"http://union.dangdang.com/transfer.php?from=P-285531&ad_type=10&sys_id=1&backurl=$URL$ \" target=\"_bank\">$NAME$</a>" ;

boost::regex expression("<div class=\"listitem pic\".*?>"
						"<a.*?href=\"(\\S*)\".*?\"><img class=\"lazy_img\" src=\"(\\S*)\" alt=\"(.*?)\".*?/></a>"
						".*?"
						"<div class=\"panel price\">"
						"<span class=\"price_d\">гд<span class=\"num\">(\\S*)</span></span><span class=\"price_m\">гд<span class=\"num\">(\\S*)</span></span>") ; 


CDangDangCrawler::CDangDangCrawler(updateViewCallBack callback_)
: webCrawler(callback_)
{
}

CDangDangCrawler::~CDangDangCrawler(void)
{
}

int CDangDangCrawler::getResult(const char* key , WebCrawlerResult& result)
{
	char szReq[1024] ={0} ;
	sprintf(szReq ,CDangDangCrawler::reqFormat.c_str() , regUrlEncode(std::string(key)).c_str()) ;
	std::string str = urlGet(szReq) ;
	if ( "" == str )
	{
		return -1 ;
	}

	str = doReSearch(str) ;
	
	return getResult_i(str , result) ;
}

int CDangDangCrawler::getResult_i(std::string& pContent , WebCrawlerResult& resultList ) 
{
	std::string::const_iterator start, end; 
	start = pContent.begin(); 
    end = pContent.end(); 
    boost::match_results<std::string::const_iterator> what; 
    boost::match_flag_type flags = boost::match_default ; 
	std::string msg ;
    while(regex_search(start, end, what, expression, flags)) 
	{
		tgWebCrawlerResult result;
		strncpy(result.szWebSiteName , "DangDang" , sizeof(result.szWebSiteName) - 1) ;

		msg.assign(what[1].first, what[1].second); 
		strncpy(result.szResultLink , msg.c_str() , sizeof(result.szResultLink) - 1 ) ;

		msg.assign(what[3].first, what[3].second); 
		strncpy(result.szResultName , msg.c_str() , sizeof(result.szResultName) - 1) ;

		msg.assign(what[4].first, what[5].second); 
		strncpy(result.szPrice , msg.c_str() , sizeof(result.szPrice) - 1) ;

		msg.assign(what[5].first, what[5].second); 
		strncpy(result.szMarkSalePrice , msg.c_str() , sizeof(result.szPrice) - 1) ;

		//make page link 
		std::ext_string strLink(CDangDangCrawler::targetUrl) ;
		strLink.replace("$URL$" , result.szResultLink) ;
		strLink.replace("$NAME$" , result.szResultName) ;
		strncpy(result.szLinkPage , strLink.c_str() , sizeof(result.szLinkPage) - 1) ;

		resultList.push_back(result) ;

		start = what[0].second; 
	}
	if ( resultList.size() > 0 )
	{
		saveLinks(resultList) ;
	}
	else
	{
		showDefaultPage("") ;
	}
	return 0 ;
}

std::string CDangDangCrawler::doReSearch(std::string& strSearchResult)
{
	std::string msg ;
	std::string::const_iterator start, end; 

	boost::regex reSearchExpression(CDangDangCrawler::reSearchUrlFormat.c_str()) ;

	start = strSearchResult.begin(); 
    end = strSearchResult.end(); 
    boost::match_results<std::string::const_iterator> what; 
    boost::match_flag_type flags = boost::match_default ; 
    while(regex_search(start, end, what, reSearchExpression, flags)) 
	{
		msg.assign(what[1].first, what[1].second); 
		return urlGet(msg.c_str()) ;
	}
	return strSearchResult ;
}
