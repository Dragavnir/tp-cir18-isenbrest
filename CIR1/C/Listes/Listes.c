#include "Listes.h"

int main() {
	element *tete = NULL;
	element *queue = NULL;
	int donnee;


	/****************************************************/
	/*  A decommenter pour utiliser saisie_ajoutT() et  */
	/*  saisie_ajoutQ()                                 */
	/****************************************************

	while(1) {
		saisie_ajoutT(&tete);
		if(tete->suiv == NULL) {
			queue = tete;
		}
		if(tete->donnee == -1) {
			tete = tete->suiv;
			break;
		}	
	}

	parcours(tete);

	while(1){
		donnee = saisie_ajoutQ(&queue);
		if(donnee == -1) {
			break;
		}
	}

	parcours(tete); */

	tete = saisie_insere(tete);

	if(!tete) {
		printf("\nloltnul\n\n");
	}

	parcours(tete);

	libere_liste(tete);

	return EXIT_SUCCESS;
}
