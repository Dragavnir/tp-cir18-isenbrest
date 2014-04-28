#include "Tri.h"

int main() {
	char *tab[TAILLE];
	int i = 0;
	int j = 0;

	int longueur;

	char *buffer = calloc(LG_MAX, sizeof(char));

	long debut, fin;
	struct timeval temps;

	gettimeofday(&temps, NULL);

	debut = temps.tv_sec * 1000000 + temps.tv_usec;

	srand(time(NULL));

	for(i = 0; i < TAILLE; i++) {
		
/*		longueur = rand()%LG_MAX; 

		for(j = 0; i < longueur; i++) {
			tab[i][j] = rand()%26 + 97;
		}

		tab[i][j] = '\0';
		//tab[i] = rand()%TAILLE;
		printf("%s\n", tab[i]);
*/

		printf("Rentrez une chaine de caractères : ");
		fgets(buffer, LG_MAX, stdin);
		buffer[strlen(buffer)-1] = '\0';

		tab = realloc(tab, i*sizeof(char *));
		tab[i] = calloc(LG_MAX, sizeof(char));

		strcpy(tab[i], buffer);
	}

	printf("\n");

	qsort(tab, TAILLE, sizeof(char *)*LG_MAX, &comp_string);

	for(i = 0; i < TAILLE; i++) {
		printf("%s\n", tab[i]);
	}

	printf("\n\n");

	gettimeofday(&temps, NULL);

	fin = temps.tv_sec*1000000+temps.tv_usec;

	printf("Temps d'exécution : %.3fsec\n", (fin-debut)/(double)1000000);

	return EXIT_SUCCESS;
}
