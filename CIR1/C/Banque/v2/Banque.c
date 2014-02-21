#include "Banque.h"

int main() {
	int method;
	client *donneesClients = NULL; // Tableau servant à stocker les clients
	int nbClients = 0;
	int result;
	int emetteur;
	int destinataire; // Variables utilisées pour virement()
	double montant; // Utilisé pour virement() et retrait()
	char nomSaisi[LG_MAX+2];
	char prenomSaisi[LG_MAX+2]; // Variables utilisées pour recherche();

	printf("\nBienvenue dans notre banque.\n");

	while(1) {
		printf("\nQue voulez-vous faire ?\n"
			"\t1 : Entrer un ou plusieurs nouveau(x) client(s).\n"
			"\t2 : Chercher un client et afficher son solde\n"
			"\t3 : Effectuer un retrait\n"
			"\t4 : Effectuer un virement entre deux clients\n"
			"\t5 : Quitter le programme\n"
			"\nVotre sélection : ");
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
				if(nbClients > 0) {
					printf("\nSélection : Recherche et affichage\n");
	
					printf("\nPrenom : ");
					fgets(prenomSaisi, LG_MAX+1, stdin);
					prenomSaisi[strlen(prenomSaisi)-1] = '\0';
		
					printf("Nom : ");
					fgets(nomSaisi, LG_MAX+1, stdin);
					nomSaisi[strlen(nomSaisi)-1] = '\0';
					// Saisie des informations (nom+prénom) 
					// nécessaires à la recherche du client
				
					result = recherche(nomSaisi, 
							prenomSaisi, 
							donneesClients, 
							nbClients);
					// Recherche
					affichage(result, donneesClients);
					// Affichage du résultat de la recherche
				}
				else {
					printf("\nAucun client saisi, merci de d'abord saisir au moins un client\n\n");
				}
				break;
			case 3:	// L'utilisateur souhaite retirer de l'argent
				if(nbClients > 0) {
					printf("\nPrenom : ");
					fgets(prenomSaisi, LG_MAX+1, stdin);
					prenomSaisi[strlen(prenomSaisi)-1] = '\0';
	
					printf("Nom : ");
					fgets(nomSaisi, LG_MAX+1, stdin);
					nomSaisi[strlen(nomSaisi)-1] = '\0';
					// Saisie des informations (nom+prénom) 
					// nécessaires à la recherche du client
	
					printf("Montant à retirer : ");
					scanf("%lf", &montant);
					getchar();
				
					result = recherche(nomSaisi,
							prenomSaisi, 
							donneesClients, 
							nbClients);
					// Recherche

					retrait(result, montant, 
						donneesClients);
					// Retrait
				}
				else {
					printf("\nAucun client saisi, merci de d'abord saisir au moins un client\n\n");
				}
				break;
			case 4:	// L'utilisateur souhaite virer de l'argent à un autre utilisateur
				if(nbClients > 1) {
					printf("\nPrenom de l'émetteur : ");
					fgets(prenomSaisi, LG_MAX+1, stdin);
					prenomSaisi[strlen(prenomSaisi)-1] = '\0';
	
					printf("Nom de l'émetteur : ");
					fgets(nomSaisi, LG_MAX+1, stdin);
					nomSaisi[strlen(nomSaisi)-1] = '\0';
					// Saisie des informations (nom+prénom) 
					// nécessaires à la recherche de 
					// l'émetteur

					emetteur = recherche(nomSaisi, 
							prenomSaisi, 
							donneesClients, 
							nbClients);
					// Recherche des informations de 
					// l'émetteur

					printf("\nPrenom du destinataire : ");
					fgets(prenomSaisi, LG_MAX+1, stdin);
					prenomSaisi[strlen(prenomSaisi)-1] = '\0';
	
					printf("Nom du destinataire : ");
					fgets(nomSaisi, LG_MAX+1, stdin);
					nomSaisi[strlen(nomSaisi)-1] = '\0';
					// Saisie des informations (nom+prénom) 
					// nécessaires à la recherche 
					// du destinataire

					printf("\nMontant à virer : ");
					scanf("%lf", &montant);
					getchar();
				
					destinataire = recherche(nomSaisi,
							prenomSaisi, 
							donneesClients, 
							nbClients);
					// Recherche des informations du 
					// récepteur

					virement(emetteur, destinataire, 
						montant, donneesClients);
				}
				else {
					printf("\nIl n'y a pas assez de clients, merci de saisir au moins deux clients.\n\n");
				}
				break;
			case 5: // L'utilisateur souhaite quitter le programme
				printf("\nAu revoir !\n\n");
				return EXIT_SUCCESS;
			default: // L'utilisateur a rentré une commande inconnue
				printf("\nSélection incorrecte\n");
		}
	}
}
