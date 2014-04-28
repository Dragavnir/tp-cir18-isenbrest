#include "CSV.h"

void CSVToMail(FILE *src, FILE *dest) {
	int i = 0;
	int j = 0;
	int breakable = 0;
	char *ligne = calloc(LG_MAX, sizeof(char));
	char *virgule = NULL; // Pointe à chaque virgule
	char *guillemets = NULL; // Pointe aux guillemets à la fin de l'adresse

	while(fgets(ligne,LG_MAX,src)) {
		breakable = 0;
		if(j > 0) {
			for(i = 0; i < ITERANCES; i++) {
				virgule = strchr(ligne, ',');
				if(virgule == NULL) {
					// Moins de 48 virgules dans la ligne
					breakable = 1;
				} else {
					*virgule = ' ';
				}
			}

			if(breakable) {
				break;
			}

			ligne = virgule+1;

			guillemets = strchr(ligne, '"');
			if(guillemets != NULL) {
				*guillemets = '\0';

				ligne = guillemets+1;

				guillemets = strchr(ligne, '"');
				if(guillemets != NULL) {
					*guillemets = '\0';
				}
			}
			else {
				virgule = strchr(ligne, ',');
				if(virgule != NULL) {
					*virgule = '\0';
				}
			}

			if(*ligne != '\0') {
				fprintf(dest, "%s\n", ligne);
			}
		}
		j++;
		// j sert à passer la ligne d'en-tete
	}
}
