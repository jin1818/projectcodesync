

#include <afxinet.h> 

int splitString(CString str, char split, CStringArray& strArray)  
{
	strArray.RemoveAll();  
	CString strTemp = str; //此赋值不能少  
	int nIndex = 0; //  
	while( 1 )  
	{  
		nIndex = strTemp.Find( split );  
		if( nIndex >= 0 )  
		{  
			strArray.Add( strTemp.Left( nIndex ) );  
			strTemp = strTemp.Right( strTemp.GetLength() - nIndex - 1 );  
		}  
		else break;  
	}  
	strArray.Add( strTemp );
	return strArray.GetSize();  
}  

CString getList(CString  strURL , CString cookie) 
{

	CInternetSession session;
	CHttpFile *file = NULL;
	CString strHtml = "";   //存放网页数据
	try{
/*		CStringArray cookies;
		splitString(cookie , ';' , cookies) ;
		for(int i =0 ; i < cookies.GetSize() ; i++ ) 
		{
			CString item = cookies.GetAt(i) ;
			CString name = "" ;
			CString value = "" ;
			int nIndex = item.Find('=') ;
			if ( nIndex  >= 0 ) {
				name = item.Left(nIndex) ;
				value = item.Right(item.GetLength() - nIndex - 1) ;
			}
			else {
				name = item ;
			}
			session.SetCookie(strURL, name , value) ;
		}
*/		file = (CHttpFile*)session.OpenURL(strURL);
	}catch(CInternetException * m_pException){
		file = NULL;
		m_pException->m_dwError;
		m_pException->Delete();
		session.Close();
		return "";
	}
	CString strLine;
	if(file != NULL){
		while(file->ReadString(strLine) != NULL){
			strHtml += strLine;
		}
	}else{
		return "";
	}
	session.Close();
	file->Close();
	delete file;
	file = NULL;
	return strHtml ;
}

