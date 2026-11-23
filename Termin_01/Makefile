CFLAGS = -Wall -Wextra -g -O0 -fno-stack-protector

.PHONY: all clean bufferoverflow bufferoverflow_simple bufferoverflow_chain

all: bufferoverflow bufferoverflow_simple bufferoverflow_chain

bufferoverflow: bufferOverflow.c
	gcc ${CFLAGS} -o $@.out bufferOverflow.c

bufferoverflow_simple: bufferOverflow_simple.c
	gcc ${CFLAGS} -o $@.out bufferOverflow_simple.c

bufferoverflow_chain: bufferOverflow_chain.c
	gcc ${CFLAGS} -o $@.out bufferOverflow_chain.c

clean:
#		del /f *.out *.o *.so *.a
# Comment line above and uncomment line below for UNIX systems
	rm -rf *.out *.o *.so *.a *.dSYM

include ../debug.mk
