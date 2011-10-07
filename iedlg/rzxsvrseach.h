#ifndef RZX_WATER_NET_H
#define RZX_WATER_NET_H 1
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the RZXSVRSEACH_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// RZXSVRSEACH_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

int __stdcall AutoSearchSvrAddr(char *filePath,BOOL bDefault);
/*
	���������� ���漰��·��
̽�����ע�᲻�ϣ�������������һ���ض���HTTP GET���������а���һ����������B25AF4D7-EA30-494C-B519-7D1F4383ED5C��������������ǰ���������һЩ���Ŵ��Ա��ⷢ����Ϊ�����׵ı������

�ֲ�ʽ�����������������һ���ض��ļ���λ�ڹ����������װĿ¼�£���Ϊregsvr.addr��д���������ע�����IP��ַ�Ͷ˿ڣ��ļ���ʽΪ��
���ʮ����IP + : + PORT + ���з�\n
����ֲ�ʽ��ע�����������192.168.1.1��10010�˿��ϣ����ļ��е�����Ϊ��
	192.168.1.1:10010\n
�ļ�����д��ǰ��Ҫ����,�����㷨����RC4����Կ�̶�Ϊ����������B25AF4D7-EA30-494C-B519-7D1F4383ED5C��

��·ϵͳ���Ӿ������ڵ�����HTTP GET����һ��ƥ�䵽���������򽫷ֲ�ʽ������������ɵķ�����ע�������Ϣ�ļ����ظ����͸�������û���̽�룩��̽�����յ���ҳ������Ƚ��ܣ�ͨ�������ļ���������˭ע�ᡣ

̽��ͨ�����ַ�ʽ���ַ�����ʱ����GET����Ӧ�þ���һ���������ԣ����β�ѯ��ʱ��������̫�̣����ܵ���5���ӣ������ҵ�ǰһ�γ���ʧ�ܺ�Ӧ����������ĳ���ʱ������ͬʱҪ��֤���β�ѯʱ�䲻��С��2Сʱ��

ʵ�ֺ�����	AutoSearchSvrAddr
����	��	char *filePath ָ�������Ҫ���浽���ļ�ȫ·����
			BOOL bDefault  TRUE��ʾĬ�ϵ�ַ��FALSE��ʾ��̬��ȡ
����ֵ	��	int  �ɹ�����0��ʧ�ܷ��أ�1���ӵ�ַʧ�ܡ���2���ջ�Ӧʧ�ܡ���3�����ļ�ʧ��
*/



DWORD __stdcall HttpDownFile(char *domain,int port,char *httpPath,char *savePath);
/*
	HttpDownFile("www.xxx.com",80,"/apps/test.htm","c:\\test.htm");
	���������ļ��Ĵ�С
*/
DWORD __stdcall UrlDownFile(char *url,char *savePath);
/*
	UrlDownFile("http://www.xxx.com/apps/test.hmt","c:\\test.htm");
	���������ļ��Ĵ�С
*/
int __stdcall GetFilesToTempPath(char *httpdomain,char *localIniFile);
/*
	GetFilesToTempPath("WWW.XXX.COM","C:\\UPDATE.INI");
	��"C:\\UPDATE.INI"��ָ���ļ���"WWW.XXX.COM"���ص�������ʱĿ¼��
	����ָ��httpdomain������ʹ��UPDATE.INI�ļ��е�[UPDATE]->domain 
	UPDATE.INI�ļ���ʽ���£�

[UPDATE]
domain     =		;http���������������������͵�½������ʹ����ͬ������
port       =	80	;http�������Ķ˿�
module     =	20	;��ǰ�ֲ�ʽ�ͻ��˹����ļ����������ÿһ���ļ���һ��[module_x]��֮��Ӧ��x��0��ʼ

;�ֲ�ʽ�ͻ��������ļ���������ֵĴ���Ӧ����agentmanage.sys�ļ���һһ��Ӧ

[module_0]
ver  	=	1.0.0.0
path 	=	agentdown/update/agentmanage.sys	;�ֲ�ʽ�ͻ��˰汾�����ļ�
name 	=	agentmanage.sys			;�ļ���
[module_1]
ver  	=	1.0.0.0				;�ļ��İ汾�ţ��������������ļ������汾�޹ء����˰汾����APP.INI����Ӧ�ļ��汾�Ų�ͬ�����´��ļ��������滻	
path 	=	agentdown/update/SnapPicDll.dll	;���HTTP��������Ŀ¼��ȫ·��������ʱʹ��
name 	=	SnapPicDll.dll			;���غ��Դ��������ڿͻ��˴洢ϵͳ��
[module_2]
ver  	=	1.0.0.0
path 	=	agentdown/update/FileLog.dll
name 	=	FileLog.dll
[module_3]
ver  	=	1.0.0.0
path 	=	agentdown/update/processctrl.dll
name 	=	processctrl.dll
[module_4]
ver  	=	1.0.0.0
path 	=	agentdown/update/QQRecorder.dll
name 	=	QQRecorder.dll
[module_5]
ver  	=	1.0.0.0
path 	=	agentdown/update/ServerControl.dll
name 	=	ServerControl.dll
[module_6]
ver  	=	1.0.0.0
path 	=	agentdown/update/SysInfo.dll
name 	=	SysInfo.dll
[module_7]
ver  	=	1.0.0.0
path 	=	agentdown/update/RTXSend.dll
name 	=	RTXSend.dll
[module_8]
ver  	=	1.0.0.0
path 	=	agentdown/update/Agent.exe
name 	=	Agent.exe
[module_9]
ver  	=	1.0.0.0
path 	=	agentdown/update/copyapp.exe
name 	=	copyapp.exe
[module_10]
ver  	=	1.0.0.0
path 	=	agentdown/update/sysproc.dll
name 	=	sysproc.dll
[module_11]
ver  	=	1.0.0.0
path 	=	agentdown/update/sysproc.sys
name 	=	sysproc.sys
[module_12]
ver  	=	1.0.0.0
path 	=	agentdown/update/dismanager.exe
name 	=	dismanager.exe
[module_13]
ver  	=	1.0.0.0
path 	=	agentdown/update/rzxsvrseach.dll
name 	=	rzxsvrseach.dll
[module_14]
ver  	=	1.0.0.0
path 	=	agentdown/update/SVR.INI
name 	=	SVR.INI
[module_15]
ver  	=	1.0.0.0
path 	=	agentdown/update/ssleay32.dll
name 	=	ssleay32.dll
[module_16]
ver  	=	1.0.0.0
path 	=	agentdown/update/libeay32.dll
name 	=	libeay32.dll
[module_17]
ver  	=	1.0.0.0
path 	=	agentdown/update/HashLite.dll
name 	=	HashLite.dll
[module_18]
ver  	=	1.0.0.0
path 	=	agentdown/update/Send.dll
name 	=	Send.dll
[module_19]
ver  	=	1.0.0.0
path 	=	agentdown/update/b2j.dll
name 	=	b2j.dll
[module_20]
ver  	=	1.0.0.0
path 	=	agentdown/update/
name 	=	
*/
void __stdcall DataToRc4(void *buffer_ptr, int buffer_len);

void __stdcall SetDefaultSvrAddr(char *domain,char* port);
/*
SetDefaultSvrAddr����Ĭ�ϵķ�������ַ��
*/

void writelog(char *format,...);//���߳�IDΪ��׺д��־������ܴ�5�����
char *getlogfilename(int ex,char *outPath,int outLen);
void writelogex(bool force,int ex,char *format,...);//��int exΪ��׺д��־������ܴ�5�����,��forceΪǿ��д��־��������g_logWrited�����������Ƿ�д��־
inline void empty_log(char *,...){}
#define WZX_LONG 1
#ifdef WZX_LONG
#define __writelog writelog 
#else
#define __writelog empty_log
#endif
/*
IWaterNet�ӿڷ�װ�˷�ˮǽ�������ͨ��Э�飬ʵ����һЩ����������� ��



class IWaterNet
{
public:
	//��¼�������Ĺ��ܡ���ˮǽ��ܵ��ô�
	//����localIP�Ǳ���IP��svrIP�Ƿ�����IP,svrPort�Ƿ������˿ں�����ʼ��ˮǽ�������֮���ͨ�š�
	virtual int Logon(DWORD localIP,DWORD svrIP,WORD svrPort)=0;

	//�������ܡ���ˮǽ��ܵ������̵߳��ô˺�������ʱ�������������������tm�ǵ�ǰϵͳʱ�䣡
	virtual int HeartSvr(DWORD tm)=0;

	//��ˮǽ��ܵ��ô˺�����ʼ�����������·������ÿ�������������ͨ��IMSGRecver�ӿ�֪ͨ��ˮǽ��ܣ�
	virtual BOOL BeginListen()=0;

	//��ˮǽ��ܵ��ô˺���ֹͣ�����������·�������
	virtual void Stop()=0;

	//��ˮǽ��ܻ�Ӧ��ģ�顱���ô˺��������������������������ص����������Ҫ��ͨ��IMSGRecver�ӿ�֪ͨ��ˮǽ��ܣ� 
	virtual BOOL SendCmd(void *pdata,int len)=0;

	//��ˮǽ��ܻ�Ӧ��ģ�顱���ô˺������ͱ����ļ����������������У�
	//		pPathName�����ļ���ȫ·������
	//		netName�Ƿ������յ����ļ���������·������
	//		szRule�������ļ��ϴ�������Ĺ���
	//		alarmָʾ�ļ��ϴ��ɹ��Ժ��Ƿ�������������ļ�����֪ͨ��
	virtual BOOL UploadFileEx(char *pPathName,char *szRule,char *netName,BOOL alarm)=0;

	//��ˮǽ��ܻ�Ӧ��ģ�顱���ô˺�����ȡ������������ͻ��˵�ID
	virtual DWORD get_SendID()=0;

	//��ˮǽ��ܻ�Ӧ��ģ�顱���ô˺�����ȡ����ͨ���Ƿ����
	virtual BOOL get_Encrypt()=0;

	//��ˮǽ��ܵ��ô˺�����������ͨ���Ƿ����
	virtual void set_Encrypt(BOOL encry)=0;

	//��ˮǽ��ܻ�Ӧ��ģ�顱���ô˺�����ȡ����IP�ĵ����ʽ
	virtual char *get_MyIP()=0;
	//��ˮǽ��ܻ�Ӧ��ģ�顱���ô˺�����ȡ����IP
	virtual DWORD get_MydwIP()=0;
	//��ˮǽ��ܻ�Ӧ��ģ�顱���ô˺�����ȡ���������ļ�����˿ڣ����������ϴ��ļ���
	virtual WORD  get_FilePort()=0;
	//��ˮǽ��ܵ��ô˺�����ȡ����������������ʱ������
	virtual DWORD get_MaxHandleInterval()=0;
};
*/


class IMSGRecver
{
public:
	virtual int OnMSG(DWORD msg,DWORD len,void *pdata)=0;
};
class IWaterNet
{
public:
	
	virtual int Logon(DWORD localIP,DWORD svrIP,WORD svrPort)=0;
	virtual int HeartSvr(DWORD tm)=0;
	virtual BOOL BeginListen()=0;
	virtual void Stop()=0;
	virtual BOOL SendCmd(void *pdata,int len)=0;
	virtual BOOL UploadFileEx(char *pPathName,char *szRule,char *netName,BOOL alarm)=0;
	virtual DWORD get_SendID()=0;
	virtual BOOL get_Encrypt()=0;
	virtual void set_Encrypt(BOOL encry)=0;
	virtual char *get_MyIP()=0;
	virtual DWORD get_MydwIP()=0;
	virtual WORD  get_FilePort()=0;
	virtual DWORD get_MaxHandleInterval()=0;
};
/*
��ˮǽ��ܵ���GetWaterNet��ȡIWaterNet�ӿڣ�Ȼ�����IWaterWorker�ӿڵĳ�ʼ����������Ϊ����������Ӧ��ģ�顱
*/
IWaterNet *__stdcall GetWaterNet(IMSGRecver *irecver);
#endif//RZX_WATER_NET_H