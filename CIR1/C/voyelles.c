#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LG_MAX 30

void voyelles(char *);

int main() {
	char chaine[LG_MAX+1];
	
	printf("Merci d'entrer une chaîne de caractères (30 caractères max) : ");
	
	fgets(chaine, LG_MAX+2, stdin);
	chaine[strlen(chaine)-1] = '\0';
	
	voyelles(chaine);
	
	return EXIT_SUCCESS;
}

void voyelles(char * chaine) {
	while(*chaine != '\0') {
		if(*chaine == 'a' || *chaine == 'e' || *chaine == 'i' || *chaine == 'o' || *chaine == 'u' || *chaine == 'y') {
			printf("%c", *chaine);
		}
		chaine++;
	}
	printf("\n");
}
