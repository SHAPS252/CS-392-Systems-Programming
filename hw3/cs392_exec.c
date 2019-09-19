// Daniel Shapiro
// "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro

#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include "cs392_exec.h"

void command(char* str){
	int pid = fork();
	// Call fork
	if(pid < 0){
		// If an error occurs
		perror("An error has occurred.");
		// printf("An error has occurred.");
	}
	if(pid == 0){
		// Child process
		// Tokenizes input into a malloc and then calls execvp on that malloc
		char** stringArray;
		stringArray = malloc(sizeof(char*));
		memset(stringArray, 0, sizeof(char));
		int i = 0;
		int j = 1;
		char* pch = strtok(str, "\n ");
		while(pch != NULL){
			stringArray[i] = pch;
			stringArray = (char**) realloc(stringArray, sizeof(char*)*(j + 1));
			pch = strtok(NULL, "\n ");
			i++;
			j++;
		}
		stringArray[i] = NULL;
		execvp(stringArray[0], stringArray);
		free(stringArray);
		free(pch);
		exit(1);
	}
	if(pid > 0){
		// Parent process waits for child to finish before resuming
		wait(NULL);
		printf("cs392_shell $: ");
	}
}