CFLAGS = -Wall -Wextra -g

SORTIERUNGFILES = sortierung.c sortierungsvergleich.c stoppuhr.c zufallsarray.c

sortierungsvergleich: $(SORTIERUNGFILES)
	gcc ${CFLAGS} -o sortierungsvergleich.out $(SORTIERUNGFILES)

clean:
#		del /f *.out *.o *‚.so
# Comment line above and uncomment line below for UNIX systems
	rm -f *.out *.o *.so