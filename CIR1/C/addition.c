#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

int main(int argc, char **argv) {
	
	if(argc!= 3) {
		printf("Usage : ./addition nombre1 nombre2\n");
		return EXIT_FAILURE;
	}
	
	printf("%.2f + %.2f = %.2f\n", atof(argv[1]), atof(argv[2]), atof(argv[1])+atof(argv[2]));

	return EXIT_SUCCESS;
}
