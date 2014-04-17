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

char *traduction(char *fr, noeud *racine) {
	if(!racine) {
		return NULL;
	}
	if(!strcmp(racine->francais, fr)) {
		return racine->anglais;
	}
	else if(strcmp(racine->francais, fr) > 0) {
		return traduction(fr, racine->gauche);
	}
	else if(strcmp(racine->francais, fr) < 0) {
		return traduction(fr, racine->droite);
	}
}

noeud *creation(char *nomfic) {
	FILE *fp;
	char chaine[LG_MAX];
	char *anglais = NULL;
	char *separateur = NULL;
	noeud *lexique = NULL;

	fp = fopen(nomfic, "r");

	if(fp == NULL) {
		printf("Fichier inexistant.\n");
		exit(-1);
	}

	while(fgets(chaine,LG_MAX,fp)) {
		chaine[strlen(chaine)-1] = '\0';
		separateur = strchr(chaine, ':');
		if(separateur != NULL) {
			*separateur = '\0';
			lexique = inserer(chaine, separateur+1, lexique);
		}
	}

	fclose(fp);

	return lexique;
}
