#include "stdio.h" 	// Diréctives de préprocesseur (ou de précompilation)
int main() 		// Début du programme (start), et en-tête de la fonction main (principale)
{			// Ouverture du corps de la fonction main (début des instructions)

	/* Instructions */
	int a = 12;	// Déclaration avec initialisation
	char b = 255;
	short c = 127;
	long d = 15;
	printf("\na = %d, longueur = %d\n", a, sizeof(a)); // Appel de fonction standard
	printf("b = %d, longueur = %d\n", b, sizeof(b));
	printf("c = %d, longueur = %d\n", c, sizeof(c));
	printf("d = %d, longueur = %d\n\n", d, sizeof(d));

	printf("b = %c\n", b); // Affiche le caractère
	printf("b = %x\n \n", b); // Affiche en hexadécimal
}			// Fermeture du corps de la fonction main
