/*--------------------*/
/*      Prologue      */
/*--------------------*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int n;
	float x;
	float somme = 0;
	
	printf("\nTapez le nombre de valeurs à saisir : ");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		printf("Entrez la %de valeur réelle : ", i+1);
		scanf("%f", &x);
		
		somme = somme + x;
	}
	
	printf("\nLa somme des %d valeurs est %.2f.\n\n", n, somme);
	return EXIT_SUCCESS;
}
