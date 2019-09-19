#include <stdio.h>
#include <stdlib.h>

// Daniel Shapiro
// "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro

void cs392_socket_log(char* ip, int port){
	// takes as input a string for the ip address, and an int for the port number. Then opens the
	// cs392_socket.log file in append mode, and writes to that file, then closes that file.
	FILE * fp;
	fp = fopen("./cs392_socket.log", "a");
	fprintf(fp, "%s connected on port %d\n", ip, port);
	fclose(fp);
}