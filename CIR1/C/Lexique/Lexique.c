#include "Lexique.h"

int main() {
	noeud *lexique = creation("lexiquefar.txt");
	char *mot_anglais;

	/*
	lexique = inserer("avion", "plane", lexique);
	lexique = inserer("noeud", "node", lexique);
	lexique = inserer("age", "age", lexique);
	lexique = inserer("fraise", "strawberry", lexique);
	lexique = inserer("vert", "green", lexique);
	lexique = inserer("robinet", "tap", lexique);
	*/

	if(mot_anglais = traduction("Verrou", lexique)) {
		printf("Traduction de \"Arrondi à l'entier inférieur\" : %s\n", 
			traduction("Arrondi à l'entier inférieur", lexique));
	}
	else {
		fprintf(stderr, "La racine est nulle !\n");
	}

	return EXIT_SUCCESS;
}
