Listes : fonctions.o Listes.o
	gcc -g fonctions.o Listes.o -o Listes
fonctions.o : fonctions.c Listes.h
	gcc -g -c fonctions.c
Listes.o : Listes.c Listes.h
	gcc -g -c Listes.c
clean :
	rm *.o *.gch Listes
