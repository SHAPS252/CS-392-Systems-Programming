#  Daniel Shapiro
#  "I pledge my honor that I have abided by the Stevens Honor System." - Daniel Shapiro


libcs392string.so : cs392_strlen.o cs392_memcpy.o
	gcc -shared -fPIC -o libcs392string.so cs392_strlen.o cs392_memcpy.o

cs392_strlen.o : cs392_strlen.c
	gcc -O0 -g -fPIC -c cs392_strlen.c -o cs392_strlen.o

cs392_memcpy.o : cs392_memcpy.c
	gcc -O0 -g -fPIC -c cs392_memcpy.c -o cs392_memcpy.o

clean :
	rm -rf *.o *.so