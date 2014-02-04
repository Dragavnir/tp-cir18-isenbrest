#include "Struct.h"

void saisie(point *tabPoint, int taille) {
	int i = 0;

	for(i = 0; i < taille; i++) {
		tabPoint[i].num = i+1;
		
		printf("Valeur de x du %de point : ", i+1);
		scanf("%f", &tabPoint[i].x);
	
		printf("Valeur de y du %de point : ", i+1);
	      	scanf("%f", &tabPoint[i].y);
	}
}

void affiche(point *tabPoint, int taille) {
	int i = 0;

	for(i = 0; i < taille; i++) {
		printf("Coordonnées du %de point : (%.2f;%.2f)\n", tabPoint[i].num,tabPoint[i].x,tabPoint[i].y);
	}
}
