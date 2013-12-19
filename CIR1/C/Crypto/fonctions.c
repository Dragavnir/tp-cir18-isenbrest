#include "crypto.h"
/*------------------------------- Partie 1 -------------------------------*/
int testUpperCase(char letter_c) {
	return letter_c >= 'A' && letter_c <= 'Z';
}

char lowerToUpper(char letter_c) {
	return (letter_c >= 'a' && letter_c <= 'z')?letter_c-32:letter_c;
}

/*------------------------------- Partie 2 -------------------------------*/
void encryption(int key_i, char * text_pc, char * code_pc) {
	
	while(*text_pc != '\0') {
		*code_pc = lowerToUpper(*text_pc);		
		if(testUpperCase(*code_pc)) {
			*code_pc = 'A' + ((*code_pc - 'A' + key_i)%ALPHABET);
		}
		text_pc++;
		code_pc++;
	}
	*code_pc = '\0';
}

/*------------------------------- Partie 3 -------------------------------*/
void decryption(int key_i, char * code_pc, char * decode_pc) {

	while(*code_pc != '\0') {
		*decode_pc = lowerToUpper(*code_pc);
		if(testUpperCase(*decode_pc)) {
			*decode_pc = 'A' + ((*decode_pc - 'A' + key_i)%ALPHABET);
		}
		code_pc++;
		decode_pc++;
	}
	*decode_pc = '\0';
}

/*------------------------------- Partie 4 -------------------------------*/
float * freqAnalysis(char * code_pc) {
	float * tab_pf = malloc((ALPHABET+1)*sizeof(float));
	int i = 0;
	int lettres_i = 0;
	
	if(tab_pf != NULL) { // Si malloc a pu allouer l'espace pour 
		while(*code_pc != '\0') {
			if(testUpperCase(*code_pc)) {
				tab_pf[*code_pc - 'A']++;
				lettres_i++;
			}
			code_pc++;
		}
		for(i = 0; i < ALPHABET; i++) {
			tab_pf[i] = tab_pf[i]/(float)lettres_i * 100;
		}
		return tab_pf;
	}
	return 0;
}

void printFreq(float * tab_pf) {
	int count_i = 0;
	int count2_i = 0;
	int fiveCounter_i = 0;
	
	// Une simple automatisation de l'affichage
	for(count_i = 0; count_i < ALPHABET; count_i++) {
		fiveCounter_i++;
		printf("%c\t", count_i+'A');
		
		if(fiveCounter_i == 5) {
		// Affichage d'une nouvelle ligne toutes les 5 lettres (voir énoncé)
			printf("\n");
			for(count2_i = 5; count2_i > 0; count2_i--) {
				printf("%3.1f\t", tab_pf[count_i-count2_i+1]);
			}
			printf("\n");
			fiveCounter_i = 0;
		}
	}
	// La dernière valeur n'étant pas affichée par la boucle, on s'en charge
	printf("\n%3.1f\n", tab_pf[ALPHABET-1]);
}

int computeKey(float * tab_pf) {
	int rank_i = 0;
	int count_i = 0;
	
	for(count_i = 0; count_i < ALPHABET; count_i++) { // On recherche le rang du tableau contenant le plus haut pourcentage
		if(tab_pf[count_i] > rank_i) {
			rank_i = count_i;
		}
	}
	if('A'+rank_i < 'E') { // Cas où A + la clé est inférieur à E (codes décimaux ASCII)
		return 'Z'-rank_i-'E'+1;
	}
	return 'A'+rank_i-'E'; // Cas où A + la clé est supérieur ou égal à E (codes décimaux ASCII)
}
