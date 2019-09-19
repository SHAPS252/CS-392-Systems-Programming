#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Daniel Shapiro
// "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro

int main(int argc, char ** argv){
	// Checks that there is only 2 inputs
	if(argc != 3){
		return 0;
	}
	int sock;
	// Declaring a socket
	struct sockaddr_in echoserver;
	char buffer[1024];

	if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0){
		printf("Socket error");
		return -1;
	}

	memset(&echoserver, 0, sizeof(echoserver));
	echoserver.sin_family = AF_INET;
	// sets ip address
	echoserver.sin_addr.s_addr = inet_addr(argv[1]);
	// sets port number
	echoserver.sin_port = htons(atoi(argv[2]));
	// connecting
	if(connect(sock, (struct sockaddr *) &echoserver, sizeof(echoserver))<0){
		printf("Connection error");
		return -1;
	}
	// prompts user
	char str[1024];
	printf("Please enter a string: \n");
	fgets(str, 1024, stdin);
	// sends user input to server
	send(sock, str, 1024, 0);
	// receive that input back.
	recv(sock, buffer, 1024, 0);
	// print that input
	printf("%s", buffer);
	// close the socket
	close(sock);
	return 0;
}