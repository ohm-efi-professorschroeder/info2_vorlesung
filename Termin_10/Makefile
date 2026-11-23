CFLAGS = -Wall -Wextra -g -O0

.PHONY: all clean primzahl

all: primzahl

primzahl: primzahl.c
	gcc ${CFLAGS} -o $@.out primzahl.c

clean:
#		del /f *.out *.o *.so *.a
# Comment line above and uncomment line below for UNIX systems
	rm -rf *.out *.o *.so *.a *.dSYM

include ../debug.mk
