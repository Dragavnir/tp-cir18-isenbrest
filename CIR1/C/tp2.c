#include "stdio.h"
int main() {
	char a = 'z';
	int b = 28;
	short c = 12;
	printf("Adresse de a : %p\n", &a);
	printf("Adresse de b : %p\n", &b);
	printf("Adresse de c : %p\n\n", &c);
	// Saisie de variables
	printf("Tapez un caractère : ");
	scanf("%c", &a); // Jamais de texte entre les guillemets d'un scanf
	printf("Tapez un entier : ");
	scanf("%d", &b);
	printf("Valeur de a : %c\n", a);
	printf("Valeur de b : %d\n", b);
	printf("\a");
}
