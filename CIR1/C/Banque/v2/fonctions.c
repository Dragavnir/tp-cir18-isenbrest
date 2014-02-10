#include "Banque.h"

int saisie(client **pdonneesClients) {
	client *donneesClients = *pdonneesClients; // Prologue

	int i = 0;

	while(1) {
		printf("\n");
		donneesClients = realloc(donneesClients, (i+1)*sizeof(client));
		// Le tableau est redimensionné à chaque entrée

		printf("Prenom (tapez 0 pour arrêter) : ");
		fgets(donneesClients[i].prenom, LG_MAX+1, stdin);
		donneesClients[i].prenom[strlen(donneesClients[i].prenom)-1] = '\0';
		// Saisi du prénom (champ "prenom" de la structure)

		if(!strcmp(donneesClients[i].prenom, "0")) {
			break;
		}
		// Sortie de la boucle si l'utilisateur a entré "0"
		
		printf("Nom : ");
		fgets(donneesClients[i].nom, LG_MAX+1, stdin);
		donneesClients[i].nom[strlen(donneesClients[i].nom)-1] = '\0';
		// Saisie du nom (champ "nom" de la structure)
		
		printf("Solde : ");
		scanf("%lf", &donneesClients[i].solde);
		getchar();
		// Saisie de la solde (champ "solde" de la structure)
	
		i++;
	}	

	*pdonneesClients = donneesClients; // Epilogue

	return i;
}

int recherche(char *nom, char *prenom, client *donneesClients, int nbClients) {
	int i = 0;

	for(i = 0; i < nbClients; i++) { // Vérification pour tout rang du tableau
		if(!strcmp(donneesClients[i].nom, nom) && !strcmp(donneesClients[i].prenom, prenom)) { 
		// Si le nom ET le prénom correspondent à un rang du tableau
			return i; // Retour de l'identifiant du client
		}
	}

	return -1; // Si le client n'est pas trouvé, on renvoie un code d'erreur
}

void affichage(int id, client *donneesClients) {
	if(id >= 0) { // Si l'id est correct, affichage des informations
		printf("\nPrenom : %s\nNom : %s\nSolde : %.2lf\n\n", donneesClients[id].prenom, donneesClients[id].nom, donneesClients[id].solde); 
		// Affichage des informations du client au rang id du tableau
	}
	else {
		printf("\nLe client sélectionné n'existe pas.\n\n");
		// Traitement de l'erreur renvoyée par recherche si le client n'exite pas
	}
}

void retrait(int id, float montant, client *donneesClients) {
	if(id >= 0) {
		if(donneesClients[id].solde >= montant) {
			donneesClients[id].solde -= montant;
			printf("\nRetrait effectué. Votre nouveau solde est de %.2lf.\n\n", donneesClients[id].solde);
		}
		else {
			printf("\nVous avez spécifié un montant trop élevé.\n\n");
			// Le solde du client n'est pas suffisant pour faire le retrait
		}
	}
	else {
		printf("\nLe client sélectionné n'existe pas.\n\n");
		// Traitement de l'erreur renvoyée par recherche si le client n'exite pas
	}
}

void virement(int emetteur, int destinataire, float montant, client *donneesClients) {
	if(emetteur >= 0 && destinataire >= 0) {
		if(emetteur != destinataire) {
			if(donneesClients[emetteur].solde >= montant) {
				donneesClients[emetteur].solde -= montant;
				// Retrait de la somme du compte de l'émetteur
				donneesClients[destinataire].solde += montant;
				// Crédit de la somme du compte du récepteur
				printf("\nVirement effectué.\nLe nouveau solde de l'émetteur du virement (%s %s) est de %.2lf.\nLe nouveau solde du destinataire (%s %s) du virement est de %.2lf.\n\n", donneesClients[emetteur].prenom, donneesClients[emetteur].nom, donneesClients[emetteur].solde, donneesClients[destinataire].prenom, donneesClients[destinataire].nom, donneesClients[destinataire].solde);
				// Affichage du bilan du virement
			}
			else {
				printf("\nVous avez spécifié un montant trop élevé.\n\n");
				// Le solde du client n'est pas suffisant pour faire le retrait
			}
		}
		else {
			printf("\nVous ne pouvez pas virer d'argent à vous-même.\n\n");
			// L'émetteur et le récepteur sont identiques
		}
	}
	else {
		if(emetteur < 0) {
			printf("\nL'émetteur n'existe pas.\n\n");
			// Traitement de l'erreur renvoyée par recherche si l'émetteur n'exite pas
		}
		else if(destinataire < 0) {
			printf("\nLe destinataire n'existe pas.\n\n");
			// Traitement de l'erreur renvoyée par recherche si le destinataire n'exite pas
		}
	}
}
