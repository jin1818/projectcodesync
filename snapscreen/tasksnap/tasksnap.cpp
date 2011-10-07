// tasksnap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <afxwin.h>
#include <windows.h>

#include "../../cximage600_full/CxImage/ximage.h"

typedef unsigned char byte;

void Screen(char filename[])
{
    CDC *pDC;//��ĻDC

	HDC   hScrDC= GetDC(NULL) ;

    pDC = CDC::FromHandle(hScrDC);//��ȡ��ǰ������ĻDC
    int BitPerPixel = pDC->GetDeviceCaps(BITSPIXEL);//�����ɫģʽ
    int Width = pDC->GetDeviceCaps(HORZRES);
    int Height = pDC->GetDeviceCaps(VERTRES);
    
    CDC memDC;//�ڴ�DC
    memDC.CreateCompatibleDC(pDC);
    
    CBitmap memBitmap, *oldmemBitmap;//��������Ļ���ݵ�bitmap
    memBitmap.CreateCompatibleBitmap(pDC, Width, Height);
	
    oldmemBitmap = memDC.SelectObject(&memBitmap);//��memBitmapѡ���ڴ�DC
    memDC.BitBlt(0, 0, Width, Height, pDC, 0, 0, SRCCOPY);//������Ļͼ���ڴ�DC
	
	CxImage image ;
	image.CreateFromHBITMAP((HBITMAP)memBitmap);
	if (image.IsValid()){
		if(!image.IsGrayScale()) image.IncreaseBpp(24);
		image.SetJpegQuality(80);
		image.Save(filename,CXIMAGE_FORMAT_JPG);
	}	

    memDC.SelectObject(oldmemBitmap);

	DeleteDC(hScrDC);
}

int loadconfig(const char* filepath)
{
	if ( NULL == filepath) {
		
	}
	return 0 ;
}

int main(int argc, char* argv[])
{

	return 0;
}
