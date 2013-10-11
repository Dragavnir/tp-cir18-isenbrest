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

/*-------------------------------------------------------*/
/*      Chapitre 3 : "Du traitement au cas par cas"      */
/*-------------------------------------------------------*/
	for(i = 0; i < n; i++) {
		printf("Entrez la %de valeur réelle : ", i+1);
		scanf("%f", &x);
		
		somme = somme + x;
	}

/*--------------------------------------------*/
/*      Chapitre 4 : "Le résultat final"      */
/*--------------------------------------------*/	

	printf("\nLa somme des %d valeurs est %.2f.\n\n", n, somme);
	return EXIT_SUCCESS;
}
