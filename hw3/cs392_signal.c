// Daniel Shapiro
// "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "cs392_signal.h"


static void hdl (int sig, siginfo_t *siginfo, void *context){
	// Handler function for SIGINT and SIGTSTP
		if(sig == SIGINT){
			printf("SIGINT Received\n");
			
		};
		if(sig == SIGTSTP){
			printf("SIGTSTP Received\n");
			
		};
	};
void registration(){
	// Registers the handler function to call sigaction.
	// Uses the SA_SIGINFO flag to switch from the default.
		struct sigaction act;
		memset (&act,  '\0', sizeof(act));
		act.sa_sigaction = &hdl;
		act.sa_flags = SA_SIGINFO;
		if(sigaction(SIGINT, &act, NULL) < 0){
			perror("Sigaction");
			
		}
		if(sigaction(SIGTSTP, &act, NULL) < 0){
			perror("Sigaction");
			
		}

}