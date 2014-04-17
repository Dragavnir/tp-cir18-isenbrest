Lexique : fonctions.o Lexique.o
	gcc -g fonctions.o Lexique.o -o Lexique
fonctions.o : fonctions.c Lexique.h
	gcc -c -g fonctions.c
crypto.o : Lexique.c Lexique.h
	gcc -c -g Lexique.c
clean :
	rm *.o *.gch Lexique
