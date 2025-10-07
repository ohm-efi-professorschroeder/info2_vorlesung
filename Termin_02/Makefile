CFLAGS = -Wall -Wextra -g

eingabetest: eingabeTest.c eingabe.c
	gcc ${CFLAGS} -o eingabeTest.out eingabe.c anfangsbuchstabe.c

anfangsbuchstabe: anfangsbuchstabe.c eingabe.c
	gcc ${CFLAGS} -o anfangsbuchstabe.out eingabe.c anfangsbuchstabe.c

fehler: fehler.c
	gcc -w -g -o fehler.out fehler.c

laengen: laengen.c
	gcc -w -g -o laengen.out laengen.c

clean:
#		del /f *.out *.o *‚.so
# Comment line above and uncomment line below for UNIX systems
	rm -f *.out *.o *.so