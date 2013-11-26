// Première version du programme : Décommenter toutes les lignes commentées, commenter le bloc while et les lignes 14 et 15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONG_MAX 132
#define LETTRE 'e'

int main() {
	char texte[LONG_MAX+2];
	// int longueur;
	int lettreE = 0;
	// int i = 0;
	char *ptexte = NULL;
	ptexte = texte;
	
	printf("Ecrivez votre texte (%d caractères maximum) : ", LONG_MAX);
	fgets(texte, LONG_MAX+2, stdin);
	texte[strlen(texte)-1] = '\0';

	//longueur = (int)strlen(texte);
	
	/* for(i = 0; i < longueur; i++) {
		if(texte[i] == LETTRE) {
			lettreE++;
		}
	}*/
	
	while(*ptexte != '\0') {
		if(*ptexte == LETTRE) {
			lettreE++;
		}
		ptexte++;
	}
		
	printf("Il y a %d fois la lettre 'e' dans le texte rentré.\n", lettreE);
	
	return EXIT_SUCCESS;
}
