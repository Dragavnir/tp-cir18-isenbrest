#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#define	LG_MAX 		1000
#define MAX(a,b)	(((a)>(b))?(a):(b))

struct noeud {
	char *francais;
	char *anglais;
	struct noeud *gauche;
	struct noeud *droite;
};

typedef struct noeud noeud;

noeud *inserer(char *fr, char *en, noeud *racine);
char *traduction(char *fr, noeud *racine);
noeud *creation(char *nomfic);
void parcoursGRD(noeud *racine, void(*fonction)(noeud *));
void parcoursGDR(noeud *racine, void(*fonction)(noeud *));
int hauteur (noeud *racine);
void affiche(noeud *noeud);
void libere(noeud *noeud);
