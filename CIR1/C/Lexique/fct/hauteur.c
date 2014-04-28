#include "Lexique.h"

int hauteur (noeud *racine)
{
	if (racine == NULL)
		return 0;
	else
		return 1 + MAX(hauteur(racine->gauche), hauteur(racine->droite));
}

