#ifndef APP_STRUCT_H
#define APP_STRUCT_H 1
/////////////		appstruct.h		///////////////////////

#pragma pack(push,APP_STRUCT_H)
#pragma pack(1)
typedef struct __ShareMem
{
	char	bRuning;
	char	FlagString[63];
	DWORD	timeV;		//GetTickCount()/1000-服务器时间
	DWORD	appid;
	WORD    wSize;		//sizeof(APPSHAREINFO)
	DWORD	timeV2;		//time(&timeV2)-服务器时间
	DWORD	timeV3;
}APPSHAREINFO,*PAPPSHAREINFO;
#pragma pack(pop,APP_STRUCT_H)
inline int SharemInit(PAPPSHAREINFO pShareInfo,char *name)
{
	if(strcmp(name,pShareInfo->FlagString))
	{
		memset(pShareInfo,0,sizeof(*pShareInfo));
		pShareInfo->bRuning=1;
		strcpy(pShareInfo->FlagString,name);
		pShareInfo->appid=::GetCurrentProcessId();
		pShareInfo->wSize=sizeof(*pShareInfo);
		return 1;
	}
	return 0;
}
#define  ADJUST_SYSTIME(info,tm)\
	do\
	{\
		(info->timeV)=(::GetTickCount()/1000)-(tm);\
		(info->timeV2)=time((time_t*)&(info)->timeV2)-(tm);\
	}while(0)
inline DWORD get_systime_withtick(PAPPSHAREINFO info,DWORD tick)
{
	return (tick/1000)-info->timeV;
}
inline DWORD get_systime_withtime(PAPPSHAREINFO info,DWORD tm)
{
	return tm-info->timeV2;
}
#endif//APP_STRUCT_H
