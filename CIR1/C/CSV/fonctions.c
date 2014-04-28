#include "CSV.h"

void CSVToMail(FILE *src, FILE *dest) {
	int i = 0;
	int j = 0;
	char *ligne = calloc(LG_MAX, sizeof(char));
	char *arobase = NULL;
	char *delimiteur = NULL;

	while(fgets(ligne, LG_MAX, src)) {
		if(j > 0) {
			arobase = strchr(ligne, '@');
			if(arobase) {
				delimiteur = arobase;
				while(delimiteur) {
					if(*delimiteur == ',' || 
						*delimiteur == '"') {
						break;
					}
					if(*(delimiteur-1) != '\0') {
						delimiteur--;
					} else {
						break;
					}
				}

				if(delimiteur) {

					*delimiteur = '\0';

					ligne = delimiteur+1;

					delimiteur = strchr(ligne, '"');

					if(!delimiteur) {
						delimiteur = strchr(ligne, ',');
					}

					*delimiteur = '\0';

					fprintf(dest, "%s\n", ligne);
					fflush(dest);

				}
			}
		}
		j++;
		// j sert à passer la ligne d'en-tete
	}
/*	if(ligne) {
		printf("%p : %s\n", ligne, ligne);fflush(stdout);
		free(ligne);
	}
	if(delimiteur) {
		free(delimiteur);
	}
	if(arobase){
		free(arobase);
	} */
// To be fixed

}
