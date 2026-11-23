CFLAGS = -Wall -Wextra -g -O0 -I../Termin_02

.PHONY: all clean stringaddierer stringsortierung stringtausch

all: stringaddierer stringsortierung stringtausch

stringaddierer: stringaddierer.c eingabe.c
	gcc ${CFLAGS} -o $@.out stringaddierer.c eingabe.c

stringsortierung: stringsortierung.c
	gcc ${CFLAGS} -o $@.out stringsortierung.c

stringtausch: stringtausch.c
	gcc ${CFLAGS} -o $@.out stringtausch.c

clean:
#		del /f *.out *.o *.so *.a
# Comment line above and uncomment line below for UNIX systems
	rm -rf *.out *.o *.so *.a *.dSYM

include ../debug.mk
