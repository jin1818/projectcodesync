// InternetShopDoc.h :  CInternetShopDoc ��Ľӿ�
//


#pragma once

class CInternetShopDoc : public CDocument
{
protected: // �������л�����
	CInternetShopDoc();
	DECLARE_DYNCREATE(CInternetShopDoc)

// ����
public:

// ����
public:

// ��д
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CInternetShopDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


