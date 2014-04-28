#include "Lexique.h"

void libere(noeud *noeud) {
	free(noeud->anglais);
	free(noeud->francais);
	free(noeud);
}
