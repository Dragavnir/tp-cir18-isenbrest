#include "Struct.h"

int main() {
	point tabPoint[NB_CHAMPS+1];

	int tab[NB_CHAMPS];

	int i;
	int taille = NB_CHAMPS;

	saisie(tabPoint, taille);
	affiche(tabPoint, taille);

	return EXIT_SUCCESS;
}
