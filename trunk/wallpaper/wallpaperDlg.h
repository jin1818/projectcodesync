// wallpaperDlg.h : ͷ�ļ�
//

#pragma once

#include <afxtempl.h>
// CwallpaperDlg �Ի���
class CwallpaperDlg : public CDialog
{
// ����
public:
	CwallpaperDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_WALLPAPER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	BOOL SetWallPaper(CString strPath) ;
	void GetFilePath(CString szPath) ;

// ʵ��
protected:
	HICON m_hIcon;
	CList<CString> picPathList ;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT nIDEvent);
};
