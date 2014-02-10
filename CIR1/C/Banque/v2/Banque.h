#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#define LG_MAX 30

/*----- Structures -----*/

typedef struct {
	char nom[LG_MAX+2];
	char prenom[LG_MAX+2];
	double solde;
} client;

/*----- Prototypes -----*/

int saisie(client **donneesClients);
int recherche(char *nom, char *prenom, client *donneesClients, int nbClients);
void affichage(int id, client *donneesClients);
void retrait(int id, float montant, client *donneesClients);
void virement(int emetteur, int destinataire, float montant, client *donneesClients);
