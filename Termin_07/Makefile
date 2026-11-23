CFLAGS = -Wall -Wextra -g -O0

.PHONY: all clean callByReference const

all: callByReference const

callByReference: callByReference.c
	gcc ${CFLAGS} -o $@.out callByReference.c

const: const.c
	gcc ${CFLAGS} -o $@.out const.c

clean:
#		del /f *.out *.o *.so *.a
# Comment line above and uncomment line below for UNIX systems
	rm -rf *.out *.o *.so *.a *.dSYM

include ../debug.mk
