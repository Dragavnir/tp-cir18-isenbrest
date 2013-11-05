#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
	char tab1[N] = {'a', 'b', 'c', 'd', 'e'};
	char tab2[N] = {'b', 'a', 'c', 'a', 'e'};
	char tab[N];
	int i, j;
	int valeursCommunes = 0;
	
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(tab2[j] == tab1[i]) {
				valeursCommunes++;
				break;
			}
		}
	}
	
	printf("\nValeurs communes : %d\n\n", valeursCommunes);
	return EXIT_SUCCESS;
}
