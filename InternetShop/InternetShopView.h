// InternetShopView.h : CInternetShopView ��Ľӿ�
//


#pragma once


class CInternetShopView : public CHtmlView
{
protected: // �������л�����
	CInternetShopView();
	DECLARE_DYNCREATE(CInternetShopView)

// ����
public:
	CInternetShopDoc* GetDocument() const;

// ����
public:

// ��д
	public:
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CInternetShopView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // InternetShopView.cpp �ĵ��԰汾
inline CInternetShopDoc* CInternetShopView::GetDocument() const
   { return reinterpret_cast<CInternetShopDoc*>(m_pDocument); }
#endif

