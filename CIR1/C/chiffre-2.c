// Variante de lettre-e.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONG_MAX 10
#define CHIFFRE  2

int main() {
	int tab[LONG_MAX] = {2,4,1,2,8,3,4,2,5,2};
	int chiffre = 0;
	int *ptab = NULL;
	ptab = tab;

	while(*ptab < LONG_MAX) {
		if(*ptab == CHIFFRE) {
			chiffre++;
		}
		ptab++;
	}
		
	printf("Il y a %d fois le chiffre 2 dans le tableau.\n", chiffre);
	
	return EXIT_SUCCESS;
}
