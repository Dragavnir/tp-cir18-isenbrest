SDL : fonctions.o SDL.o
	gcc fonctions.o SDL.o -lSDL -o SDL
fonctions.o : fonctions.c SDL.h
	gcc -c fonctions.c
crypto.o : SDL.c SDL.h
	gcc -c SDL.c
clean :
	rm *.o *.gch SDL
