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

	return donnee; // On renvoie la donnée rentrée pour pouvoir la tester dans la boucle (et décider si cette dernière s'arrête ou non)
}

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

		nouveau = realloc(nouveau, sizeof(element));
		nouveau->donnee = donnee;

		if(!tete) { // Premier element de la liste
			tete = nouveau;
			printf("Premier élément de la liste !\n\n");fflush(stdout);
		}

		else {
			temp = tete;
			if(temp->donnee < nouveau->donnee) {
				printf("0\n");
				// Element à mettre en tête
				nouveau->suiv = tete;
				tete = nouveau;
			}
			else {
				printf("1\n");fflush(stdout);
				while(temp) {
					printf("2\n");fflush(stdout);
					prec = temp;
					temp = temp->suiv;
					if(prec->donnee > nouveau->donnee &&
						temp->donnee < nouveau->donnee) {
						printf("3\n");fflush(stdout);
						prec->suiv = nouveau;
						nouveau->suiv = temp;
					}
				}
				if(!temp && prec->donnee > nouveau->donnee) {
					printf("4\n");fflush(stdout);
					prec->suiv = nouveau;
				}
			}
		}
	}
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
