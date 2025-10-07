CFLAGS = -Wall -Wextra -g

bufferoverflow: bufferOverflow.c
	gcc ${CFLAGS} -o bufferOverflow.out bufferOverflow.c

bufferoverflow_simple: bufferOverflow_simple.c
	gcc ${CFLAGS} -o bufferOverflow.out bufferOverflow_simple.c

clean:
#		del /f bufferOverflow.out *.o *‚.so
# Comment line above and uncomment line below for UNIX systems
	rm -f *.out *.o *.so