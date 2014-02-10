Banque : fonctions.o Banque.o
	gcc fonctions.o Banque.o -o Banque -g
fonctions.o : fonctions.c Banque.h
	gcc -c fonctions.c -g
crypto.o : Banque.c Banque.h
	gcc -c Banque.c -g
clean :
	rm *.o *.gch Banque
