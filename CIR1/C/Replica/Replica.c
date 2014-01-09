#include "Replica.h"

int main() {
	char chaine_saisie[LG_MAX_SAISIE+1];
	char **tab_chaine = NULL;	// **tab_chaine -> Renvoie vers un tableau de pointeurs ; *tab_chaine -> Renvoie vers l'adresse du tableau ; tab_chaine -> Adresse de la zone contenant l'adresse du tableau
	int i = 0;
	int longueur;
	int nb_chaines;

	

	// Saisie
	do {
		printf("\nTapez la %de chaîne de caractères ou \"fin\" pour arrêter la saisie : ", i+1);
		fgets(chaine_saisie, LG_MAX_SAISIE+2, stdin);
		chaine_saisie[strlen(chaine_saisie)-1] = '\0';
		longueur = strlen(chaine_saisie);
		
		tab_chaine = realloc(tab_chaine, (i+1)*sizeof(char *));
		
		tab_chaine[i] = calloc(longueur+1, sizeof(char));
	
		strcpy(tab_chaine[i], chaine_saisie);
		
		i++;
	} while(strcmp(tab_chaine[i-1], "fin"));
	
	nb_chaines = i-1;
	
	printf("\n---------\n\n");
	
	// Affichage
	for(i = 0; i < nb_chaines; i++) {
		printf("Chaine n°%d : %s\n\n", i+1, tab_chaine[i]);
	}
	
	printf("---------\n\n");
	
	// Libération
	for(i = 0; i < nb_chaines; i++) {
		free(tab_chaine[i]);
		printf("Mémoire occupée par la chaine n°%d libérée.\n\n", i+1);
	}
	
	free(tab_chaine);
	printf("Mémoire occupée par le double pointeur libérée.\n");
	
	return EXIT_SUCCESS;
}
