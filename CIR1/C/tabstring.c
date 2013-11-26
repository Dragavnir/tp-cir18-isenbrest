/* J'ai eu la flemme de commenter celui-là, peut-être plus tard... */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONG_MAX 10
#define CHIFFRE 2

int main() {
	int tab[LONG_MAX]={0};
	char reponse[LONG_MAX+1];
	int i = 0;
	int * ptab = NULL;
	int chiffre = 0;
	int longueur;
	ptab = tab;
	
	printf("Tapez un entier (longueur max : %d) : ", LONG_MAX);
	
	fgets(reponse, LONG_MAX+2, stdin);
	reponse[strlen(reponse)-1] = '\0';
	longueur = (int)strlen(reponse);
	
	for(i = 0; i < strlen(reponse); i++) {
		tab[i] = (int)reponse[i]-48;
	}
	
	for(i = 0; i < strlen(reponse); i++) {
		printf("%d\n", tab[i]);
	}
	
	while((ptab - tab) < longueur) {
		if(*ptab == CHIFFRE) {
			chiffre++;
		}
		ptab++;
	}
		
	printf("Il y a %d fois le chiffre 2 dans le tableau.\n", chiffre);
	
	return EXIT_SUCCESS;
}
