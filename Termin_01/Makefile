CFLAGS = -Wall -Wextra -g -O0 -fno-stack-protector

bufferoverflow: bufferOverflow.c
	gcc ${CFLAGS} -o bufferOverflow.out bufferOverflow.c

bufferoverflow_simple: bufferOverflow_simple.c
	gcc ${CFLAGS} -o bufferOverflow.out bufferOverflow_simple.c

bufferoverflow_chain: bufferOverflow_chain.c
	gcc ${CFLAGS} -o bufferOverflow.out bufferOverflow_chain.c

clean:
#		del /f bufferOverflow.out *.o *‚.so
# Comment line above and uncomment line below for UNIX systems
	rm -f *.out *.o *.so