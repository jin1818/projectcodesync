// testborderDoc.h :  CtestborderDoc ��Ľӿ�
//


#pragma once

class CtestborderDoc : public CDocument
{
protected: // �������л�����
	CtestborderDoc();
	DECLARE_DYNCREATE(CtestborderDoc)

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
	virtual ~CtestborderDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


