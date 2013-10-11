/********************************************************************************/
/*                           Evolution du TP notes.c                            */
/* Réécriture avec une structure do { } while; au lieu d'une structure while{ } */
/********************************************************************************/


/*--------------------*/
/*      Prologue      */
/*--------------------*/

#include <stdio.h>
#include <stdlib.h>

int main() {
/*-----------------------------------------*/
/*      Chapitre 1 : "Partir de zéro"      */
/*-----------------------------------------*/

	int note;
	int nb_notes = 0;
	int total = 0;
	int noteMax = 0;
	int noteMin = 65535;
	float moyenne;
	
/*----------------------------------------------*/
/*      Chapitre 2 : "Travail à la chaîne"      */
/*----------------------------------------------*/

	do { /* Pour toute note non négative (note négative : arrêt du programme) */
		printf("Entrez une note (négative pour arrêter) : ");
		scanf("%d", &note);
		
		total = total + note;
		nb_notes++;
		
		if(note > noteMax) {
			noteMax = note;
		}
		if(note < noteMin && note >= 0) {
			noteMin = note;
		}
		
	} while(note >= 0);
	
	nb_notes--;
	total = total - note;
		
/*-------------------------------------*/
/*      Chapitre 3 : "Le cas nul"      */
/*-------------------------------------*/
	
	if(nb_notes == 0) { /* Cas d'erreur : la première valeur rentrée est négative */
		printf("Arrêt du programme, aucune moyenne calculée...\n\n");
		return EXIT_SUCCESS;
	}
/*------------------------------------------------*/
/*      Chapitre 4 : "La dernière opération"      */
/*------------------------------------------------*/
	
	moyenne = (float)total/(float)nb_notes;
	
/*----------------------------------------------------------------*/
/*      Chapitre 5 : "I'm making a note here: Huge success!"      */
/*----------------------------------------------------------------*/
	
	printf("\nLa moyenne des %d notes rentrées est %.2f.\nLa note minimale est %d, la note maximale est %d.\n\n", nb_notes, moyenne, noteMin, noteMax);
	return EXIT_SUCCESS;
}
