Roach : fonctions.o Roach.o
	gcc fonctions.o Roach.o -lSDL -lSDL_mixer -lSDL_ttf -lm -o Roach
fonctions.o : fonctions.c Roach.h
	gcc -c -lSDL -lSDL_mixer -lSDL_ttf fonctions.c
Roach.o : Roach.c Roach.h
	gcc -c -lSDL -lSDL_mixer -lSDL_ttf Roach.c
clean :
	rm *.o *.gch Roach
