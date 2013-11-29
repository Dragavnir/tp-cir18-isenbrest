#include <stdio.h>
#include <stdlib.h>

float carre(float valeur) {
/*--------------------------------------------*/
/*               Fonction carre               */
/*                                            */
/*  But : Calculer le carre d'un flottant     */
/*                                            */
/*  Paramètres :                              */
/*            Entrées : float valeur          */
/*            Sorties : float valeur*valeur   */
/*            Retour : carre de valeur        */
/*                                            */
/*  Création : Brendan Abolivier le 28/11/13  */
/*--------------------------------------------*/

	return valeur*valeur;
}

float puissance(float valeur, int puissance) {
/*------------------------------------------------------------------------*/
/*                           Fonction puissance                           */
/*                                                                        */
/*  But : Calculer la valeur d'un flottant à la puissance n (n entier)    */
/*                                                                        */
/*  Paramètres :                                                          */
/*            Entrées : float valeur, int puissance                       */
/*            Sorties : float resultat                                    */
/*            Retour : Puissance n de valeur                              */
/*                                                                        */
/*               Création : Brendan Abolivier le 28/11/13                 */
/*------------------------------------------------------------------------*/

	int i;
	float resultat = valeur;

	if(puissance == 0) {
		resultat = 1;
	} else if (puissance < 0) {
		puissance = -puissance;
		for(i = 1; i < puissance; i++) {
			resultat = resultat*valeur;
		}
		resultat = 1/resultat;
	} else {
		for(i = 1; i < puissance; i++) {
			resultat = resultat*valeur;
		}
	}
	return resultat;
}

int main() {
	float valeur;
	int n;
	
	printf("Entrez un nombre réel : ");
	scanf("%f", &valeur);
	
	printf("Carré de la valeur : %.2f\n", carre(valeur));
	
	printf("Entrez une puissance entière : ");
	scanf("%d", &n);
	
	printf("%.2f à la puissance %d : %.2f\n", valeur, n, puissance(valeur, n));
	
	return EXIT_SUCCESS;
}
