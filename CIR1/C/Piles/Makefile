Piles : fonctions.o Piles.o
	gcc fonctions.o Piles.o -o Piles
fonctions.o : fonctions.c Piles.h
	gcc -c fonctions.c
crypto.o : Piles.c Piles.h
	gcc -c Piles.c
clean :
	rm *.o *.gch Piles
