
#ifndef __AUTH_H__
#define __AUTH_H__

#include <string>
#include "getmac.h"
#include "authcommon.h"


static const int sl[] = 
{1,8,9,23,9,8,26,11,2,3,96,36,35,36,65,51,90,10,2,20,6,78,7,
16,86,92,32,96,38,2,12,12,32,96,36,35,36,65,13,90,10,2,20,68,78,7,
16,68,39,23,59,48,21,13,21,32,18,36,35,23,65,51,90,10,2,20,6,78,7} ;

inline CString encode(CString src) {
	CString result ;
	src = charToHex(src).c_str() ;
	char* p = new char[src.GetLength() + 1 ] ;
	memset(p , 0 ,  src.GetLength() + 1 ) ;
	for(int i = 0 ; i< src.GetLength() ; i++ ) {
		p[i]= (src[i] + sl[i] ) ^ 8 ;
	}
	result = p ;
	delete []p ;
	result = charToHex(result).c_str() ;
	return result ;
}

inline CString decode(CString src) {
	CString result ;
	src = HexToChar(src).c_str() ;
	char* p = new char[src.GetLength() + 1 ] ;
	memset(p , 0 ,  src.GetLength() + 1 ) ;
	for(int i = 0 ; i< src.GetLength() ; i++ ) {
		p[i]= (src[i] ^ 8) - sl[i] ;
	}
	result = p ;
	delete []p ;
	result = HexToChar(result).c_str() ;
	return result ;
}

inline CString getRegisterFile() {
	char szSysPath[MAX_PATH] = {0} ;
	GetSystemDirectory(szSysPath , sizeof(szSysPath) - 1) ;

	CString    sPath;   	
	GetModuleFileName(NULL,sPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);   
	sPath.ReleaseBuffer    ();   
	int    nPos;   
	nPos=sPath.ReverseFind('\\');   
	sPath=sPath.Right(sPath.GetLength() - nPos - 1);   
	
	return   CString(szSysPath) + "\\" +  sPath + ".hf";   
}

struct AuthStruct 
{
	char src[256] ;
	char dst[256] ;
	int use ;
	char back[256] ;
} ;

inline int checkRegister() {
	CString filePath = getRegisterFile() ;
	FILE * fp = fopen (filePath , "rb") ;
	if ( NULL == fp ) {
		return -1 ;
	}
	AuthStruct auth ;
	fread(&auth , 1 , sizeof(auth) , fp) ;
	fclose(fp) ;
	
	unsigned int srcHash = 0 ;
	time_t srcT = 0 ;
	int maxUserTimes = 0 ;
	sscanf(auth.src , "%ul-%d-%d" , &srcHash , &srcT , &maxUserTimes) ;
	
	//check src
	char mac[256] ={0} ;
	getMAC(mac) ;
	unsigned int hash = SDBMHash(mac) ;
	
	if (srcHash != hash) {
		return -4 ;
	}
	
	//注册码验证
	CString result = decode(auth.dst) ;
	if (result != auth.src) {
		return -2 ;
	}
	
	//使用次数验证
	if ( auth.use >= maxUserTimes ) {
		return -3 ;
	}
	
	//时间验证
	time_t now ;
	time(&now) ;
	if (now - srcT > 24 * 365 * 60 * 60) {
		return -5 ;
	}
	
	return 0 ;
}

inline int registerSoftware(const char* src , const char* dst) {
	CString filePath = getRegisterFile() ;
	AuthStruct auth ;
	memset(&auth, 0 , sizeof(auth)) ;
	memcpy(auth.src , (void *)src , sizeof(auth.src)) ;
	memcpy(auth.dst , (void *)dst , sizeof(auth.dst)) ;
	
	CString result = decode(auth.dst) ;
	if (result != auth.src) {
		return -2 ;
	}
	FILE * fp = fopen (filePath , "wb") ;
	if ( NULL == fp ) {
		return -1 ;
	}
	
	fwrite(&auth , 1 , sizeof(auth) , fp) ;
	fclose(fp) ;
	return 0 ;
}

inline CString getNewSrcCode(const int useTimes) 
{
	time_t   t ; 
	time(&t) ;
	char mac[256] ={0} ;
	getMAC(mac) ;
	CString timeStr ;
	timeStr.Format("%ul-%-d-%05d" , SDBMHash(mac) , t , useTimes) ;
	CString filePath = getRegisterFile() ;
	AuthStruct auth ;
	memset(&auth, 0 , sizeof(auth)) ;
	memcpy(auth.src , (void *)timeStr.GetBuffer(0) , sizeof(auth.src)) ;
	FILE* fp = fopen (filePath , "wb") ;
	fwrite(&auth , 1 , sizeof(auth) , fp) ;
	fclose(fp) ;
	return timeStr ;

}


inline CString getSrcCode(const int useTimes) {
	CString filePath = getRegisterFile() ;
	AuthStruct auth ;
	memset(&auth, 0 , sizeof(auth)) ;
	
	FILE * fp = fopen (filePath , "rb") ;
	if ( fp != NULL ) 
	{
		fread(&auth , 1 , sizeof(auth) , fp) ;
		fclose(fp) ;
		fp = NULL ;
		if (checkRegister() == 0 ) 
		{
			return auth.src ;
		}
		else 
		{
			if (strlen(auth.dst) > 0) 
			{
				CString timeStr = getNewSrcCode(useTimes) ;
				return timeStr ;	
			}
			else 
			{
				return auth.src ;
			}
		}
	}
	else 
	{
		return getNewSrcCode(useTimes) ; 
	}
}

inline int upUseTime() {
	CString filePath = getRegisterFile() ;
	FILE * fp = fopen (filePath , "rb") ;
	if ( NULL == fp ) {
		return -1 ;
	}
	AuthStruct auth ;
	fread(&auth , 1 , sizeof(auth) , fp) ;
	fclose(fp) ;
	fp = NULL ;

	auth.use++ ;

	fp = fopen (filePath , "wb") ;
	if ( NULL == fp ) {
		return -1 ;
	}
	
	fwrite(&auth , 1 , sizeof(auth) , fp) ;
	fclose(fp) ;
	return 0 ;
}


#endif //__AUTH_H__