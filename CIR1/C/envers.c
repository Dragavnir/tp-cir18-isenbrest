#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONG_MAX 30

int main() {

	char texte[LONG_MAX+1] = {0};
	int longueur;
	int i = 0;
	
	printf("Merci d'entrer un mot (30 caractères maximum) : ");
	
	fgets(texte, LONG_MAX+2, stdin);
	texte[strlen(texte)-1] = '\0';
	
	longueur = (int)strlen(texte);
	
	for(i = longueur; i >= 0; i--) {
		printf("%c", texte[i]);
	}
	
	printf("\n");
	
	return EXIT_SUCCESS;

}
