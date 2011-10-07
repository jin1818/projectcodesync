#ifndef WIN_USED_H
#define WIN_USED_H 1
#include "windows.h"
#include "IO.H"
///////////		winused.h	///////////////
inline HANDLE wuCreateProc(char *exePath,char *command,DWORD &pid)
{
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	char commandline[4096];
	memset (&pi, 0, sizeof(pi));
	memset (&si, 0, sizeof(si));
	si.cb= sizeof(si);
	::GetStartupInfo(&si);
	if(command)
		wsprintf(commandline,"\"%s\" %s",exePath,command);
	else
		wsprintf(commandline,"\"%s\"",exePath);
	BOOL fSuccess= ::CreateProcess(NULL,
		commandline,
		NULL,
		NULL,
		NULL,
		0,
		NULL,
		NULL,
		&si,
		&pi);
	if (!fSuccess)
	{
		return  NULL;
	}
	::CloseHandle(pi.hThread);
	pid=pi.dwProcessId;
	return pi.hProcess;
}
/*
inline HANDLE wuCreateProc2(char *exePath,char *command,DWORD &pid)
{
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	memset (&pi, 0, sizeof(pi));
	memset (&si, 0, sizeof(si));
	si.cb= sizeof(si);
	::GetStartupInfo(&si);
	BOOL fSuccess= ::CreateProcess(exePath,
		command,
		NULL,
		NULL,
		NULL,
		0,
		NULL,
		NULL,
		&si,
		&pi);
	if (!fSuccess)
	{
		return  NULL;
	}
	::CloseHandle(pi.hThread);
	pid=pi.dwProcessId;
	return pi.hProcess;
}
*/
inline BOOL wuModifyRegValue(HKEY root,char *subPath,char *valueName,void *value,DWORD valueLen,DWORD type)
{
	HKEY hk;
	if(::RegOpenKeyEx(root,subPath,0,KEY_WRITE,&hk)==ERROR_SUCCESS)
	{
		if(::RegSetValueEx(hk,valueName,0,type,(BYTE *)value,valueLen)==ERROR_SUCCESS)
		{
			::RegCloseKey(hk);
			return TRUE;
		}
		::RegCloseKey(hk);
	}
	return FALSE;
}
inline BOOL wuDeleteRegValue(HKEY root,char *subPath,char *valueName)
{
	HKEY hk;
	if(::RegOpenKeyEx(root,subPath,0,KEY_ALL_ACCESS,&hk)==ERROR_SUCCESS)
	{
		if(::RegDeleteValue(hk,valueName)==ERROR_SUCCESS)
		{
			::RegCloseKey(hk);
			return TRUE;
		}
		::RegCloseKey(hk);
	}
	return FALSE;
}
inline DWORD wuReadRegValue(HKEY root,char *subPath,char *valueName,DWORD *type,VOID *data,DWORD size)
{
	HKEY hk;
	if(::RegOpenKeyEx(root,subPath,0,KEY_READ,&hk)==ERROR_SUCCESS)
	{
		if(ERROR_SUCCESS==::RegQueryValueEx(hk,valueName,NULL,type,(BYTE *)data,&size))
		{
			::RegCloseKey(hk);
			return size;
		}
		::RegCloseKey(hk);
	}
	return 0;
}
inline BOOL wuDeleteFile(char *path)
{
	::SetFileAttributes(path,FILE_ATTRIBUTE_NORMAL);
	return ::DeleteFile(path);
}
inline BOOL wuCopyFile(char *from,char *to)
{
	::SetFileAttributes(to,FILE_ATTRIBUTE_NORMAL);
	for(int i=0;i<10;i++)
	{
		if(::CopyFile(from,to,FALSE))
			return TRUE;
		::Sleep(100);
	}
	return FALSE;
}
inline BOOL wuCreateDir(char *path)
{
	int len;
	len=strlen(path);
	while(len!=0 && path[len]!='\\')len--;
	if(len)
	{
		path[len]=0;
		if(::GetFileAttributes(path)==-1)
		{
			if(!wuCreateDir(path))
			{
				path[len]='\\';
				return FALSE;
			}
		}
		path[len]='\\';
		if(::GetFileAttributes(path)!=-1)
			return TRUE;
		if(::CreateDirectory(path,NULL))
			return TRUE;
	}
	return FALSE;
}

inline BOOL wuDeleteDir(char *Dir)
{
	_finddata_t fdata;
	long hFind;
	char szDirBuffer[260];
	strcpy(szDirBuffer,Dir);
	strcat(szDirBuffer,"\\*.*");
	if((hFind=_findfirst(szDirBuffer,&fdata))!=-1)
	{
		do
		{
			if(fdata.attrib&_A_SUBDIR)
			{
				if(strcmp(fdata.name,".")!=0&&strcmp(fdata.name,"..")!=0)
				{
					wsprintf(szDirBuffer,"%s\\%s",Dir,fdata.name);
					if(!wuDeleteDir(szDirBuffer))
						break;
				}
			}
			else
			{
				wsprintf(szDirBuffer,"%s\\%s",Dir,fdata.name);
				if(!wuDeleteFile(szDirBuffer))
					break;
			}
		}while(_findnext(hFind,&fdata)!=-1 );
		_findclose(hFind);
		return ::RemoveDirectory(Dir);
		//return TRUE;
	}
	return FALSE;
}

inline int wuReadIniString(char *group,char *value,char *out,DWORD outSize,char *iniFile,char *szDefault="")
{
	int i;
	int len=GetPrivateProfileString(group,value,"",out,outSize,iniFile);
	if(len)
	{
		i=0;
		while(out[i]==0x20||out[i]=='\t')i++;
		if(value=strstr(out+i,";"))
		{
			value[0]=0;
			len=(value-out);
		}
		if(i<len)
		{
			len--;
			while(len!=0 && (out[len]==0x20||out[len]=='\t'))len--;
			len++;
			out[len]=0;
			if(i!=0)
			{
				len=0;
				while(out[len++]=out[i++]);
			}
			return len;
		}

	}
	return 0;
}
inline void wuRebootSystem()
{
	HANDLE hToken;
	TOKEN_PRIVILEGES tp;
	LUID luid;
	::OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY, &hToken ) ;
	::LookupPrivilegeValue( NULL, SE_SHUTDOWN_NAME, &luid );
	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	::AdjustTokenPrivileges( hToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), NULL, NULL );
	::ExitWindowsEx(EWX_REBOOT | EWX_FORCE, 0);
}
#pragma comment (lib, "version.lib")
inline DWORD wuGetFileVer(char *filePath,DWORD &verLS,DWORD &verMS)
{
	char *pverinfo;
	DWORD vsize,handle;
	VS_FIXEDFILEINFO *vfix;
	verLS=verMS=0;
	if(vsize=::GetFileVersionInfoSize(filePath,&handle))
	{
		if(pverinfo=new char[vsize])
		{
			if(::GetFileVersionInfo(filePath,handle,vsize,pverinfo))
			{
				if(::VerQueryValue(pverinfo,"\\",(LPVOID *)&vfix,(PUINT)&vsize))
				{
					verLS=vfix->dwFileVersionLS;
					verMS=vfix->dwFileVersionMS;
				}
			}
			delete pverinfo;
		}
	}
	return ((verMS&0XFF0000)<<8)|((verMS&0XFF)<<16)|((verLS&0XFF0000)>>8)|(BYTE)verLS;
}
inline DWORD wuGetAppPath(char *path,DWORD size)
{
	size=::GetModuleFileName(NULL,path,size);
	while(path[size]!='\\')size--;
	size++;
	path[size]=0;
	return size;
}
/*

inline DWORD wuGetAppPath2(char *path,DWORD size)
{
	size=::GetModuleFileName(NULL,path,size);
	while(path[size]!='\\')size--;
	path[size]=0;
	return size;
}
*/
inline DWORD wuGetSystemPath(char *path,DWORD size)
{
	DWORD pos;
	pos=::GetSystemDirectory(path,size);
	if(pos<size)
	{
		if(path[pos-1]!='\\')
		{
			path[pos++]='\\';
			path[pos]=0;
		}
		return pos;
	}
	return 0;
}
inline DWORD wuGetWinPath(char *path,DWORD size)
{
	DWORD pos;
	pos=::GetWindowsDirectory(path,size);
	if(pos<size)
	{
		if(path[pos-1]!='\\')
		{
			path[pos++]='\\';
			path[pos]=0;
		}
		return pos;
	}
	return 0;
}
typedef enum E_WALLPAPERSTYLE
{
	WP_S=1,
	WP_C,
	WP_F,
}WALLPAPERSTYLE;
/*
设置桌面背景
参数说明：
	char *bmpFile,BMP图片文件名含路径，因为图片中能在WIN目录下
	WALLPAPERSTYLE style，平铺、拉伸、居中
*/
inline void SetWallpaper(char *bmpFile,WALLPAPERSTYLE style)
{
	char szWinDir[512];
	switch(style)
	{
	case WP_C:
		wuModifyRegValue(HKEY_CURRENT_USER,"Control Panel\\Desktop","TileWallpaper",(BYTE *)"0",2,REG_SZ);
		wuModifyRegValue(HKEY_CURRENT_USER,"Control Panel\\Desktop","WallpaperStyle",(BYTE *)"0",2,REG_SZ);
		break;
	case WP_F:
		wuModifyRegValue(HKEY_CURRENT_USER,"Control Panel\\Desktop","TileWallpaper",(BYTE *)"0",2,REG_SZ);
		wuModifyRegValue(HKEY_CURRENT_USER,"Control Panel\\Desktop","WallpaperStyle",(BYTE *)"2",2,REG_SZ);
		break;
	case WP_S:
		wuModifyRegValue(HKEY_CURRENT_USER,"Control Panel\\Desktop","TileWallpaper",(BYTE *)"1",2,REG_SZ);
		wuModifyRegValue(HKEY_CURRENT_USER,"Control Panel\\Desktop","WallpaperStyle",(BYTE *)"0",2,REG_SZ);
		break;
	}
	if(bmpFile)
	{
		wuGetWinPath(szWinDir,sizeof(szWinDir));
		strcat(szWinDir,bmpFile);
		SystemParametersInfo(SPI_SETDESKWALLPAPER,0,szWinDir,SPIF_UPDATEINIFILE);
	}
	else
		SystemParametersInfo(SPI_SETDESKWALLPAPER,0,0,SPIF_UPDATEINIFILE);
}
inline BOOL GetCurrentScreenSave(PVOID path,DWORD size)
{
	DWORD type=REG_SZ;
	if(wuReadRegValue(HKEY_CURRENT_USER,"Control Panel\\Desktop","SCRNSAVE.EXE",&type,path,size))
		return TRUE;
	return FALSE;
}
inline void SetCurrentScreenSave(char * path,DWORD size)
{
	if(path)
	{
		wuModifyRegValue(HKEY_CURRENT_USER,"Control Panel\\Desktop","SCRNSAVE.EXE",(BYTE *)path,size,REG_SZ);
	}
	else
	{
		wuDeleteRegValue(HKEY_CURRENT_USER,"Control Panel\\Desktop","SCRNSAVE.EXE");
	}
	SystemParametersInfo(SPI_SETSCREENSAVEACTIVE,TRUE,0,0);

}
inline void StartScreenSave()
{
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_SCREENSAVE, 0);
}
inline HANDLE wuCreateShareMem(PVOID & addr,DWORD size,char *name)
{
	HANDLE hMapping; 
	if(hMapping=CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,size,name))
	{
		if(addr=MapViewOfFile(hMapping,FILE_MAP_ALL_ACCESS,0,0,0))
			return hMapping;
		::CloseHandle(hMapping);
	}
	return NULL;
}
inline VOID wuCloseShareMem(HANDLE hMaping,PVOID &addr)
{
	if(addr)
	{
		UnmapViewOfFile(addr); 
		addr=NULL;
	}
	::CloseHandle(hMaping);
}
#endif//WIN_USED_H
