CSV : fonctions.o CSV.o
	gcc -g fonctions.o CSV.o -o CSV
fonctions.o : fonctions.c CSV.h
	gcc -c -g fonctions.c
crypto.o : CSV.c CSV.h
	gcc -c -g CSV.c
clean :
	rm *.o *.gch CSV
