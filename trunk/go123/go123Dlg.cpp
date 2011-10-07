// go123Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "go123.h"
#include "go123Dlg.h"
#include ".\go123dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cgo123Dlg �Ի���



Cgo123Dlg::Cgo123Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cgo123Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cgo123Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LEFT_VIEW, m_leftView);
}

BEGIN_MESSAGE_MAP(Cgo123Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// Cgo123Dlg ��Ϣ�������

BOOL Cgo123Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_leftView.InsertColumn(0,"�����ʺ�",LVCFMT_LEFT,20);
	m_leftView.InsertColumn(1,"Զ���ʺ�",LVCFMT_LEFT,20);
	m_leftView.InsertColumn(2,"�����ǳ�",LVCFMT_LEFT,20);
	m_leftView.InsertColumn(3,"Զ���ǳ�",LVCFMT_LEFT,20);

	DWORD dwStyle;
	dwStyle = m_leftView.GetExtendedStyle();
	dwStyle |= LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT |LVS_EX_HEADERDRAGDROP ;
	m_leftView.SetExtendedStyle(dwStyle);	
	m_leftView.SetBkColor(RGB(0xFF, 0xFF, 0xFF));
	m_leftView.SetEditable(TRUE);

	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cgo123Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
HCURSOR Cgo123Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cgo123Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}
