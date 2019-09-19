// Daniel Shapiro
// "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro

#include "cs392_exec.h"
#include "cs392_log.h"
#include "cs392_signal.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main(){
	char str[131072];
	// Prompt user
	printf("cs392_shell $: ");

	//Register handlers
	registration();

	//Loop
	while(1){
		// Get input
		fgets(str, 131072, stdin);
		

		//Log to file
		write_to(str);
		
		// Check if input was "exit"
		int result = strcmp(str, "exit\n");
	
		if(result == 0){
			// If input was exit
			exit(0);
		}else{
			//Run cmd
			command(str);
			memset(str, 0, sizeof(char) * 131072);
			continue;
		}
	}

}