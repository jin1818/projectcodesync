// AmazonCrawler.cpp: implementation of the CAmazonCrawler class.
//
//////////////////////////////////////////////////////////////////////

#include "AmazonCrawler.h"
#include "urlcodec.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "ext_string.h"
#include <boost/regex.hpp>


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

std::string CAmazonCrawler::reqFormat ="http://www.amazon.cn/s/ref=nb_sb_noss?__mk_zh_CN=%E4%BA%9A%E9%A9%AC%E9%80%8A%E7%BD%91%E7%AB%99&url=search-alias%3Daps&x=8&y=11&field-keywords=" ;

std::string CAmazonCrawler::targetUrl="<a href=\"http://www.amazon.cn/gp/redirect.html?ie=UTF8&location=$URL$&tag=cppentry-23&linkCode=ur2&camp=536&creative=3200\" target=\"_blank\">$NAME$</a><img src=\"http://www.assoc-amazon.cn/e/ir?t=cppentry-23&l=ur2&o=28\" width=\"1\" height=\"1\" border=\"0\" alt=\"\" style=\"border:none !important; margin:0px !important;\" />" ; 

boost::regex amazonexpression("<div class=\"data\">.*?"
				 "<div class=\"title\">.*?"
				 "<a class=\"title\" href=\"(\\S*)/\\S*\">(.*?)</a>.*?"
				 "</div>.*?"
				 "<div class=\"newPrice\">.*?"
				 "<strike>(.*?)</strike><span class=\"price\">(.*?)</span>");

CAmazonCrawler::CAmazonCrawler(updateViewCallBack callback_)
:webCrawler(callback_)
{

}

CAmazonCrawler::~CAmazonCrawler()
{

}

int CAmazonCrawler::getResult(const char* key , WebCrawlerResult& result)
{
	char szReq[1024*10] ={0} ;
	sprintf(szReq , "%s%s" , CAmazonCrawler::reqFormat.c_str() , regUrlEncode(gbk2utf8(key)).c_str()) ;
	std::string str = urlGet(szReq) ;
	if ( str == "")
	{
		return -1 ;
	}

	return getResult_i(str , result) ;
}

int CAmazonCrawler::getResult_i(std::string& pContent , WebCrawlerResult& resultList) 
{
	std::string::const_iterator start, end; 
	start = pContent.begin(); 
    end = pContent.end(); 
    boost::match_results<std::string::const_iterator> what; 
    boost::match_flag_type flags = boost::match_default ; 
	std::string msg ;
    while(regex_search(start, end, what, amazonexpression, flags)) 
	{
		tgWebCrawlerResult result;
		memset(&result , 0 , sizeof(result)) ;
		strncpy(result.szWebSiteName , "Amazon" , sizeof(result.szWebSiteName) - 1) ;

		msg.assign(what[1].first, what[1].second); 
		std::string url = regUrlEncode(msg.c_str()) ;
		strncpy(result.szResultLink , url.c_str() , sizeof(result.szResultLink) - 1 ) ;

		msg.assign(what[2].first, what[2].second); 
		msg = utf82gbk(msg.c_str()) ;
		strncpy(result.szResultName , msg.c_str() , sizeof(result.szResultName) - 1) ;
	
		msg.assign(what[3].first, what[3].second); 
		msg = utf82gbk(msg.c_str()) ;
		strncpy(result.szMarkSalePrice , msg.c_str() , sizeof(result.szMarkSalePrice) - 1) ;

		msg.assign(what[4].first, what[4].second); 
		msg = utf82gbk(msg.c_str()) ;
		strncpy(result.szPrice , msg.c_str() , sizeof(result.szPrice) - 1) ;

		//make page link 
		std::ext_string strLink(CAmazonCrawler::targetUrl) ;
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




