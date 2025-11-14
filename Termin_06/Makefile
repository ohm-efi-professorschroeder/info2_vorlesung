CFLAGS = -Wall -Wextra -g -I../Termin_02

stringaddierer: stringaddierer.c eingabe.c
	gcc ${CFLAGS} -o stringaddierer.out stringaddierer.c eingabe.o

stringsortierung: stringsortierung.c eingabe.c
	gcc ${CFLAGS} -o stringsortierung.out stringsortierung.c eingabe.c

stringtausch: stringtausch.c eingabe.c
	gcc ${CFLAGS} -o stringtausch.out stringaddierer.c eingabe.c

# eingabe.c aus Termin 2
eingabe.c:
	gcc ${CFLAGS} -c ../Termin_02/eingabe.c

clean:
#		del /f *.out *.o *‚.so
# Comment line above and uncomment line below for UNIX systems
	rm -f *.out *.o *.so