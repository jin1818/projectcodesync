// wallpaper.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CwallpaperApp:
// �йش����ʵ�֣������ wallpaper.cpp
//

class CwallpaperApp : public CWinApp
{
public:
	CwallpaperApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CwallpaperApp theApp;