#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	FILE *fp = NULL;
	fp = fopen("yolo", "w");

	printf("Tapez un entier : ");
	scanf("%d", &n);

	fwrite(&n, sizeof(int), 1, fp);

	printf("Tapez un second entier : ");
	scanf("%d", &n);

	fwrite(&n, sizeof(int), 1, fp);

	fclose(fp);

	fp = fopen("yolo", "r");

	fread(&n, sizeof(int), 1, fp);

	printf("Premier entier : %d\n", n);

	fread(&n, sizeof(int), 1, fp);

	printf("Second envier : %d\n", n);

	fclose(fp);
}
