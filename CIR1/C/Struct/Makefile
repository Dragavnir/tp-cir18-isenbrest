Struct : fonctions.o Struct.o
	gcc fonctions.o Struct.o -o Struct
fonctions.o : fonctions.c Struct.h
	gcc -c fonctions.c
crypto.o : Struct.c Struct.h
	gcc -c Struct.c
clean :
	rm *.o *.gch Struct
