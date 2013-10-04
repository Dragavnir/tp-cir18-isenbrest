#include <stdio.h>
#include <stdlib.h>
/* Définition des constantes */
#define AGE_MAJORITE 18
#define SOMME_MINIMALE 100
#define SOMME_SANS_VERIF 10000
#define CANCEL 0

int main () {
	int age;
	float somme;
	
	printf("\nBienvenue. Afin que nous puissions prendre en charge votre dossier, merci de remplir quelques renseignements.");
	printf("\nMerci d'entrer votre âge : ");
	scanf("%d", &age);
	printf("Merci d'entrer la somme que vous souhaitez déposer : ");
	scanf("%f", &somme);
	
	if(somme < SOMME_SANS_VERIF) { /* On vérifie si l'utilisateur souhaite déposer plus de 10 000€ */
	
		if(age >= AGE_MAJORITE && somme >= SOMME_MINIMALE) { /* On vérifie l'âge de l'utilisateur ainsi que la somme qu'il souhaite déposer */
			printf("\nNous allons procéder à l'ouverture de votre compte sous quelques jours. Merci de bien vouloir patienter.\n");
		}
	
		else { /* S'il y a eu une erreur, on vérifie chacun des paramètres */
	
			if(age < AGE_MAJORITE) { /* Vérification de l'age */
				printf("\nVous devez être majeur pour devenir client chez nous. Merci de revenir dans %d ans.\n", AGE_MAJORITE-age);
			}
	
			else if(somme < SOMME_MINIMALE) { /* Vérification de la somme, dans le cas où l'utilisateur est majeur */
	
				while(somme < SOMME_MINIMALE) { 
				/* Si le problème vient de la somme entrée, on propose à l'utilisateur de rentrer de nouveau une somme en lui spécifiant combien il manque. La demande se fait de façon répétitive, mais l'utilisateur peut entrer 0 afin de quitter le programme. */
	
					printf("\nLa somme minimale pour rentrer un compte chez nous est de 100€. Il vous manque %.2f€ pour pouvoir ouvrir votre compte.\nMerci de rectifier votre montant.\n", SOMME_MINIMALE-somme);
					printf("Entrez un nouveau montant, ou tapez 0 pour abandonner l'opération : ");
					scanf("%f", &somme);
	
					if(somme == CANCEL) {
						printf("\nA une prochaine fois !\n\n");
						return EXIT_SUCCESS;
						/* On peut aussi enlever le return et rajouter "&& somme != CANCEL" dans la condition à la ligne 26, ce qui aurait le même effet du côté de l'utilisateur. */
					}
	
					else if(somme >= SOMME_MINIMALE) {
						printf("\nNous allons procéder à l'ouverture de votre compte sous quelques jours. Merci de bien vouloir patienter.\n\n");
					}
				}
			}
		}
	}
	
	else { /* Si la somme est supérieure ou égale à 10 000€, on accepte le client sans vérifier son âge. */
		printf("\nBienvenue dans notre banque ! Je m'occupe de votre dossier dès maintenant avec la plus haute priorité.\n");
	}

	
	return EXIT_SUCCESS;
	/* Tout s'est bien passé, cey la fête \o/ */
}
