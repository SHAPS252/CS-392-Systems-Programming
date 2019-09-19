# Daniel Shapiro
# "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro

all: cs392_echoserver cs392_echoclient

cs392_echoserver: cs392_echoserver.o cs392_log.o
	gcc -g cs392_echoserver.o cs392_log.o -o cs392_echoserver

cs392_echoclient: cs392_echoclient.o
	gcc -g cs392_echoclient.o -o cs392_echoclient

cs392_echoclient.o: cs392_echoclient.c
	gcc -g -c cs392_echoclient.c -o cs392_echoclient.o

cs392_log.o: cs392_log.c
	gcc -g -c cs392_log.c -o cs392_log.o

cs392_echoserver.o: cs392_echoserver.c
	gcc -c -g cs392_echoserver.c -o cs392_echoserver.o


clean:
	rm -rf *.o cs392_echoclient cs392_echoserver