#include "Banque.h"

int main() {
	int method;
	client *donneesClients = NULL;
	int nbClients = 0;
	int result;
	char *nomSaisi;
	char *prenomSaisi;

	printf("\nBienvenue dans notre banque.\n");

	while(1) {
		printf("\nQue voulez-vous faire ?\n\t1 : Entrer un ou plusieurs nouveau(x) client(s).\n\t2 : Chercher un client et afficher son solde\n\t3 : Quitter le programme\n\nVotre saisie : ");
		scanf("%d", &method);
		getchar();

		switch (method) {
			case 1:
				printf("Sélection : Saisie\n");
				nbClients = saisie(donneesClients);
				break;
			case 2:
				printf("Sélection : Recherche et affichage\n");
				printf("Entrer le prenom et le nom du client : ");
				scanf("%s %s", prenomSaisi, nomSaisi);
				getchar();
				result = recherche(nomSaisi, prenomSaisi, donneesClients, nbClients);
				affichage(result, donneesClients);
				break;
			case 3:
				printf("\nAu revoir !\n\n");
				return EXIT_SUCCESS;
			default:
				printf("Sélection incorrecte\n");
				return EXIT_FAILURE;
		}
	}
	
	return EXIT_SUCCESS;
}
