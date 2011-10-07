// InternetShopView.h : CInternetShopView 类的接口
//


#pragma once


class CInternetShopView : public CHtmlView
{
protected: // 仅从序列化创建
	CInternetShopView();
	DECLARE_DYNCREATE(CInternetShopView)

// 属性
public:
	CInternetShopDoc* GetDocument() const;

// 操作
public:

// 重写
	public:
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CInternetShopView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // InternetShopView.cpp 的调试版本
inline CInternetShopDoc* CInternetShopView::GetDocument() const
   { return reinterpret_cast<CInternetShopDoc*>(m_pDocument); }
#endif

