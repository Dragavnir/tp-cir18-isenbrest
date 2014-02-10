#include "Banque.h"

int main() {
	int method;
	client *donneesClients = NULL;
	int nbClients = 1;
	int result;
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
				affichage(result, donneesClients);
				// Affichage du résultat de la recherche
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
