#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#define NB_CHAMPS 10

typedef struct {
	int num;
	float x;
	float y;
}point;

void saisie(point *tabPoint, int taille);
void affiche(point *tabPoint, int taille);
