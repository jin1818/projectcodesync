// testborderView.h : CtestborderView ��Ľӿ�
//


#pragma once


class CtestborderView : public CView
{
protected: // �������л�����
	CtestborderView();
	DECLARE_DYNCREATE(CtestborderView)

// ����
public:
	CtestborderDoc* GetDocument() const;

// ����
public:

// ��д
	public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CtestborderView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // testborderView.cpp �ĵ��԰汾
inline CtestborderDoc* CtestborderView::GetDocument() const
   { return reinterpret_cast<CtestborderDoc*>(m_pDocument); }
#endif

