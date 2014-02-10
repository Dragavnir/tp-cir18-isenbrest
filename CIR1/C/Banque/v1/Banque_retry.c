#include "Banque.h"

int main() {
	int method;
	client *donneesClients = NULL;
	int nbClients = 1;
	int result;
	int quit = 0;
	char retry;
	char nomSaisi[LG_MAX+2];
	char prenomSaisi[LG_MAX+2]; // Variables servant à l'appel de recherche();

	printf("\nBienvenue dans notre banque.\n");

	while(1) {
		printf("\nQue voulez-vous faire ?\n"
			"\t1 : Entrer un ou plusieurs nouveau(x) client(s).\n"
			"\t2 : Chercher un client et afficher son solde\n"
			"\t3 : Quitter le programme\n\nVotre sélection : ");
		scanf("%d", &method);
		getchar();
		// Gestion du menu

		switch (method) {
			case 1:	// L'utilisateur souhaite saisir des informations
				printf("\nSélection : Saisie\n");
				nbClients = saisie(&donneesClients);
				// Saisie des clients
				break;
			case 2: // L'utilisateur souhaite chercher un client
				printf("\nSélection : Recherche et affichage\n");

				do {
					printf("\nPrenom : ");
					fgets(prenomSaisi, LG_MAX+1, stdin);
					prenomSaisi[strlen(prenomSaisi)-1] = '\0';
		
					printf("Nom : ");
					fgets(nomSaisi, LG_MAX+1, stdin);
					nomSaisi[strlen(nomSaisi)-1] = '\0';
					// Saisie des informations (nom+prénom) 
					// nécessaires à la recherche d'un client
				
					result = recherche(nomSaisi, prenomSaisi, 
							donneesClients, nbClients);
					// Recherche
					quit = (result < 0)?0:1;
					// Si résultat valide, on revient au menu
					// après l'affichage

					affichage(result, donneesClients);
					// Affichage du résultat de la recherche
					if(result < 0) {
						do {
							printf("Réessayer ? [O/n] ");
							retry = getchar();
							if(getchar()) {
								continue;
							}
							switch(retry) {
								case '\n':
								case 'o':
								case 'O':
									quit = 0;
									getchar();
									printf("0");
									break;
								case 'n':
								case 'N':
									quit = 1;
									getchar();
									printf("1");
									break;
								default:
									quit = -1;
									getchar();
									printf("Merci d'entrer un caractère correct.\n\n");
									break;
							}
						}while(quit < 0);
						
					}
				}while(!quit);
				break;
			case 3: // L'utilisateur souhaite quitter le programme
				printf("\nAu revoir !\n\n");
				return EXIT_SUCCESS;
			default: // L'utilisateur a rentré une commande inconnue
				printf("Sélection incorrecte\n");
				return EXIT_FAILURE;
		}
	}
}
