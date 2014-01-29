crypto : fonctions.o crypto.o
	gcc fonctions.o crypto.o -o crypto
fonctions.o : fonctions.c crypto.h
	gcc -c fonctions.c
crypto.o : crypto.c crypto.h
	gcc -c crypto.c
clean :
	rm *.o crypto
