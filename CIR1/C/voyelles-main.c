#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LG_MAX 30

void voyelles(char *, char *);

int main() {
	char chaine[LG_MAX+1];
	char voyellesTab[LG_MAX+1] = "aaaaaaaaaaaaaaaaaaaaaaaa";
	
	printf("Merci d'entrer une chaîne de caractères (30 caractères max) : ");
	
	fgets(chaine, LG_MAX+2, stdin);
	chaine[strlen(chaine)-1] = '\0';
	
	voyelles(chaine, voyellesTab);
	printf("%s\n", voyellesTab);
	
	return EXIT_SUCCESS;
}

void voyelles(char * chaine, char * tab) {
	while(*chaine != '\0') {
		if(*chaine == 'a' || *chaine == 'e' || *chaine == 'i' || *chaine == 'o' || *chaine == 'u' || *chaine == 'y') {
			*tab = *chaine;
			tab++;
		}
		chaine++;
		*tab = '\0';
	}
}
