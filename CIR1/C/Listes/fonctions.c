#include "Listes.h"

/****************************************************************************/
/*	fonction : saisie_ajoutT()                                          */
/*	Ajoute en tête de liste toute valeur rentrée par l'utilisateur      */
/*                                                                          */
/*      Entrees/Sorties :                                                   */
/*		- ptete : Pointeur sur la tête de la liste (element **)     */
/*	Sorties : Aucune                                                    */
/****************************************************************************/

void saisie_ajoutT(element **ptete) {
	element *tete = *ptete; // Prologue

	element *nouveau = NULL;

	nouveau = malloc(sizeof(element));
	printf("Rentrez une valeur : ");
	scanf("%d", &(nouveau->donnee));
	nouveau->suiv = tete;
	tete = nouveau;

	*ptete = tete; // Epilogue
}

/****************************************************************************/
/*	fonction : parcours()                                               */
/*	Parcourt la liste en partant de la tête et affiche chaque valeur    */
/*                                                                          */
/*      Entrees :                                                           */
/*		- tete : Adresse de la tête de la liste (element *)         */
/*	Sorties : Aucune                                                    */
/****************************************************************************/

void parcours(element *tete) {
	element *adr_temp = tete;
	while(adr_temp) {
		printf("Donnee : %d\n", adr_temp->donnee);
		adr_temp = adr_temp->suiv;
	}
}

/****************************************************************************/
/*	fonction : saisie_ajoutQ()                                          */
/*	Ajoute en queue les valeurs saisies par l'utilisateur               */
/*                                                                          */
/*      Entrees/Sorties :                                                   */
/*		- pqueue : Pointeur sur la queue de la liste (element**)    */
/*	Sorties :                                                           */
/*		- donnee : Valeur saisie par l'utilisateur                  */
/****************************************************************************/

int saisie_ajoutQ(element **pqueue) {
	element *queue = *pqueue; // Prologue
	int donnee;

	printf("Rentrez une valeur : ");
	scanf("%d", &donnee);
	if(donnee != -1) {
		queue->suiv = malloc(sizeof(element));
		queue = queue->suiv;
		queue->donnee = donnee;
		queue->suiv = NULL;
	}
	*pqueue = queue; // Epilogue

	return donnee; // On renvoie la donnée rentrée pour pouvoir la tester dans la boucle (et décider si cette dernière s'arrête ou non)
}

/****************************************************************************/
/*	fonction : saisie_insere()                                          */
/*	Insere dans l'ordre decroissant les valeurs saisies par             */
/*		l'utilisateur                                               */
/*                                                                          */
/*      Entrees :                                                           */
/*		- tete : Adresse de la tête de la liste (element *)         */
/*	Sorties :                                                           */
/*		- tete : Adresse de la tête de la liste (element *)         */
/****************************************************************************/

element *saisie_insere(element *tete) {
	element *temp = NULL;
	element *prec = NULL;
	element *nouveau = NULL;
	int donnee;
	
	while(1) {
		printf("Rentrez une valeur : ");
		scanf("%d", &donnee);
		getchar();
		if(donnee == -1) {
			break;
		}

		nouveau = malloc(sizeof(element));
		nouveau->donnee = donnee;
		nouveau->suiv = NULL;

		if(!tete) { // Premier element de la liste
			tete = nouveau;
			printf("Premier élément de la liste !\n\n");fflush(stdout);
		}

		else {
			temp = tete;
			if(temp->donnee < nouveau->donnee) {
				// Element à mettre en tête
				nouveau->suiv = tete;
				tete = nouveau;
			}
			else {
				prec = temp;
				while(temp) {
					if(prec->donnee > nouveau->donnee &&
						temp->donnee < nouveau->donnee) {
						prec->suiv = nouveau;
						nouveau->suiv = temp;
					}
					prec = temp;
					temp = temp->suiv;
				}
				if(!temp && prec->donnee > nouveau->donnee) {
					prec->suiv = nouveau;
				}
			}
		}
	}
	return tete;
}

/****************************************************************************/
/*	fonction : libere_liste()                                           */
/*	Libère tous les éléments de la liste (pas de fuite mémoire)         */
/*                                                                          */
/*      Entrees/Sorties :                                                   */
/*		- tete : tete de la liste (element *)                       */
/*	Sorties : Aucune                                                    */
/****************************************************************************/

void libere_liste(element *tete) {
	element *suivant = NULL;
	element *adr_temp = tete;
	while(adr_temp) {
		suivant = adr_temp->suiv;
		free(adr_temp);
		printf("Espace libéré à l'adresse %p\n", adr_temp);
		adr_temp = suivant;
	}
}
