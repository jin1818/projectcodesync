// go123Dlg.h : 头文件
//

#pragma once
#include "reportctrl.h"


// Cgo123Dlg 对话框
class Cgo123Dlg : public CDialog
{
// 构造
public:
	Cgo123Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GO123_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CReportCtrl m_leftView;
};
