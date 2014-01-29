Replica : fonctions.o Replica.o
	gcc fonctions.o Replica.o -o Replica
fonctions.o : fonctions.c Replica.h
	gcc -c fonctions.c
crypto.o : Replica.c Replica.h
	gcc -c Replica.c
clean :
	rm *.o *.gch Replica
