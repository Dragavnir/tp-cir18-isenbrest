/*--------------------*/
/*      Prologue      */
/*--------------------*/

#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------------*/
/*      Chapitre 1 : "One value to rule them all"      */
/*-----------------------------------------------------*/

#define TAILLE_MAX 5 /* Le programme s'adapte à la valeur prise par TAILLE_MAX */

int main() {
/*------------------------------------------------------*/
/*      Chapitre 2 : "Des conteneurs particuliers"      */
/*------------------------------------------------------*/

	int tab[TAILLE_MAX];
	int i;
	int somme = 0;
	
/*-------------------------------------------------------*/
/*      Chapitre 3 : "L'automatisation des entrées"      */
/*-------------------------------------------------------*/

	printf("\nEntrez %d valeurs entières (pressez entrée après chaque valeur) : \n", TAILLE_MAX);
	for(i = 0; i < TAILLE_MAX; i++) { /* On calcule la somme (pour la moyenne) en même temps qu'on récupère les valeurs entrées */
		scanf("%d", &tab[i]);
		somme += tab[i];
	}
	
/*--------------------------------------*/
/*      Chapitre 4 : "Double sens"      */
/*--------------------------------------*/

	printf("\n------- AFFICHAGE DANS L'ORDRE -------\n");
	
	for(i = 0; i < TAILLE_MAX; i++) {
		printf("\n%dè valeur : %d\nAdresse de tab[%d] : %p\n", i+1, tab[i], i, &tab[i]);
	}
	
	printf("\n--- AFFICHAGE DANS L'ORDRE INVERSE ---\n");
	
	for(i = TAILLE_MAX-1; i > -1; i--) {
		printf("\n%dè valeur : %d\nAdresse de tab[%d] : %p\n", i+1, tab[i], i, &tab[i]);
	}
	
/*--------------------------------------------*/
/*      Chapitre 5 : "Un air de déjà-vu"      */
/*--------------------------------------------*/

	printf("\n------------ MOYENNE : %.2f -----------\n\n", (float)somme/TAILLE_MAX);
		
	return EXIT_SUCCESS;
}
