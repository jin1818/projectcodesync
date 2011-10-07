// ImgSkin.cpp: implementation of the CImgSkin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImgSkin.h"
#include "afxconv.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "ZvLib.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
Image * CImgSkin::m_pImg = NULL;

CImgSkin::CImgSkin()
{

}

CImgSkin::~CImgSkin()
{

}

bool CImgSkin::Load(const char * szPath, const char * szControlType)
{
	if(szPath==NULL || strcmp(szPath,"")==0)
		return true;

	m_szSkinPath = szPath;

	TiXmlDocument XmlDoc(szPath);
	TiXmlNode * pXmlNode;
	char * szValue;

	if(!XmlDoc.LoadFile())
	{
		SetErr("打开皮肤文件 %s 错误:%s", szPath, XmlDoc.ErrorDesc());
		return false;
	}

	szValue = (char*)(XmlDoc.FirstChild("Skin")->FirstChild("ImgPath")->FirstChild()->Value());

	CString szImgPath;
	szImgPath.Format("%s%s", CZvLib::GetFileDirPath(szPath).c_str(), szValue);

	WCHAR szWch[MAX_PATH] = {0};
	MultiByteToWideChar( CP_ACP, 0, szImgPath.GetBuffer(szImgPath.GetLength()), -1, szWch, MAX_PATH) ;

	Image * pImg;

	pImg = Image::FromFile(szWch);

	if(pImg==NULL)
	{
		SetErr("打开文件 %s 错误。", szImgPath);
		return false;
	}

	Unload();

	m_pImg = pImg;

	// <Rect>
	pXmlNode = XmlDoc.FirstChild("Skin")->FirstChild("Control")->FirstChild(szControlType)->FirstChild("Rect");
	if(pXmlNode)
		pXmlNode = pXmlNode->FirstChild();
	
	vector<string> vtRect;
	
	for(; pXmlNode!=NULL; pXmlNode = pXmlNode->NextSibling())
	{
		szValue = (char*)pXmlNode->FirstChild()->Value();

		CZvLib::SplitString(szValue, ",", vtRect);
		if(vtRect.size()==4)
		{
			Rect rc(atoi(vtRect[0].c_str()), atoi(vtRect[1].c_str()), atoi(vtRect[2].c_str()), atoi(vtRect[3].c_str()));

			m_mapRect[pXmlNode->Value()] = rc;
		}
	}

	// <Color>
	pXmlNode = XmlDoc.FirstChild("Skin")->FirstChild("Control")->FirstChild(szControlType)->FirstChild("Color");
	if(pXmlNode)
		pXmlNode = pXmlNode->FirstChild();
	
	for(; pXmlNode!=NULL; pXmlNode = pXmlNode->NextSibling())
	{
		szValue = (char*)pXmlNode->FirstChild()->Value();

		CZvLib::SplitString(szValue, ",", vtRect);
		if(vtRect.size()==3)
		{
			m_mapColor[pXmlNode->Value()] = RGB(atoi(vtRect[0].c_str()), atoi(vtRect[1].c_str()), atoi(vtRect[2].c_str()));
		}
	}
	
	return true;
}

void CImgSkin::Unload()
{
	if(IsLoaded())
	{			
		delete m_pImg;
		m_pImg = NULL;
	}
}

bool CImgSkin::IsLoaded()
{
	return m_pImg!=NULL;
}
