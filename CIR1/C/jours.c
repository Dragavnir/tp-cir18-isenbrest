/*------------------*/
/*     Prologue     */
/*------------------*/

#include <stdio.h>
#include <stdlib.h>

/*--------------------*/
/* Table des matières */
/*--------------------*/

/* Différents nombres de jours possibles */
#define MOIS_LONG 31
#define MOIS_MOINS_LONG 30
#define MOIS_ENCORE_MOINS_LONG 28
#define MOIS_BISSEXTILE 29
#define MOIS_DEBUT 1
/* Intervale de mois existant, ainsi que l'identifiant du mois de février */
#define MOIS_MIN 1
#define MOIS_MAX 12
#define FEVRIER 2
/* Constantes nécessaire à la vérification de la "bissextualité" d'une année */
#define BISSEXTILE_MULTIPLE1 4
#define BISSEXTILE_MULTIPLE2 400
#define BISSEXTILE_PAS_MULTIPLE 100
/* Résultat d'un modulo si le premier terme est multiple du second */
#define MULTIPLE 0

int main() {
/*--------------------------------------------*/
/*    Chapitre 1 : "De nouvelles valeurs"     */
/*--------------------------------------------*/
	
	int jourEntree;
	int jours;
	int mois;
	int annee;
	char moisType; /* Vaut 0 si le mois est à 28 jours, 1 si le mois est à 29 jours, 2 pour 30 et 3 pour 31 */

/*---------------------------------------------*/
/*    Chapitre 2 : "Un intervenant inconnu"    */
/*---------------------------------------------*/

	/* Saisie des valeurs */
	printf("\nEntrez la date au format jour/mois/année : ");
	scanf("%d/%d/%d", &jourEntree, &mois, &annee);
	
/*----------------------------------------------*/
/*    Chapitre 3 : "L'erreur de l'inconnu"      */
/*----------------------------------------------*/
	
	if (mois < MOIS_MIN || mois > MOIS_MAX) { /* Cas d'erreur : Si le mois n'est pas compris entre 1 et 12 */
		printf("\nValeur de mois incorrecte. Merci de réessayer avec un mois existant.\n\n");
		return EXIT_FAILURE;
	}
	
/*-------------------------------------------------*/
/*    Chapitre 4 : "Une recherche impitoyable"     */
/*-------------------------------------------------*/
	
	if(((mois%FEVRIER) == MULTIPLE && mois <= (MOIS_MAX/2) && mois > (MOIS_MIN)) || ((mois%2) != MULTIPLE && mois <= (MOIS_MAX/2+1) && mois > (MOIS_MAX))) {
		/* Traitement de tous les mois à moins de 31 jours */

		if(mois == FEVRIER && ((annee%BISSEXTILE_MULTIPLE1) == MULTIPLE && ((annee%BISSEXTILE_PAS_MULTIPLE) != MULTIPLE || (annee%BISSEXTILE_MULTIPLE2) == MULTIPLE))) { 
			/* Traitement des années bissextiles */
			jours = MOIS_BISSEXTILE;
			moisType = 1;
		}

		else if(mois == FEVRIER) {
			/* Mois de février hors années bissextiles */
			jours = MOIS_ENCORE_MOINS_LONG;
			moisType = 0;
		}

		else {
			/* Mois à 30 jours */
			jours = MOIS_MOINS_LONG;
			moisType = 2;
		}
	}
	
/*-----------------------------------------------------*/
/*    Chapitre 5 : "La seule alternative possible"     */
/*-----------------------------------------------------*/
	
	else { /* Traitement des mois à 31 jours : Si le programme arrive dans le else, c'est que le mois a 31 jours */
		jours = MOIS_LONG;
		moisType = 3;
	}
	
/*--------------------------------------------*/
/*    Chapitre 6 : "Agir au jour-le-jour"     */
/*--------------------------------------------*/

	if((moisType == 0 && jourEntree == MOIS_ENCORE_MOINS_LONG) || (moisType == 1 && jourEntree == MOIS_BISSEXTILE) || (moisType == 2 && jourEntree == MOIS_MOINS_LONG) || (moisType == 3 && jourEntree == MOIS_LONG)) {
		/* Si le jour entré est à la fin du mois, on le repasse à 1 et on incrémente le mois pour trouver le jour suivant */
		jourEntree = MOIS_DEBUT;
		mois++;
	}
	else { /* Sinon, on incrémente le numéro correspondant au jour */
		jourEntree++;
	}	
	
	if (mois > MOIS_MAX) { /* Cas où on change d'année, afficher le bon mois (mois 1) */
		mois = MOIS_MIN;
	}
	
	if (mois == MOIS_MIN && jourEntree == MOIS_DEBUT) { /* Cas où on change d'année, afficher la bonne année */
		annee++;
	}
	
/*-----------------------------------------------*/
/*    Chapitre 7 : "L'erreur contre-attaque"     */
/*-----------------------------------------------*/

	if ((moisType == 0 && jourEntree > MOIS_BISSEXTILE) || (moisType == 1 && jourEntree > MOIS_ENCORE_MOINS_LONG) || (moisType == 2 && jourEntree > MOIS_MOINS_LONG) || (moisType == 3 && jourEntree > MOIS_LONG) || jourEntree < MOIS_DEBUT) { /* Cas d'erreur : Le jour spécifié est incorrect */
		printf("\nValeur de jour incorrecte. Merci de réessayer avec un mois existant.\n\n");
		return EXIT_SUCCESS;
	}

/*-----------------------------------------*/
/*    Chapitre 8 : "Une fin correcte"      */
/*-----------------------------------------*/

	printf("\nNombre de jours dans le mois demandé : %d.\nLe prochain jour est le %d/%d/%d.\n\n", jours, jourEntree, mois, annee);

	return EXIT_SUCCESS;
}
