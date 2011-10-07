// aboutdlg.cpp : implementation of the CAboutDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "aboutdlg.h"
#include ".\aboutdlg.h"

LRESULT CAboutDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	CenterWindow(GetParent());
	return TRUE;
}

LRESULT CAboutDlg::OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	EndDialog(wID);
	return 0;
}


LRESULT CAboutDlg::OnBnClickedOk(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	// TODO: 在此添加控件通知处理程序代码
	OnCloseCmd(wNotifyCode , wID , hWndCtl , bHandled) ;
	return 0;
}

LRESULT CAboutDlg::OnBnClickedAboutUs(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	ShellExecute( NULL,   _T("open"), ABOUTUS_WEBSITE,   NULL,   NULL,   SW_SHOWNORMAL   );
	OnCloseCmd(wNotifyCode , wID , hWndCtl , bHandled) ;
	return 0;
}
