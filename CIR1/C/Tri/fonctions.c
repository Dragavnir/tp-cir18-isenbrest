#include "Tri.h"

void tri_insertion(int *tab, int n) {
	int longueur;
	int i = 0;
	int compteur;
	int buffer;
	int marqueur;

	printf("\nTri en cours...");fflush(stdout);

	for(i = 1; i < n; i++) {
		buffer = tab[i];
		compteur = i-1;
		marqueur = 1;
		
		while(marqueur) {
			marqueur = 0;
			if(tab[compteur] > buffer) {
				tab[compteur+1] = tab[compteur];
				compteur--;
				marqueur = 1;
			}
			if(compteur < 0) {
				marqueur = 0;
			}
		}
		tab[compteur+1] = buffer;
	}
	printf("\n\n");
}

int comp_int(const int *a, const int *b) {
	return (*a==*b)?0:(*a>*b)?1:-1;
}

int comp_string(const void *a, const void *b) {
	return strcmp((char *)a,(char *)b);
}
