#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LG_MAX 30

char * voyelles(const char *);

int main() {
	char chaine[LG_MAX+1];
	char * voyellesTab = NULL;
	
	printf("Merci d'entrer une chaîne de caractères (30 caractères max) : ");
	
	fgets(chaine, LG_MAX+2, stdin);
	chaine[strlen(chaine)-1] = '\0';
	
	voyellesTab = voyelles(chaine);
	printf("%s\n", voyellesTab);
	
	return EXIT_SUCCESS;
}

char * voyelles(const char * chaine) {
	char * tab = malloc(strlen(chaine)+1);
	char * ptab = tab;
	
	while (*chaine != '\0') {
		if(*chaine == 'a' || *chaine == 'e' || *chaine == 'i' || *chaine == 'o' || *chaine == 'u' || *chaine == 'y') {
			*ptab = *chaine;
			ptab++;
		}
		chaine++;
		*ptab = '\0';
	}
	
	return tab;
}
