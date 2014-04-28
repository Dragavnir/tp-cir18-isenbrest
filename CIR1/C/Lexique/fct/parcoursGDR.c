#include "Lexique.h"

void parcoursGDR(noeud *racine, void(*fonction)(noeud *)) {
	if(racine != NULL) {
		parcoursGDR(racine->gauche, fonction);

		parcoursGDR(racine->droite, fonction);

		fonction(racine);
	}
}

