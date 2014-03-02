#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

struct element {
	int donnee;
	struct element *suiv;
};
typedef struct element element;

void saisie_ajoutT(element **ptete);
void parcours(element *tete);
int saisie_ajoutQ(element **pqueue);
element *saisie_insere(element *);
void libere_liste(element *tete);
