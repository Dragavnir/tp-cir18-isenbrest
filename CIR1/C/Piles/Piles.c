#include "Piles.h"

int main() {
	int stack[MAX_PILE];
	int data;
	int indice_top = -1;
	int choix;
	int i = 0;
	int answer;

	// Tester plusieurs push, plusieurs pop, un peak

	while(1) {
		printf("\nQue voulez-vous faire ?\n"
			"\t1 : Empiler\n"
			"\t2 : Dépiler\n"
			"\t3 : Lire le sommet\n"
			"\t4 : Tester si la pile est vide\n"
			"\t5 : Tester si la pile est pleine\n"
			"\t6 : Quitter\n\n"
			"Votre choix : ");
		scanf("%d", &choix);
		

		switch(choix) {
			case 1:
				for(i = 0; i < MAX_PILE; i++) {
					printf("\nEntrez un entier : ");
					scanf("%d", &data);
					answer = push(data, stack, &indice_top);
					if(answer) {
						printf("Insertion réussie !\n");
					} else {
						printf("Pile pleine !\n");
						break;
					}
				}
				break;
			case 2:
				answer = pop(stack, &indice_top, &data);
				if(answer) {
					printf("La valeur %d a été retirée de"
						"la pile !\n", data);
				} else {
					printf("Plus d'élément dans la pile !\n");
					break;
				}
				break;
			case 3:
				answer = peek(stack, indice_top, &data);
				if(answer) {
					printf("\nElement au sommet de la "
						"pile : %d\n", data);
				} else {
					printf("Aucun élément dans la pile !\n");
				}
				break;
			case 4:
				answer = empty(indice_top);
				if(answer) {
					printf("\nLa pile est vide !\n");
				} else {
					printf("\nLa pile n'est pas vide !\n");
				}
				break;
			case 5:
				answer = full(indice_top);
				if(answer) {
					printf("\nLa pile est pleine !\n");
				} else {
					printf("\nLa pile n'est pas pleine !\n");
				}
				break;
			case 6:
				return EXIT_SUCCESS;
			default:
				printf("\nChoix invalide !");
				break;
		}
	}
}
