#ifndef WATER_WORKER_H
#define WATER_WORKER_H 1
/////////////		waterworker.h		//////////////////
#include "appstruct.h"
#include "rzxsvrseach.h"
/*
class IWaterWorker
{
public:
	//应用初始化。防水墙框架会调用此函数初始化每一个应用DLL。调用传递了一个IWaterNet接口和一个APPSHAREINFO数据结构指针，应用可以保留这两个变量为以后使用！
	//有关IWaterNet接口请参考rzxsvrseach.h文件。对应用来讲IWaterNet接口是与服务器通信的接口！
	virtual BOOL Init(IWaterNet *pnet,PAPPSHAREINFO pappinfo)=0;



	//防水墙框架调用此函数通知应用模块，系统将被停止。应用收到此通知应开始做结束应用的准备！
	virtual void Stop()=0;


	//防水墙框架调用此函数通知应用模块服务器有命令下发，目前所有模块都会收到每个命令的下发通知！
	//参数：
	//		DWORD msg是来自服务器的命令；
	//		void *pdata是来自服务器的数据，其结构因命令不同而不同，因此对不能理解的msg请不要处理！
	//		DWORD len是pdata参数所指数据的长度
	virtual int OnMSG(DWORD msg,DWORD len,void *pdata)=0;


	//防水墙框架提供一个由线程模拟的定时器，tm是当前系统的时间！
	virtual void OnTimer(DWORD tm)=0;


	//防水墙框架调用Stop函数通知应用模块系统将被停止以后会调用此函数，询问应用是否可以补卸载。若之前防水墙框架调用Stop函数通知应用模块系统将被停止，此函数必须阻塞当调用线程直至返回TRUE！
	virtual BOOL CanUnload()=0;
};

防水墙应用程序接口IWaterWorker:
使用防水墙通信协议的任何应用可以是一个实现此接口的DLL(目前包括"防水墙"与"广告"两个应用实现了这个接口),并且这个DLL要导出IWaterWorker * __stdcall GetWorkerInterface();

下面的代码演示了"防水墙"框架程序如何加载实现IWaterWorker的模块并得到IWaterWorker接口和调用初始化函数

typedef IWaterWorker *( __stdcall *WORDFUNC)(); 
HMODULE hmodule;
IWaterWorker *worker;
WORDFUNC func;

if(hmodule=::LoadLibrary("c:\\app.dll"))
{
	if(func=(WORDFUNC)::GetProcAddress(hmodule,"GetWorkerInterface"))
	{
		if(worker=func())
		{
			if(!worker->Init(pnet,pappinfo))
			{
				worker=NULL;
				::FreeLibrary(hmodule);
			}
		}
	}
}*/
class IWaterWorker
{
public:
	virtual BOOL Init(IWaterNet *pnet,PAPPSHAREINFO pappinfo)=0;
	virtual void Stop()=0;
	virtual int OnMSG(DWORD msg,DWORD len,void *pdata)=0;
	virtual void OnTimer(DWORD tm)=0;
	virtual BOOL CanUnload()=0;
};
IWaterWorker * __stdcall GetWorkerInterface();
#endif//  WATER_WORKER_H 