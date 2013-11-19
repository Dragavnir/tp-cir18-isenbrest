#include <stdio.h>
#include <stdlib.h>

int main () {
	char *pa = NULL;
	char tab[5] = {'a', 'b', 'c', 'd', 'e'};
	pa = tab;
	printf("%c\n", *pa);
	pa++;
	printf("%c\n", *pa);
	printf("%c\n", *(pa+1));
	printf("%d\n", pa-tab);
	printf("tab[2] : %c\n", *(pa+2));
	return EXIT_SUCCESS;
}
