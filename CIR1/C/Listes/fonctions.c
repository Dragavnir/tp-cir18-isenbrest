#include "Listes.h"

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

void parcours(element *tete) {
	element *adr_temp = tete;
	while(adr_temp) {
		printf("Donnee : %d\n", adr_temp->donnee);
		adr_temp = adr_temp->suiv;
	}
}

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

	return donnee;
}

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
