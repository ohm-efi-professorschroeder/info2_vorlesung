CFLAGS = -Wall -Wextra -g

# Namesarchive mit Shared Library bauen
namesarchive_shared_lib: main.o libnamesarchive.so
	gcc ${CFLAGS} -o namesarchive main.o libnamesarchive.so

# Namesarchive mit Static Library bauen
namesarchive_static_lib: main.o libnamesarchive.a
	gcc ${CFLAGS} -o namesarchive main.o libnamesarchive.a
		
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
#	del /f namesarchive.exe *.o *.so *.a
#   Comment line above and uncomment line below for UNIX systems
	rm -f namesarchive *.o *.so *.a