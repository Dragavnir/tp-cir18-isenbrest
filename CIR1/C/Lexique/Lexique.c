#include "Lexique.h"

int main() {
	noeud *lexique = creation("lexiquefar.txt");
	char *mot_anglais;

/*	if(mot_anglais = traduction("Calculatrice", lexique)) {
		printf("Traduction de \"Calculatrice\" : %s\n", 
			mot_anglais);
	}
	else {
		fprintf(stderr, "La racine est nulle !\n");
	}
*/
	parcoursGRD(lexique);


	printf("\nHauteur : %d\n", hauteur(lexique));

	return EXIT_SUCCESS;
}
