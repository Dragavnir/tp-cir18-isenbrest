#include <stdio.h>
#include <stdlib.h>

int strlen(const char * chaine) {
	int longueur = 0;
	while(*chaine != '\0') {
		chaine++;
		longueur++;
	}
	return longueur;
}

int main() {
	char chaine[10] = "bonjour";
	printf("L = %d\n", strlen(chaine));
	return EXIT_SUCCESS;
}
