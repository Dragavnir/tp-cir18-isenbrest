#include "Lexique.h"

void parcoursGRD(noeud *racine, void(*fonction)(noeud *)) {
	if(racine != NULL) {
		parcoursGRD(racine->gauche, fonction);

		fonction(racine);

		parcoursGRD(racine->droite, fonction);
	}
}
