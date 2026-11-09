CFLAGS = -Wall -Wextra -g -I../Termin_02

stringaddierer: stringaddierer.c eingabe.c
	gcc ${CFLAGS} -o stringaddierer.out stringaddierer.c eingabe.c

stringsortierung: stringsortierung.c
	gcc ${CFLAGS} -o stringsortierung.out stringsortierung.c

stringtausch: stringtausch.c
	gcc ${CFLAGS} -o stringtausch.out stringtausch.c

clean:
#		del /f *.out *.o *‚.so
# Comment line above and uncomment line below for UNIX systems
	rm -f *.out *.o *.so