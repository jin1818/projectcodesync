// go123Dlg.h : ͷ�ļ�
//

#pragma once
#include "reportctrl.h"


// Cgo123Dlg �Ի���
class Cgo123Dlg : public CDialog
{
// ����
public:
	Cgo123Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GO123_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CReportCtrl m_leftView;
};
