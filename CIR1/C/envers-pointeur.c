#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONG_MAX 30

int main() {

	char texte[LONG_MAX+1] = {0};
	char * ptexte = texte;
	
	printf("Merci d'entrer un mot (30 caractères maximum) : ");
	
	fgets(texte, LONG_MAX+2, stdin);
	texte[strlen(texte)-1] = '\0';
	
	ptexte += strlen(texte);
	
	while(ptexte >= texte) {
		printf("%c", *ptexte);
		ptexte--;
	}
	
	printf("\n");
	
	return EXIT_SUCCESS;

}
