/*--------------------*/
/*      Prologue      */
/*--------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRONOM_MAX 5
#define VERBE_MAX 50

int main() {
/*--------------------------------------*/
/*      Chapitre 1 : Entrée brute       */
/*--------------------------------------*/

	char pronom[PRONOM_MAX+1];
	char verbe[VERBE_MAX+1];
	int nbpronom;
	
	printf("Merci d'entrer pronom : ");
	
	fgets(pronom, PRONOM_MAX+2, stdin);
	pronom[strlen(pronom)-1] = '\0';
	
	printf("Merci d'entrer un verbe du premier groupe à l'infinitif : ");
	
	fgets(verbe, VERBE_MAX+2, stdin);
	verbe[strlen(verbe)-1] = '\0';
	

/*----------------------------------------------*/
/*      Chapitre 2 : Un groupe très fermé       */
/*----------------------------------------------*/

	while(!(!strcmp(pronom, "je") || !strcmp(pronom, "tu") || !strcmp(pronom, "il") || !strcmp(pronom, "elle") || !strcmp(pronom, "on") || !strcmp(pronom, "nous") || !strcmp(pronom, "vous") || !strcmp(pronom, "ils") || !strcmp(pronom, "elles"))) {
		printf("Vous n'avez pas entré de pronom, ou celui-ci n'est pas entièrement en minuscules. Merci de recommencer ou tapez 0 pour annuler : ");
		fgets(pronom, VERBE_MAX+2, stdin);
		pronom[strlen(pronom)-1] = '\0';
		if(!strcmp(verbe, "0")) {
			return EXIT_SUCCESS;
		}
	}
	
	if(!strcmp(pronom, "je")) {
		nbpronom = 1;
	}
	else if(!strcmp(pronom, "tu")) {
		nbpronom = 2;
	}
	else if(!strcmp(pronom, "il") || !strcmp(pronom, "elle") || !strcmp(pronom, "on")) {
		nbpronom = 3;
	}
	else if(!strcmp(pronom, "nous")) {
		nbpronom = 4;
	}
	else if(!strcmp(pronom, "vous")) {
		nbpronom = 5;
	}
	else if(!strcmp(pronom, "ils") || !strcmp(pronom, "elles")) {
		nbpronom = 6;
	}
	
	
/*-------------------------------------------*/
/*      Chapitre 3 : Chercher l'intrus       */
/*-------------------------------------------*/
	
	while(!(verbe[strlen(verbe)-1] == 'r' && verbe[strlen(verbe)-2] == 'e' && strlen(verbe) >= 4) || !strcmp(verbe, "aller")) {
		printf("Vous n'avez pas entré de verbe du premier groupe ou ce dernier n'est pas à l'infinitif. Merci de recommencer ou tapez 0 pour annuler : ");
		fgets(verbe, VERBE_MAX+2, stdin);
		verbe[strlen(verbe)-1] = '\0';
		if(!strcmp(verbe, "0")) {
			return EXIT_SUCCESS;
		}
	}
	
	
/*-----------------------------------------------------------*/
/*      Chapitre 4 : La formatisation de l'information       */
/*-----------------------------------------------------------*/
	
	switch(nbpronom) {
		case 1: {
			verbe[strlen(verbe)-1] = '\0';
			if(verbe[0] == 'a' || verbe[0] == 'e' || verbe[0] == 'i' || verbe[0] == 'o' || verbe[0] == 'u' || verbe[0] == 'y') {
				pronom[1] = '\'';
			}
			else {
				strcat(pronom, " ");
			}
			break;
		}
		case 2: {
			verbe[strlen(verbe)-1] = 's';
			strcat(pronom, " ");
			break;
		}
		case 3: {
			verbe[strlen(verbe)-1] = '\0';
			strcat(pronom, " ");
			break;
		}
		case 4: {
			verbe[strlen(verbe)-2] = '\0';
			strcat(pronom, " ");
			strcat(verbe, "ons");
			break;
		}
		case 5: {
			verbe[strlen(verbe)-2] = '\0';
			strcat(pronom, " ");
			strcat(verbe, "ez");
			break;
		}
		case 6: {
			verbe[strlen(verbe)-1] = '\0';
			strcat(pronom, " ");
			strcat(verbe, "nt");
			break;
		}
	}
	
	printf("%s%s\n", pronom, verbe);
	
	return EXIT_SUCCESS;
}
