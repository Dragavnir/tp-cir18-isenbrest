Tri : fonctions.o Tri.o
	gcc fonctions.o Tri.o -o Tri
fonctions.o : fonctions.c Tri.h
	gcc -c fonctions.c
crypto.o : Tri.c Tri.h
	gcc -c Tri.c
clean :
	rm *.o *.gch Tri
