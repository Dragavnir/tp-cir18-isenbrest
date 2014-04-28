#include "Lexique.h"

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
