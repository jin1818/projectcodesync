
#ifndef __COMMON_H__
#define __COMMON_H__

static char gModulePath[MAX_PATH] = {0} ;

inline const char* getModulePath() {
	const char* path = __argv[0] ;
	const char* p = strrchr(path , '\\') ;
	if (p == NULL) {
		strcpy(gModulePath , path) ;
	}
	else {
		strncpy(gModulePath , path , p - path) ;
	}
	return gModulePath ;
}

#endif