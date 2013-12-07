#include "crypto.h"
/*------------------------------- Partie 1 -------------------------------*/
int testUpperCase(char letter_c) {
	if(letter_c >= A && letter_c <= Z) {
		return 1;
	}
	return 0;
}

char lowerToUpper(char letter_c) {
	if(letter_c >= 97 && letter_c <= 122) {
		return letter_c-32;
	}
	return letter_c;
}

/*------------------------------- Partie 2 -------------------------------*/
void encryption(int key_i, char * text_pc, char * code_pc) {

	while(key_i < -26) { // Si la clé est inférieure à -26
		key_i = key_i+26;
		key_i = 26-(-key_i);
	}
	
	while(key_i > 26) { // Si la clé est supérieure à 26
		key_i = key_i-26;
	}

	while(*text_pc != '\0') {
		*code_pc = lowerToUpper(*text_pc);
		
		if(testUpperCase(*code_pc)) {
			// La vérification suivante permet de laisser intacts les espaces et éléments de ponctuation
			if(!testUpperCase(*code_pc+key_i)) {
				*code_pc = key_i+*code_pc-ALPHABET;
			}
			else {
				*code_pc = *code_pc+key_i;
			}
		}
		text_pc++;
		code_pc++;
	}
	*code_pc = '\0';
}

/*------------------------------- Partie 3 -------------------------------*/
void decryption(int key_i, char * code_pc, char * decode_pc) {
	// Cette fonction est très proche de la précédente. Pour tout dire, j'ai juste changé le nom des variables et remplacé des + par des - (et inversement), sinon c'est du banal copié-collé.
	
	if(key_i < -26) { // Si la clé est inférieure à -26
		key_i = key_i+26;
		key_i = 26-(-key_i);
	}
	
	if(key_i > 26) { // Si la clé est supérieure à 26
		key_i = key_i-26;
	}
	
	while(*code_pc != '\0') {
		*decode_pc = lowerToUpper(*code_pc);
		
		if(testUpperCase(*decode_pc)) {
			// La vérification suivante permet de laisser intacts les espaces et éléments de ponctuation
			if(!testUpperCase(*decode_pc-key_i)) {
				*decode_pc = *decode_pc-key_i+ALPHABET;
			}
			else {
				*decode_pc = *decode_pc-key_i;
			}
		}
		code_pc++;
		decode_pc++;
	}
	*decode_pc = '\0';
}

/*------------------------------- Partie 4 -------------------------------*/
void freqAnalysis(char * code_pc, float * tab_pf) {
	int acc_i = 0;
	int i = 0;
	int longueur_i = (int)strlen(code_pc);
	
	// Oui, ça fait mélange un peu barbare entre pointeurs et indices, mais c'est le moyen le plus simple que je voie
	for(i = 0; i < ALPHABET; i++) {
		char * pcode_pc = code_pc;
		acc_i = 0;
		
		while(*pcode_pc != '\0') { 
		// Cette boucle comptabilise le nombre de fois que la lettre sélectionnée est trouvée dans la chaîne
			if(*pcode_pc == i+A) {
				acc_i++;
			}
			pcode_pc++;
		}
		tab_pf[i] = ((float)acc_i/(float)longueur_i)*100; // Calcul du pourcentage (avec cast explicite pour rendre en float)
	}
}

void printFreq(float * tab_pf) {
	int count_i = 0;
	int count2_i = 0;
	int fiveCounter_i = 0;
	
	// Une simple automatisation de l'affichage
	for(count_i = 0; count_i < ALPHABET; count_i++) {
		fiveCounter_i++;
		printf("%c\t", count_i+A);
		
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
	
	for(count_i = 0; count_i < ALPHABET; count_i++) {
	// On recherche le rang du tableau contenant le plus haut pourcentage
		if(tab_pf[count_i] > rank_i) {
			rank_i = count_i;
		}
	}
	
	if(A+rank_i < E) {
	// Cas où A + la clé est inférieur à E (codes décimaux ASCII)
		return Z-rank_i-E+1;
	}
	
	// Cas où A + la clé est supérieur ou égal à E (codes décimaux ASCII)
	return A+rank_i-E;
}
