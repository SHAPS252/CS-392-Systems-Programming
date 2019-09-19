// Daniel Shapiro
// "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro

#include <stdio.h>
#include <stdlib.h>
#include "cs392_log.h"

void write_to(char *str){
	// Opens a file in append mode, so that if it doesn't exist, this will create it and write to the end of it, then closes the pointer.
	FILE* fp;
	fp = fopen("cs392_shell.log", "a");
	fputs(str, fp);
	fclose(fp);
	return;
};