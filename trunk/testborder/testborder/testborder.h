// testborder.h : testborder Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h�� 
#endif

#include "resource.h"       // ������


// CtestborderApp:
// �йش����ʵ�֣������ testborder.cpp
//

class CtestborderApp : public CWinApp
{
public:
	CtestborderApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CtestborderApp theApp;
