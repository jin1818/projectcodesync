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
	服务器发现 （涉及旁路）
探针如果注册不上，则向外网发送一个特定的HTTP GET请求，请求中包含一个特征串（B25AF4D7-EA30-494C-B519-7D1F4383ED5C），在特征串的前后随机生成一些干扰串以避免发现行为很容易的被察觉。

分布式管理服务器启动后向一个特定文件（位于管理服务器安装目录下，名为regsvr.addr）写入服务器的注册监听IP地址和端口；文件格式为：
点分十进制IP + : + PORT + 换行符\n
例如分布式的注册监听在主机192.168.1.1的10010端口上，则文件中的内容为：
	192.168.1.1:10010\n
文件内容写入前需要加密,加密算法采用RC4，密钥固定为特征串，即B25AF4D7-EA30-494C-B519-7D1F4383ED5C。

旁路系统监视局域网内的所有HTTP GET请求，一旦匹配到特征串，则将分布式管理服务器生成的服务器注册监听信息文件返回给发送该请求的用户（探针），探针在收到该页面后首先解密，通过分析文件决定该向谁注册。

探针通过这种方式发现服务器时发送GET请求应该具有一定的智能性，两次查询的时间间隔不能太短（不能低于5分钟），并且当前一次尝试失败后应该拉长后面的尝试时间间隔；同时要保证两次查询时间不能小于2小时。

实现函数：	AutoSearchSvrAddr
参数	：	char *filePath 指定结果将要保存到的文件全路径名
			BOOL bDefault  TRUE表示默认地址，FALSE表示动态获取
返回值	：	int  成功返回0，失败返回－1连接地址失败、－2接收回应失败、－3创建文件失败
*/



DWORD __stdcall HttpDownFile(char *domain,int port,char *httpPath,char *savePath);
/*
	HttpDownFile("www.xxx.com",80,"/apps/test.htm","c:\\test.htm");
	返回下载文件的大小
*/
DWORD __stdcall UrlDownFile(char *url,char *savePath);
/*
	UrlDownFile("http://www.xxx.com/apps/test.hmt","c:\\test.htm");
	返回下载文件的大小
*/
int __stdcall GetFilesToTempPath(char *httpdomain,char *localIniFile);
/*
	GetFilesToTempPath("WWW.XXX.COM","C:\\UPDATE.INI");
	将"C:\\UPDATE.INI"中指定文件从"WWW.XXX.COM"下载到本地临时目录中
	若不指定httpdomain参数则使用UPDATE.INI文件中的[UPDATE]->domain 
	UPDATE.INI文件格式如下：

[UPDATE]
domain     =		;http服务器的域名，如果不填和登陆服务器使用相同的域名
port       =	80	;http服务器的端口
module     =	20	;当前分布式客户端共有文件个数，相对每一个文件有一个[module_x]与之对应。x从0开始

;分布式客户端所有文件在下面出现的次序应与在agentmanage.sys文件中一一对应

[module_0]
ver  	=	1.0.0.0
path 	=	agentdown/update/agentmanage.sys	;分布式客户端版本控制文件
name 	=	agentmanage.sys			;文件名
[module_1]
ver  	=	1.0.0.0				;文件的版本号，仅用于升级与文件真正版本无关。若此版本号与APP.INI中相应文件版本号不同将导致此文件被升级替换	
path 	=	agentdown/update/SnapPicDll.dll	;相对HTTP服务器根目录的全路径，下载时使用
name 	=	SnapPicDll.dll			;下载后，以此名保存在客户端存储系统上
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
SetDefaultSvrAddr设置默认的服务器地址，
*/

void writelog(char *format,...);//以线程ID为后缀写日志，最大能带5个变参
char *getlogfilename(int ex,char *outPath,int outLen);
void writelogex(bool force,int ex,char *format,...);//以int ex为后缀写日志，最大能带5个变参,若force为强制写日志，否则以g_logWrited变量来决定是否写日志
inline void empty_log(char *,...){}
#define WZX_LONG 1
#ifdef WZX_LONG
#define __writelog writelog 
#else
#define __writelog empty_log
#endif
/*
IWaterNet接口封装了防水墙与服务器通信协议，实现了一些网络基本功能 ！



class IWaterNet
{
public:
	//登录服务器的功能。防水墙框架调用此
	//其中localIP是本地IP；svrIP是服务器IP,svrPort是服务器端口函数开始防水墙与服务器之间的通信。
	virtual int Logon(DWORD localIP,DWORD svrIP,WORD svrPort)=0;

	//心跳功能。防水墙框架的心跳线程调用此函数，定时完成与服务器的心跳活动。tm是当前系统时间！
	virtual int HeartSvr(DWORD tm)=0;

	//防水墙框架调用此函数开始监听服务器下发的命令，每当有命令到来都会通过IMSGRecver接口通知防水墙框架！
	virtual BOOL BeginListen()=0;

	//防水墙框架调用此函数停止监听服务器下发的命令
	virtual void Stop()=0;

	//防水墙框架或“应用模块”调用此函数向服务器发送命令。服务器返回的命令如果需要将通过IMSGRecver接口通知防水墙框架！ 
	virtual BOOL SendCmd(void *pdata,int len)=0;

	//防水墙框架或“应用模块”调用此函数发送本地文件给服务器发，其中：
	//		pPathName本地文件的全路径名；
	//		netName是服务器收到的文件名（不含路径）；
	//		szRule是引起文件上传的命令的规则；
	//		alarm指示文件上传成功以后是否向服务器发送文件到达通知。
	virtual BOOL UploadFileEx(char *pPathName,char *szRule,char *netName,BOOL alarm)=0;

	//防水墙框架或“应用模块”调用此函数获取服务器分配给客户端的ID
	virtual DWORD get_SendID()=0;

	//防水墙框架或“应用模块”调用此函数获取网络通信是否加密
	virtual BOOL get_Encrypt()=0;

	//防水墙框架调用此函数设置网络通信是否加密
	virtual void set_Encrypt(BOOL encry)=0;

	//防水墙框架或“应用模块”调用此函数获取本地IP的点分形式
	virtual char *get_MyIP()=0;
	//防水墙框架或“应用模块”调用此函数获取本地IP
	virtual DWORD get_MydwIP()=0;
	//防水墙框架或“应用模块”调用此函数获取服务器的文件传输端口，但不用于上传文件！
	virtual WORD  get_FilePort()=0;
	//防水墙框架调用此函数获取与服务器心跳的最大时间间隔！
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
防水墙框架调用GetWaterNet获取IWaterNet接口，然后会在IWaterWorker接口的初始化函数中做为参数传给“应用模块”
*/
IWaterNet *__stdcall GetWaterNet(IMSGRecver *irecver);
#endif//RZX_WATER_NET_H