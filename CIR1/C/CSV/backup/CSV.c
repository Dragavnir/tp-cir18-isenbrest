#include "CSV.h"

int main(int argc, char *argv[]) {
	FILE *csv_src = NULL;
	FILE *csv_dest = NULL;

	if(argc == 3) {
		csv_src = fopen(argv[1], "r");
		if(csv_src == NULL) {
			fprintf(stderr, "Impossible d'ouvrir le fichier %s !\n",
					argv[1]);
			return EXIT_FAILURE;
		}

		csv_dest = fopen(argv[2], "w");
		if(csv_dest == NULL) {
			fprintf(stderr, "Impossible de créer ou d'ouvrir le"
					"fichier %s !\n", argv[2]);
			return EXIT_FAILURE;
		}

		CSVToMail(csv_src, csv_dest);
	}
	else {
		fprintf(stderr, "Syntaxe : ./CSV source.csv destination.csv\n");
		return EXIT_FAILURE;
	}
	
	fclose(csv_src);
	fclose(csv_dest);
	return EXIT_SUCCESS;
}
