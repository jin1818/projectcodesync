#ifndef APP_NAME_H
#define APP_NAME_H 1
/////////////	appname.h	///////////////////
#define APP_INI_NAME "agentmanage.sys"
#define APP_SVRINI_NAME "SVR.INI"
#define APP_UPDATAINI_NAME "update.ini"
#define APP_AUTORUN_KEY  "RZX_DCLIENT"
#define KEY_ROOT "ROOT"

#define KEY_UNINSTALL "UNINSTALL"
#define KEY_OTHER  "OTHER"
#define KEY_UPDATE "UPDATE"
#define KEY_RUN    "RUN"
#define KEY_HIDE   "HIDE"
#define KEY_REMOVE  "TEMP_REMOVE"
#define KEY_BACK    "TEMP_BACKUP"
#define EXIT_FILE_NAME "{4143EA51-12BC-49fe-8986-6D7E947F346D}.tmp"
#define APP_FLAG_STRING APP_AUTORUN_KEY

#define OLD_INI "wzx_setup.ini"
inline BOOL g_IsStoped()
{
	char Path[512];
	wuGetAppPath(Path,sizeof(Path));
	strcat(Path,"option\\" EXIT_FILE_NAME);
	FILE *file=fopen(Path,"r");
	if(file)
	{
		fclose(file);
		return TRUE;
	}
	return FALSE;
}
#endif//APP_NAME_H