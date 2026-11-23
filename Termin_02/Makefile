CFLAGS = -Wall -Wextra -g -O0

.PHONY: all clean eingabetest anfangsbuchstabe fehler laengen

all: eingabetest anfangsbuchstabe fehler laengen

eingabetest: eingabeTest.c eingabe.c
	gcc ${CFLAGS} -o $@.out eingabe.c eingabeTest.c

anfangsbuchstabe: anfangsbuchstabe.c eingabe.c
	gcc ${CFLAGS} -o $@.out eingabe.c anfangsbuchstabe.c

fehler: fehler.c
	gcc -w -g -O0 -o $@.out fehler.c

laengen: laengen.c
	gcc -w -g -O0 -o $@.out laengen.c

clean:
#		del /f *.out *.o *.so *.a
# Comment line above and uncomment line below for UNIX systems
	rm -rf *.out *.o *.so *.a *.dSYM

include ../debug.mk
