#include "Replica.h"

int main() {
	char **tab_chaine = NULL;	// **tab_chaine -> Renvoie vers un tableau de pointeurs ; *tab_chaine -> Renvoie vers l'adresse du tableau ; tab_chaine -> Adresse de la zone contenant l'adresse du tableau
	int i = 0;
	int longueur;
	int nbChaines;

	// Saisie
	do {
		entreeChaine(&tab_chaine, i);
		i++;
	} while(strcmp(tab_chaine[i-1], "fin"));
	
	nbChaines = i-1;
	
	printf("\n---------\n\n");
	
	// Affichage
	printf("Adresse de tab_chaine : %p\n\nAdresse de *tab_chaine : %p\n\nAdresse de **tab_chaine : %p\n\n", &tab_chaine, &(*tab_chaine), &(**tab_chaine));
	for(i = 0; i < nbChaines; i++) {
		printf("Chaine n°%d : %s ; Adresse : %p\n\n", i+1, tab_chaine[i], &tab_chaine[i]);
	}
	
	printf("---------\n\n");
	
	// Libération
	liberation(tab_chaine, nbChaines);
	
	return EXIT_SUCCESS;
}
