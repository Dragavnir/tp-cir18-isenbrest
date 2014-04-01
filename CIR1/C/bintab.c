#include <stdlib.h>
#include <stdio.h>
#define TAB_ROWS 2095200

int main() {
	int i = 0;
	float temperature[TAB_ROWS];
	FILE *fp = NULL;

	for(i = 0; i < TAB_ROWS; i++) {
		temperature[i] = (float)i/3;
	}

	fp = fopen("yola", "w");

	fwrite(temperature, sizeof(float), TAB_ROWS, fp);

	fclose(fp);

/*	fp = fopen("yola", "r");

	fread(temperature, sizeof(float), TAB_ROWS, fp);

	for(i = 0; i < TAB_ROWS; i++) {
		printf("Valeur %d : %f\n", i, temperature[i]);
	}

	fclose(fp);
*/
}
