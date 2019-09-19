// Daniel Shapiro
// "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro



#include "cs392_string.h"

unsigned cs392_strlen(char *str){
	unsigned length = 0;
	int i = 0;
	while(str[i] != '\0'){
		length++;
		i++;
	}
	return length;
}