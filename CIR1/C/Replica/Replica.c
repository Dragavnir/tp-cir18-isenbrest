#include "Replica.h"

int main() {
	char chaine_saisie[LG_MAX_SAISIE+1];
	char *chaine;
	int i = 0;
	int longueur;
	
	printf("Tapez une chaîne de caractères : ");
	fgets(chaine_saisie, LG_MAX_SAISIE+2, stdin);
	chaine_saisie[strlen(chaine_saisie)-1] = '\0';
	longueur = strlen(chaine_saisie);
	
	chaine = calloc(longueur+1, sizeof(char));
	
	strcpy(chaine, chaine_saisie);
	
	printf("chaine : %s\n", chaine);
	
	return EXIT_SUCCESS;
}
