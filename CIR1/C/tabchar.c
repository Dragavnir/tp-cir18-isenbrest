/*--------------------*/
/*      Prologue      */
/*--------------------*/

#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
/*------------------------------------------------*/
/*      Chapitre 1 : "Le caractère intégral"      */
/*------------------------------------------------*/

	char tab1[N] = {'a', 'b', 'c', 'd', 'e'};
	char tab2[N] = {'b', 'a', 'c', 'a', 'e'};
	char tab[N];
	int i;
	int j = 0; /* i sert de compteur pour tab1 et tab2 (dont le traitement évolue à la même vitesse), j sert de compteur pour tab */
	
/*-----------------------------------------------*/
/*      Chapitre 2 : "Un indice prometteur"      */
/*-----------------------------------------------*/

	for(i = 0; i < N; i++) {
		if(tab1[i] == tab2[i]) {
			printf("%c : indice %d\n", tab1[i], i);
			tab[j] = tab1[i];
			j++;
		}
	}
	
/*------------------------------------------*/
/*      Chapitre 3 : "Le point commun"      */
/*------------------------------------------*/
	
	for(i = 0; i < j; i++) { 
		/* On va jusqu'à la dernière valeur rentrée dans tab. On aurait aussi pu initialiser tab : int tab[N] = {0}; et choisir tab[i] != 0 comme condition, mais je trouve cette soltion plus simple. */
		printf("tab[%d] = %c\n", i, tab[i]);
	}
	
	printf("Il y a %d éléments en commun entre les deux tableaux.\n", j);
	
	return EXIT_SUCCESS;
}
