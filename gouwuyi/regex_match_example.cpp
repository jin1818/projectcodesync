/*
 *
 * Copyright (c) 1998-2002
 * John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 */

 /*
  *   LOCATION:    see http://www.boost.org for most recent version.
  *   FILE         regex_match_example.cpp
  *   VERSION      see <boost/version.hpp>
  *   DESCRIPTION: ftp based regex_match example.
  */
  
#include <cstdlib>
#include <stdlib.h>
#include <boost/regex.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace boost;

//regex expression("^([0-9]+)(\\-| |$)(.*)$");
regex expression("<div class=\"data\">.*?"
				 "<div class=\"title\">.*?"
				 "<a class=\"title\" href=\"(\\S*)/\\S*\">(.*?)</a>.*?"
				 "<span class=\"ptBrand\">(.*?)</span>(.*?)"
				 "<span class=\"ptBrand\">(.*?)</span>(.*?)"
				 "<span class=\"bindingAndRelease\">(.*?)</span>"
				 "(.*?)</div>(.*?)"
				 "<div class=\"newPrice\">(.*?)"
				 "(.*?)<strike>(.*?)</strike><span class=\"price\">(.*?)</span>");
				
#include<iostream>
#include<iconv.h>
int utf8togb2312(const char *sourcebuf,size_t sourcelen,char *destbuf,size_t destlen)
{
  iconv_t cd;
  if( (cd = iconv_open("gb2312","utf-8")) ==0 )
    return -1;
  memset(destbuf,0,destlen);
  const char **source = &sourcebuf;
  char **dest = &destbuf;
  if(-1 == iconv(cd,const_cast<char**>(source),&sourcelen,dest,&destlen))
    return -1;
  iconv_close(cd);
  return 0;
  
}
//regex expression("<a href=\"(\\S*)\">");

// process_ftp:
// on success returns the ftp response code, and fills
// msg with the ftp response message.
int process_ftp(const char* response, std::string* msg)
{
   std::string strresponse= response ;
   std::string::const_iterator start, end;
   start = strresponse.begin();
   end = strresponse.end();  
   boost::match_results<std::string::const_iterator> what;
   //if(regex_match(response, what, expression))
   boost::match_flag_type flags = boost::match_default;
   while(boost::regex_search(start, end, what, expression, flags))   
   {
      // what[0] contains the whole string
      // what[1] contains the response code
      // what[2] contains the separator character
      // what[3] contains the text message.
	  cout << "Match found" << endl;
	  msg->assign(what[1].first, what[1].second);
	  cout << *msg << endl ;
	  msg->assign(what[2].first, what[2].second);
	  char dest_gb2312[80];
	  utf8togb2312((*msg).c_str(),(*msg).size(),dest_gb2312,80);
	  cout << dest_gb2312 << endl ;	  
	  // update search position:
      start = what[0].second;     
	 // update flags:
      flags |= boost::match_prev_avail;
      flags |= boost::match_not_bob;	  
   }
   
   return 0 ;
}

int main(int argc)
{
	std::ifstream inf("ref=nb_sb_noss.htm",ios::in|ios::binary) ;
	stringstream in ;
	std::string	out ;
	in << inf.rdbuf() ;

      int result = process_ftp(in.str().c_str(), &out);
      if(result != -1)
      {
      }
      else
      {
         cout << "Match not found" << endl;
      }

   return 0;
}








