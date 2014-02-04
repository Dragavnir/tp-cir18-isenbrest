Banque : fonctions.o Banque.o
	gcc fonctions.o Banque.o -o Banque
fonctions.o : fonctions.c Banque.h
	gcc -c fonctions.c
crypto.o : Banque.c Banque.h
	gcc -c Banque.c
clean :
	rm *.o *.gch Banque
