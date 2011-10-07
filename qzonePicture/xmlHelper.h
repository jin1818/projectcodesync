//
//  xmlHelper.h
//  xml manipulate helper class
//  bondshi
//  2006/08/01
//

#ifndef __XML_HELPER_H__
#define __XML_HELPER_H__

#include "tinyxml.h"

//////////////////////////////////////////////////////////////////////////

class XmlNodeWrapper
{
public:
    XmlNodeWrapper(TiXmlNode* pNode) : m_pNode(pNode)
    {}

    XmlNodeWrapper(const XmlNodeWrapper& w)
    {
        m_pNode = w.m_pNode;
    }

    // getNode: 获取的一个与指定路径匹配的XML结点
    // path: 结点路径, eg: /root/parent/child, '/' is document root path
    //       如果path不以'/'开始,则是相对与自身的路径
    // <root><parent><child> ... </child></parent></root>
    // return ptr to object Node if path is valid, otherwise NULL
    TiXmlNode* getNode(const char* szPath);
    
    // baseNode: base for the return node
    // path: relative path between baseNode and object node
    // return ptr to object Node if path is valid, otherwise NULLs
    TiXmlNode* getNode(TiXmlNode& baseNode, const char* path);    

    // getValue: 返回结点的值
    std::string getValue(const char* defaultValue);
    int getValue(int defaultValue);
    double getValue(double defaultValue);

    std::string getValue(const char* szPath, const char* defaultValue);
    int getValue(const char* szPath, int defaultValue);
    double getValue(const char* szPath, double defaultValue);
    
    // getAttrValue: 获取结点的属性值
    std::string getAttrValue(const char* attrName, const char* defaultValue);
    int getAttrValue(const char* attrName, int defaultValue);
    double getAttrValue(const char* attrName, double defaultValue);

    std::string getAttrValue(const char* szPath, const char* attrName, const char* defaultValue);
    
    // setValue: 设置结点的值
    bool setValue(const char* newValue);
    bool setValue(int newValue);
    bool setValue(double newValue);
    
    // setAttrValue: 设置结点的属性值
    bool setAttrValue(const char* attrName, const char* newValue);
    bool setAttrValue(const char* attrName, int newValue);
    bool setAttrValue(const char* attrName, double newValue);
    
    // access support for m_pNode
    TiXmlNode* operator->()
    {
        return m_pNode;
    }

protected:
    TiXmlNode* m_pNode;
};


inline TiXmlNode* 
    XmlNodeWrapper::getNode(const char* szPath)
{
    TiXmlNode* baseNode = m_pNode;
    if (szPath[0] == '/')
        baseNode = m_pNode->GetDocument();

    if ( !baseNode )
        return NULL;

    return getNode(*baseNode, szPath);
}

inline TiXmlNode* 
    XmlNodeWrapper::getNode(TiXmlNode& baseNode, const char* path)
{
    char nodeName[256] = {0};
    TiXmlNode* pNode = &baseNode;
    
    while (path && (*path != '\0') && pNode) 
    {
        if (*path == '/') 
            ++path;
        
        char* temp = strchr(path, '/');
        memset(nodeName, 0, sizeof(nodeName));
        
        if (temp == NULL)
            strcpy(nodeName, path);
        else
            strncpy(nodeName, path, temp - path); 
        
        if (strcmp(nodeName, ".") == 0)
        {
            // no operation
        }
        else if (strcmp(nodeName, "..") == 0)
        {
            pNode = pNode->Parent();
        }
        else
        {
            pNode = pNode->FirstChild(nodeName);
        }
        
        if ( temp )
            path = temp + 1;
        else
            path = temp;
    }
    
    return pNode;    
}

inline std::string 
    XmlNodeWrapper::getValue(const char* defaultValue)
{
    const char* pValue = NULL;
    int t = m_pNode->Type();
    
    if (t == TiXmlNode::ELEMENT)
    {
        const TiXmlNode* pNode = m_pNode->FirstChild();
        if ( pNode )
        {
            t = pNode->Type();
            if (t == TiXmlNode::TEXT)
                pValue = pNode->Value();
        }     
    }
    else if (t == TiXmlNode::TEXT)
    {
        pValue = m_pNode->Value();
    }
    
    if ( !pValue )
        pValue = defaultValue;

    return (pValue)?pValue:"";     
}

inline int 
    XmlNodeWrapper::getValue(int defaultValue)
{
    std::string v;
    v = getValue((char*)NULL);
    if (v.empty())
        return defaultValue;

    return atoi(v.c_str());
}

inline double
    XmlNodeWrapper::getValue(double defaultValue)
{
    std::string v;
    v = getValue((char*)NULL);
    if (v.empty())
        return defaultValue;

    return strtod(v.c_str(), NULL);    
}

inline std::string
    XmlNodeWrapper::getValue(const char* szPath, const char* defaultValue)
{
    TiXmlNode* pNode = getNode(szPath);
    if ( !pNode )
        return defaultValue?defaultValue:"";

    return XmlNodeWrapper(pNode).getValue(defaultValue);
}

inline int
    XmlNodeWrapper::getValue(const char* szPath, int defaultValue)
{
    TiXmlNode* pNode = getNode(szPath);
    if ( !pNode )
        return defaultValue;        
    
    return XmlNodeWrapper(pNode).getValue(defaultValue);
}

inline double 
    XmlNodeWrapper::getValue(const char* szPath, double defaultValue)
{
    TiXmlNode* pNode = getNode(szPath);
    if ( !pNode )
        return defaultValue;        

    return XmlNodeWrapper(pNode).getValue(defaultValue);
}

inline bool 
    XmlNodeWrapper::setValue(const char* newValue)
{
    TiXmlNode* pNode = m_pNode;
    bool is_new = false;
    
    if (pNode && pNode->Type() == TiXmlNode::ELEMENT)
    {
        TiXmlNode* pContent = pNode->FirstChild();
        if ( !pContent )
        {
            //　结点内容不存在，则新建内容子结点
            pContent = pNode->InsertEndChild(TiXmlText(newValue));
            is_new = true;
        }
        
        pNode = pContent;
    }  
    
    if (!pNode || pNode->Type() != TiXmlNode::TEXT)
        return false;
    
    if ( !is_new )
        pNode->SetValue(newValue);
    
    return true;
}

inline bool 
    XmlNodeWrapper::setValue(int newValue)
{
    char buff[32] = {0};
    sprintf(buff, "%d", newValue);
    return setValue(buff);
}

inline bool
    XmlNodeWrapper::setValue(double newValue)
{
    char buff[32] = {0};
    sprintf(buff, "%f", newValue);
    return setValue(buff);  
}

inline std::string  
    XmlNodeWrapper::getAttrValue(const char* attrName, const char* defaultValue)
{    
    TiXmlElement* pElem = NULL;
    std::string v;
    
    if (m_pNode)
        pElem = m_pNode->ToElement();  
    
    if ( !pElem )
    {
        if (defaultValue)
            v = defaultValue;
        return v;
    }
    
    const char* pValue = pElem->Attribute(attrName);
    if ( pValue )
        v = pValue;
    else if ( defaultValue )
        v = defaultValue;
    
    return v;     
}

inline int
    XmlNodeWrapper::getAttrValue(const char* attrName, int defaultValue)
{
    std::string v;
    v = getAttrValue(attrName, "");
    if ( !v.empty() )
        return atoi(v.c_str());
    
    return defaultValue;    
}

inline double
    XmlNodeWrapper::getAttrValue(const char* attrName, double defaultValue)
{
    std::string v;
    v = getAttrValue(attrName, "");
    if ( !v.empty() )
        return strtod(v.c_str(), NULL);
    
    return defaultValue;    
}

inline std::string
    XmlNodeWrapper::getAttrValue(const char* szPath, const char* attrName, const char* defaultValue)
{
    TiXmlNode* pNode = getNode(szPath);
    if (!pNode)
        return defaultValue?defaultValue:"";

    return XmlNodeWrapper(pNode).getAttrValue(attrName, defaultValue);
}

inline bool
    XmlNodeWrapper::setAttrValue(const char* attrName, const char* newValue)
{
    TiXmlNode* pNode = m_pNode;
    if ( !pNode )
        return false; 
    
    TiXmlElement* pElem = pNode->ToElement();
    if ( !pElem )
        return false;
    
    pElem->SetAttribute(attrName, newValue);
    return true;
}

inline bool
    XmlNodeWrapper::setAttrValue(const char* attrName, int newValue)
{
    char buff[32] = {0};
    sprintf(buff, "%d", newValue);
    return setAttrValue(attrName, buff);
}

inline bool
    XmlNodeWrapper::setAttrValue(const char* attrName, double newValue)
{
    char buff[32] = {0};
    sprintf(buff, "%f", newValue);
    return setAttrValue(attrName, buff); 
}


//////////////////////////////////////////////////////////////////////////

#endif // __XML_HELPER_H__
