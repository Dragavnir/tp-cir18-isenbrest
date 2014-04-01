#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LG_MAX_LIGNE 256

int main() {
	char chaine[LG_MAX_LIGNE];
	int i = 1;
	FILE *fp = NULL;

	printf("\nNom à donner au fichier : ");
	fgets(chaine, LG_MAX_LIGNE, stdin);
	chaine[strlen(chaine)-1] = '\0';
	
	fp = fopen(chaine, "a+");

	if(fp == NULL || !strcmp(chaine, "files.c")) {
		printf("Erreur : Ne peut pas ouvrir le fichier !\n");
		exit(-1);
	}

	while(strcmp(chaine, "0")) {
		printf("Tapez la ligne %d (ou 0 pour terminer) : ", i++);
		fgets(chaine, LG_MAX_LIGNE, stdin);
		chaine[strlen(chaine)-1] = '\0';
		fprintf(fp, "%s\n", chaine);
	}

	fclose(fp);
}
