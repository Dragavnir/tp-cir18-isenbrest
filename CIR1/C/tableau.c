/*--------------------*/
/*      Prologue      */
/*--------------------*/

#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------------*/
/*      Chapitre 1 : "One value to rule them all"      */
/*-----------------------------------------------------*/

#define TAILLE_MAX 5

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
	for(i = 0; i < TAILLE_MAX; i++) {
		scanf("%d", &tab[i]);
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
	for(i = 0; i < TAILLE_MAX; i++) {
		somme += tab[i];
	}
	printf("\n------------ MOYENNE : %.2f -----------\n\n", (float)somme/(float)i);
		
	return EXIT_SUCCESS;
}
