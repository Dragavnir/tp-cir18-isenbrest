#include "Lexique.h"

noeud *inserer(char *fr, char *en, noeud *racine) {

	if(racine == NULL) {
		racine = malloc(sizeof(noeud));
		racine->francais = malloc(strlen(fr)*sizeof(char));
		racine->anglais = malloc(strlen(en)*sizeof(char));
		strcpy(racine->francais, fr);
		strcpy(racine->anglais, en);
		racine->gauche = NULL;
		racine->droite = NULL;
		
		return racine;
	}

	else {
		if(strcmp(racine->francais, fr) > 0) {
			racine->gauche = inserer(fr, en, racine->gauche);
		}
		else if(strcmp(racine->francais, fr) < 0) {
			racine->droite = inserer(fr, en, racine->droite);
		}
		else {
			//printf("Le mot existe déjà !\n");
		}
		return racine;
	}
}
