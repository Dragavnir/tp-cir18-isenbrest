Listes : fonctions.o Listes.o
	gcc fonctions.o Listes.o -o Listes
fonctions.o : fonctions.c Listes.h
	gcc -c fonctions.c
Listes.o : Listes.c Listes.h
	gcc -c Listes.c
clean :
	rm *.o *.gch Listes
