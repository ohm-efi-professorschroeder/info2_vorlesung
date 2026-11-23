CFLAGS = -Wall -Wextra -g -O0

SORTIERUNGFILES = sortierung.c sortierungsvergleich.c stoppuhr.c zufallsarray.c

.PHONY: all clean sortierungsvergleich

all: sortierungsvergleich

sortierungsvergleich: $(SORTIERUNGFILES)
	gcc ${CFLAGS} -o $@.out $(SORTIERUNGFILES)

clean:
#		del /f *.out *.o *.so *.a
# Comment line above and uncomment line below for UNIX systems
	rm -rf *.out *.o *.so *.a *.dSYM

include ../../debug.mk
