#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#define	LG_MAX 1000

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
