#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#define LG_MAX 30

typedef struct {
	char *nom;
	char *prenom;
	double solde;
} client;

int saisie(client *donneesClients);
int recherche(char *nom, char *prenom, client *donneesClients, int nbClients);
void affichage(int id, client *donneesClients);
