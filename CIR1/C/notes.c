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
	int noteMax;
	int noteMin;
	float moyenne;
	
/*-----------------------------------------*/
/*      Chapitre 2 : "Rester positif"      */
/*-----------------------------------------*/

	printf("\nEntrez une note (négative pour arrêter) : ");
	scanf("%d", &note);
	/* Affectation des variables noteMin et noteMax */
	noteMin = note;
	noteMax = note; 
	
/*-------------------------------------*/
/*      Chapitre 3 : "Le cas nul"      */
/*-------------------------------------*/

	if(note < NUL) { /* Cas d'erreur : l'utilisateur rentre d'emblée une valeur négative */
		printf("Arrêt du programme, aucune moyenne calculée...\n\n");
		return EXIT_SUCCESS;
	}
/*----------------------------------------------*/
/*      Chapitre 4 : "Travail à la chaîne"      */
/*----------------------------------------------*/

	while(note >= NUL) { /* Pour toute note non négative (note négative : arrêt du programme) */
		total = total + note;
		nb_notes++;
		
		if(note > noteMax) {
			noteMax = note;
		}
		if(note < noteMin) {
			noteMin = note;
		}
		
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
	
	printf("\nLa moyenne des %d notes rentrées est %.2f.\nLa note minimale est %d, la note maximale est %d.\n\n", nb_notes, moyenne, noteMin, noteMax);
	return EXIT_SUCCESS;
}
