// InternetShop.h : InternetShop Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h�� 
#endif

#include "resource.h"       // ������


// CInternetShopApp:
// �йش����ʵ�֣������ InternetShop.cpp
//

class CInternetShopApp : public CWinApp
{
public:
	CInternetShopApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CInternetShopApp theApp;
