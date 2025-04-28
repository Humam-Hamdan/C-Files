nim_ein_zug: nimzug_exhaustive.o nim_spiel_ein_zug.c Makefile
	gcc -std=c11 -Wall nimzug_exhaustive.o nim_spiel_ein_zug.c -o nim_ein_zug


nim_spiel: nimzug_exhaustive.o  nim_spiel.c Makefile
	gcc -std=c11 -Wall nimzug_exhaustive.o nim_spiel.c -o nim_spiel
	

all: nim_ein_zug nim_spiel 


nimzug_exhaustive.o: nimzug_exhaustive.h nimzug_exhaustive.c Makefile
	gcc -std=c11 -Wall -c nimzug_exhaustive.c


clean:
	rm -f nim_*.o
