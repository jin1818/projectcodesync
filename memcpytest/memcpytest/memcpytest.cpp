
#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"

int a[2][2]={{1},{2,3}};

#define print(x)  printf("the no,"#x",is") 

void * memcpyex(void * dst , void * src , size_t count)
{
	if ( NULL == dst || NULL == src || count <= 0 )
		return NULL ;

	char* pdest = (char* )dst;
	const char* psrc = (char* )src;

	if( pdest>psrc)
	{
		for( size_t i=count-1; i!=-1; --i )
			pdest[i] = psrc[i];
	}
	else
	{
		for( size_t i=0; i < count ; i++ )
			pdest[i] = psrc[i];
	}
	return dst;
}

int _tmain()
{
	print(a) ;
	printf("%d" , a[0][1]) ;
	return 0 ;
}
