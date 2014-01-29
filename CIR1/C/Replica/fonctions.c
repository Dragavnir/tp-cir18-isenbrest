#include "Replica.h"

void entreeChaine(char ***ptabChaine, int i) {
	// prologue
	char **tabChaine = *ptabChaine;
	char chaine_saisie[LG_MAX_SAISIE+1];
	int longueur;

	printf("\nTapez la %de chaîne de caractères ou \"fin\" pour arrêter la saisie : ", i+1);
	fgets(chaine_saisie, LG_MAX_SAISIE+2, stdin);
	chaine_saisie[strlen(chaine_saisie)-1] = '\0';
	longueur = strlen(chaine_saisie);
	
	tabChaine = realloc(tabChaine, (i+1)*sizeof(char *));
	tabChaine[i] = calloc(longueur+1, sizeof(char));
	strcpy(tabChaine[i], chaine_saisie);
	
	// epilogue
	
	*ptabChaine = tabChaine;	
}

void liberation(char **tabChaine, int nbChaines) {
	int i;

	for(i = 0; i < nbChaines; i++) {
		free(tabChaine[i]);
		printf("Mémoire occupée par la chaine n°%d libérée.\n\n", i+1);
	}
	
	free(tabChaine);
	printf("Mémoire occupée par le double pointeur libérée.\n");
}
