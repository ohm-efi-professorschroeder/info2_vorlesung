CFLAGS = -Wall -Wextra -g -O0

.PHONY: all clean namesarchive_shared_lib namesarchive_static_lib

all: namesarchive_static_lib namesarchive_shared_lib

# Namesarchive mit Shared Library bauen
namesarchive_shared_lib: main.o libnamesarchive.so
	gcc ${CFLAGS} -o $@.out main.o libnamesarchive.so

# Namesarchive mit Static Library bauen
namesarchive_static_lib: main.o libnamesarchive.a
	gcc ${CFLAGS} -o $@.out main.o libnamesarchive.a

# Einzelne Object-Files kompileren
main.o: main.c
	gcc -c ${CFLAGS} main.c

namesarchive.o: namesarchive.c namesarchive.h
	gcc -c ${CFLAGS} namesarchive.c

# Static Library bauen
libnamesarchive.a: namesarchive.o
	ar cr libnamesarchive.a namesarchive.o

# Shared Library bauen
libnamesarchive.so: namesarchive.o
	gcc -shared -o libnamesarchive.so namesarchive.o

clean:
#		del /f *.out *.o *.so *.a
# Comment line above and uncomment line below for UNIX systems
	rm -rf *.out *.o *.so *.a *.dSYM

include ../debug.mk
