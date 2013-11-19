/* J'ai eu la flemme de commenter celui-là, peut-être plus tard... */

#include <stdio.h>
#include <stdlib.h>

#define NB_LIGN 3
#define NB_COL 4

int main() {
	int tab[NB_LIGN][NB_COL] = {{1,2,3,4},{11,22,33,44},{111,222,333,444}};
	int totauxColonnes[NB_COL] = {0};
	int i; // Compteur sur les lignes
	int j; // Compteur sur les colonnes
	int ligne = 0; // Accumulateur : Total d'une ligne
	int total = 0; // Accumulateur : Total final
	
	for(j = 0; j < NB_COL; j++) { // Cette boucle sert à ajuster la bordure haut en fonction du nombre de colonnes
		printf("--------");
	}
	printf("---------\n");
	
	for(i = 0; i < NB_LIGN; i++) {
		ligne = 0;
		printf("|");
		for(j = 0; j < NB_COL; j++) {
			printf("%5d\t", tab[i][j]);
			ligne = ligne + tab[i][j];
			totauxColonnes[j] = totauxColonnes[j] + tab[i][j];
		}
		printf("| %5d |\n", ligne);
		total = total + ligne;
	}
	
	printf("|");
	for(j = 0; j < NB_COL; j++) { // Cette boucle sert à ajuster la ligne horizontale en fonction du nombre de colonnes
		printf("--------");
	}
	printf("-------|\n");
	
	printf("|");
	for(j = 0; j < NB_COL; j++) {
		printf("%5d\t", totauxColonnes[j]);
	}
	printf("| %5d |\n", total);
	
	for(j = 0; j < NB_COL; j++) { // Cette boucle sert à ajuster la bordure bas en fonction du nombre de colonnes
		printf("--------");
	}
	printf("---------\n");
	
	return EXIT_SUCCESS;
}
