//
// urlcodec.h
// url 编解码函数
// bondshi
// 2007/02/08
//

#ifndef __URLCODEC_H__
#define __URLCODEC_H__

#include <string>

////////////////////////////////////////////////////////////////////////////////

inline std::string
charToHex(char c)
{
    std::string result;
    char first, second;

    first = (c & 0xF0) / 16;
    first += first > 9 ? 'A' - 10 : '0';
    second = c & 0x0F;
    second += second > 9 ? 'A' - 10 : '0';

    result.append(1, first);
    result.append(1, second);

    return result;
}

inline char
hexToChar(char first, char second)
{
    int digit;
    digit = (first >= 'A' ? ((first & 0xDF) - 'A') + 10 : (first - '0'));
    digit *= 16;
    digit += (second >= 'A' ? ((second & 0xDF) - 'A') + 10 : (second - '0'));
    return static_cast<char>(digit);
}

// 标准的URL编解码操作
inline std::string
regUrlEncode(const std::string& src)
{
    std::string result;
    std::string::const_iterator iter;

    for(iter = src.begin(); iter != src.end(); ++iter) {
	char ch = *iter;
	if ((ch >= '0' && ch <= '9') ||
	    (ch >= 'A' && ch <= 'Z') ||
	    (ch >= 'a' && ch <= 'z') ||
	    strchr("-_.!~*()\'", ch) != NULL)
	{
	    result += ch;
	}
	else if (ch == ' ')
	{
	    result += '+';
	}
	else
	{
	    result += "%" + charToHex(ch);
	}
    }

    return result;
}

// 标准的URL编解码操作
inline std::string
regUrlDecode(const std::string& src)
{
    std::string result;
    std::string::const_iterator iter;
    char c;

    for(iter = src.begin(); iter != src.end(); ++iter) {
	switch(*iter) {
	case '+':
	    result.append(1, ' ');
	    break;
	case '%':
	    // Don't assume well-formed input
	    if(std::distance(iter, src.end()) >= 2
	       && std::isxdigit(*(iter + 1)) && std::isxdigit(*(iter + 2))) {
		c = *++iter;
		result.append(1, hexToChar(c, *++iter));
	    }
	    // Just pass the % through untouched
	    else {
		result.append(1, '%');
	    }
	    break;

	default:
	    result.append(1, *iter);
	    break;
	}
    }

    return result;
}

// 非标准的URL编码，只对分割符, '=', '%'进行转义
inline std::string
urlEncode(const std::string& src, char sep = '&')
{
    std::string result;
    std::string::const_iterator iter;

    for(iter = src.begin(); iter != src.end(); ++iter) {
	char ch = *iter;
	if (ch == sep || ch == '=' || ch == '%')
	{
	    result += "%" + charToHex(ch);
	}
	else
	{
	    result += ch;
	}	
    }

    return result;
}

// 非标准的URL编码，只对分割符, '=', '%'进行转义
inline std::string
urlDecode(const std::string& src, char sep = '&')
{
    std::string result;
    std::string::const_iterator iter;
    char c;

    for(iter = src.begin(); iter != src.end(); ++iter) {
	switch(*iter) {
	case '%':
	    // Don't assume well-formed input
	    if(std::distance(iter, src.end()) >= 2
	       && std::isxdigit(*(iter + 1)) && std::isxdigit(*(iter + 2))) {
		c = *++iter;
		result.append(1, hexToChar(c, *++iter));
	    }
	    // Just pass the % through untouched
	    else {
		result.append(1, '%');
	    }
	    break;

	default:
	    result.append(1, *iter);
	    break;
	}
    }

    return result;
}


////////////////////////////////////////////////////////////////////////////////

#endif // __URLCODEC_H__

