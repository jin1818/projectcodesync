// wallpaperDlg.h : 头文件
//

#pragma once

#include <afxtempl.h>
// CwallpaperDlg 对话框
class CwallpaperDlg : public CDialog
{
// 构造
public:
	CwallpaperDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_WALLPAPER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	BOOL SetWallPaper(CString strPath) ;
	void GetFilePath(CString szPath) ;

// 实现
protected:
	HICON m_hIcon;
	CList<CString> picPathList ;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT nIDEvent);
};
