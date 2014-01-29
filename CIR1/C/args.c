#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

int main(int argc, char **argv) {
	if(argc!= 3) {
		printf("Usage : ./args nom prenom\n");
		return EXIT_FAILURE;
	}
	printf("Votre nom est %s et votre prénom est %s\n", argv[1], argv[2]);
	return EXIT_SUCCESS;
}
