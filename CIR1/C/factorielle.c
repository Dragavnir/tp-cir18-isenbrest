#include <stdio.h>
#include <stdlib.h>

int factorielle(int n) {
	int fact = 1;
	int i;
	for(i = 1; i <= n; i++) {
		fact = fact*i;
	}
	return fact;
}

int factoRecursif(int n) {
	if(n==0) {
		return 1;
	}
	return n*factoRecursif(n-1);
}

int main() {
	int fact;
	printf("Merci de rentrer une factorielle : ");
	scanf("%d!", &fact);
	printf("fact(%d) = %d\n", fact, factorielle(fact));
	printf("Avec appel récursif : fact(%d) = %d\n", fact, factoRecursif(fact));
	return EXIT_SUCCESS;
}
