/***********************************************************************************/
/*                           Evolution du TP tableau.c                             */
/*  L'utilisateur peut ici rentrer un nombre non défini de valeurs (voir notes.c)  */
/***********************************************************************************/

/*--------------------*/
/*      Prologue      */
/*--------------------*/

#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------------*/
/*      Chapitre 1 : "One value to rule them all"      */
/*-----------------------------------------------------*/

#define TAILLE_MAX 1000 /* Le programme s'adapte à la valeur prise par TAILLE_MAX */

int main() {
/*------------------------------------------------------*/
/*      Chapitre 2 : "Des conteneurs particuliers"      */
/*------------------------------------------------------*/

	int tab[TAILLE_MAX];
	int i;
	int somme = 0;
	int rangMax; /* Rang de la dernière valeur rentrée */
	
/*-------------------------------------------------------*/
/*      Chapitre 3 : "L'automatisation des entrées"      */
/*-------------------------------------------------------*/

	printf("\nEntrez des valeurs entières (pressez entrée après chaque valeur, tapez un négatif pour arrêter, %d valeurs max) : \n", TAILLE_MAX);
	for(i = 0; i < TAILLE_MAX; i++) { /* On calcule la somme (pour la moyenne) en même temps qu'on récupère les valeurs entrées */
		scanf("%d", &tab[i]);
		if(tab[i] < 0) {
			break;
		}
		somme += tab[i];
	}
	
	if(i >= TAILLE_MAX) { /* Affichage d'un message dans le cas où l'utilisateur atteint le nombre limite de valeurs */
		printf("Vous avez rentré %d valeurs, ce qui est le nombre maximal de valeurs possibles. Le traitement va continuer avec les valeurs que vous avez rentrées.\n", TAILLE_MAX);
	}
	
	rangMax = i; /* Va remplacer TAILLE_MAX dans tableau.c */
	
/*--------------------------------------*/
/*      Chapitre 4 : "Double sens"      */
/*--------------------------------------*/

	printf("\n------- AFFICHAGE DANS L'ORDRE -------\n");
	
	for(i = 0; i < rangMax; i++) {
		printf("\n%dè valeur : %d\nAdresse de tab[%d] : %p\n", i+1, tab[i], i, &tab[i]);
	}
	
	printf("\n--- AFFICHAGE DANS L'ORDRE INVERSE ---\n");
	
	for(i = rangMax-1; i > -1; i--) {
		printf("\n%dè valeur : %d\nAdresse de tab[%d] : %p\n", i+1, tab[i], i, &tab[i]);
	}
	
/*--------------------------------------------*/
/*      Chapitre 5 : "Un air de déjà-vu"      */
/*--------------------------------------------*/

	printf("\n------------ MOYENNE : %.2f ----------\n\n", (float)somme/((float)rangMax+1));
		
	return EXIT_SUCCESS;
}
