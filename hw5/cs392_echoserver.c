#include "cs392_log.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/un.h>
#include <arpa/inet.h>

// Daniel Shapiro
// "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro

int main(int argc, char **argv){
	// Checks that there is only one input
	if(argc != 2){
		return 0;
	}
	// Declare a socket
	int serversock, clientsock;

	struct sockaddr_in echoserver, echoclient;
	char buffer[1024];

	if((serversock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	memset(&echoserver, 0, sizeof(echoserver));
	echoserver.sin_family = AF_INET;
	// Allow for any connection and port to be input
	echoserver.sin_addr.s_addr = htonl(INADDR_ANY);
	echoserver.sin_port = htons(atoi(argv[1]));
	if(bind(serversock, (struct sockaddr *) &echoserver, sizeof(echoserver)) < 0){
		perror("Bind fail");
		exit(EXIT_FAILURE);
	}
	// Restrict it to listen to at most 5 people

	if(listen(serversock, 5) < 0){
	perror("Listen fail");
	exit(EXIT_FAILURE);
	}
		while(1){
		// Blocking while waiting to accept clients
			socklen_t cli_addr_size = sizeof(echoclient);
			if((clientsock = accept(serversock, (struct sockaddr *) &echoclient, &cli_addr_size)) < 0){
				perror("Accept error");
				exit(EXIT_FAILURE);
			}
			char *ip = inet_ntoa(echoclient.sin_addr);
			// Log to file what ip connects on what port
			cs392_socket_log(ip, atoi(argv[1]));

			// Receives and then sends back what was read.
			recv(clientsock, buffer, 1024, 0);
			send(clientsock, buffer, 1024, 0);
			// close the connected client
			close(clientsock);

	}

	return 0;

}