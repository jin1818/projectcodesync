#ifndef WATER_WORKER_H
#define WATER_WORKER_H 1
/////////////		waterworker.h		//////////////////
#include "appstruct.h"
#include "rzxsvrseach.h"
/*
class IWaterWorker
{
public:
	//Ӧ�ó�ʼ������ˮǽ��ܻ���ô˺�����ʼ��ÿһ��Ӧ��DLL�����ô�����һ��IWaterNet�ӿں�һ��APPSHAREINFO���ݽṹָ�룬Ӧ�ÿ��Ա�������������Ϊ�Ժ�ʹ�ã�
	//�й�IWaterNet�ӿ���ο�rzxsvrseach.h�ļ�����Ӧ������IWaterNet�ӿ����������ͨ�ŵĽӿڣ�
	virtual BOOL Init(IWaterNet *pnet,PAPPSHAREINFO pappinfo)=0;



	//��ˮǽ��ܵ��ô˺���֪ͨӦ��ģ�飬ϵͳ����ֹͣ��Ӧ���յ���֪ͨӦ��ʼ������Ӧ�õ�׼����
	virtual void Stop()=0;


	//��ˮǽ��ܵ��ô˺���֪ͨӦ��ģ��������������·���Ŀǰ����ģ�鶼���յ�ÿ��������·�֪ͨ��
	//������
	//		DWORD msg�����Է����������
	//		void *pdata�����Է����������ݣ���ṹ�����ͬ����ͬ����˶Բ�������msg�벻Ҫ����
	//		DWORD len��pdata������ָ���ݵĳ���
	virtual int OnMSG(DWORD msg,DWORD len,void *pdata)=0;


	//��ˮǽ����ṩһ�����߳�ģ��Ķ�ʱ����tm�ǵ�ǰϵͳ��ʱ�䣡
	virtual void OnTimer(DWORD tm)=0;


	//��ˮǽ��ܵ���Stop����֪ͨӦ��ģ��ϵͳ����ֹͣ�Ժ����ô˺�����ѯ��Ӧ���Ƿ���Բ�ж�ء���֮ǰ��ˮǽ��ܵ���Stop����֪ͨӦ��ģ��ϵͳ����ֹͣ���˺������������������߳�ֱ������TRUE��
	virtual BOOL CanUnload()=0;
};

��ˮǽӦ�ó���ӿ�IWaterWorker:
ʹ�÷�ˮǽͨ��Э����κ�Ӧ�ÿ�����һ��ʵ�ִ˽ӿڵ�DLL(Ŀǰ����"��ˮǽ"��"���"����Ӧ��ʵ��������ӿ�),�������DLLҪ����IWaterWorker * __stdcall GetWorkerInterface();

����Ĵ�����ʾ��"��ˮǽ"��ܳ�����μ���ʵ��IWaterWorker��ģ�鲢�õ�IWaterWorker�ӿں͵��ó�ʼ������

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