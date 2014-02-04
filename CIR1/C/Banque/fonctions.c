#include "Banque.h"

int saisie(client *donneesClients) {
	char *nom;
	char *prenom;
	double solde;
	int i = 0;

	while(1) {
		printf("\n");
		donneesClients = realloc(donneesClients, (i+1)*sizeof(client));

		printf("Prenom (tapez 0 pour arrêter) : ");
		fgets(prenom, LG_MAX+1, stdin);
		prenom[strlen(prenom)-1] = '\0';
		
		if(!strcmp(prenom, "0")) {
			break;
		}

		printf("Nom : ");
		fgets(nom, LG_MAX+1, stdin);
		printf("1\n");fflush(stdout);
		nom[strlen(nom)-1] = '\0';
	
		printf("Solde : ");
		scanf("%lf", &solde);

		strcpy(donneesClients[i].prenom, prenom);
		strcpy(donneesClients[i].nom, nom);
		donneesClients[i].solde = solde;
	}	

	return i;
}

int recherche(char *nom, char *prenom, client *donneesClients, int nbClients) {
	int i = 0;

	for(i = 0; i < nbClients; i++) {
		if(!strcmp(donneesClients[i].nom, nom) && !strcmp(donneesClients[i].prenom, prenom)) {
			return i;
		}
	}

	return -1;
}

void affichage(int id, client *donneesClients) {
	if(id >= 0) {
		printf("Prenom : %s\nNom : %s\nSolde : %lf\n\n", donneesClients[id].prenom, donneesClients[id].nom, donneesClients[id].solde);
	}
	else {
		printf("Le client sélectionné n'existe pas.\n\n");
	}
}
