/*--------------------*/
/*      Prologue      */
/*--------------------*/

#include <stdio.h>
#include <stdlib.h>

int main() {
/*-----------------------------------------------------*/
/*      Chapitre 1 : "Une question de définition"      */
/*-----------------------------------------------------*/

	int i;
	int n;
	float x;
	float somme = 0;
	
/*-------------------------------------------------*/
/*      Chapitre 2 : "Définir les conditions"      */
/*-------------------------------------------------*/

	printf("\nTapez le nombre de valeurs à saisir : ");
	scanf("%d", &n);
	printf("\nValeurs (entrez un nombre et appuyez sur Entrée) :\n");

/*-------------------------------------------------------*/
/*      Chapitre 3 : "Du traitement au cas par cas"      */
/*-------------------------------------------------------*/
	for(i = 0; i < n; i++) {
		scanf("%f", &x);
		if(!i) {
			printf("La 1ère valeur entrée est %.2f\n", x);
		}
		else
		{
			printf("La %dème valeur entrée est %.2f\n", i+1, x);
		}
		somme = somme + x;
	}

/*--------------------------------------------*/
/*      Chapitre 4 : "Le résultat final"      */
/*--------------------------------------------*/	

	printf("\nLa somme des %d valeurs est %.2f\n\n", n, somme);
	return EXIT_SUCCESS;
}
