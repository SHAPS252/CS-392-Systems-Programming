// Daniel Shapiro
// "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro

#include "cs392_string.h"


void * cs392_memcpy(void * dst, void * src, unsigned num){

	char* src1;
	char* dst1;
	src1 = (char*) src;
	dst1 = (char*) dst;
	int i = 0;
	while(i<num){
		dst1[i] = src1[i];
		i++;
	}


	return dst;
}


