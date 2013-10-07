/*--------------------*/
/*      Prologue      */
/*--------------------*/

#include <stdio.h>
#include <stdlib.h>

/*------------------------------*/
/*      Table des matières      */
/*------------------------------*/

#define NUL 0

int main() {
/*-----------------------------------------*/
/*      Chapitre 1 : "Partir de zéro"      */
/*-----------------------------------------*/

	int note;
	int nb_notes = NUL;
	int total = NUL;
	float moyenne;
	
/*-----------------------------------------*/
/*      Chapitre 2 : "Rester positif"      */
/*-----------------------------------------*/

	printf("Entrez une note (négative pour arrêter) : ");
	scanf("%d", &note);
	
/*-------------------------------------*/
/*      Chapitre 3 : "Le cas nul"      */
/*-------------------------------------*/

	if(note < NUL) {
		printf("Arrêt du programme, aucune moyenne calculée...\n");
		return EXIT_SUCCESS;
	}
/*----------------------------------------------*/
/*      Chapitre 4 : "Travail à la chaîne"      */
/*----------------------------------------------*/

	while(note >= NUL) { /* Pour toute note non négative (note négative : arrêt du programme) */
		total = total + note;
		nb_notes++;
		printf("Entrez une note (négative pour arrêter) : ");
		scanf("%d", &note);
	}
	
/*------------------------------------------------*/
/*      Chapitre 5 : "La dernière opération"      */
/*------------------------------------------------*/
	
	moyenne = (float)total/(float)nb_notes;
	
/*----------------------------------------------------------------*/
/*      Chapitre 6 : "I'm making a note here: Huge success!"      */
/*----------------------------------------------------------------*/
	
	printf("La moyenne des %d notes rentrées est %.2f.\n", nb_notes, moyenne);
	return EXIT_SUCCESS;
}
