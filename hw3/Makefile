# Daniel Shapiro
# "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro

cs392_shell : cs392_shell.o cs392_exec.o cs392_signal.o cs392_log.o
	gcc -o  cs392_shell cs392_shell.o cs392_exec.o cs392_signal.o cs392_log.o

cs392_shell.o : cs392_shell.c
	gcc -c -g cs392_shell.c 

cs392_exec.o : cs392_exec.c cs392_exec.h
	gcc -c -g cs392_exec.c 

cs392_signal.o : cs392_signal.c cs392_signal.h
	gcc -c -g cs392_signal.c 

cs392_log.o : cs392_log.c cs392_log.h
	gcc -c -g cs392_log.c 

clean :
	rm -rf *.o cs392_shell