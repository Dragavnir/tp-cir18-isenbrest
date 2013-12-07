#include "crypto.h"

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

void encryption(int key_i, char * text_pc, char * code_pc) {
	while(*text_pc != '\0') {
		*code_pc = lowerToUpper(*text_pc);
		
		if(testUpperCase(*code_pc)) {
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

void decryption(int key_i, char * code_pc, char * decode_pc) {
	while(*code_pc != '\0') {
		*decode_pc = lowerToUpper(*code_pc);
		
		if(testUpperCase(*decode_pc)) {
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

void freqAnalysis(char * code_pc, float * tab_pf) {
	int acc_i = 0;
	int i = 0;
	int longueur_i = (int)strlen(code_pc);
	
	for(i = 0; i < ALPHABET; i++) {
		char * pcode_pc = code_pc;
		acc_i = 0;
		
		while(*pcode_pc != '\0') {
			if(*pcode_pc == i+A) {
				acc_i++;
			}
			pcode_pc++;
		}
		tab_pf[i] = ((float)acc_i/(float)longueur_i)*100;
	}
}

void printFreq(float * tab_pf) {
	int count_i = 0;
	int count2_i = 0;
	int fiveCounter_i = 0;
	
	for(count_i = 0; count_i < ALPHABET; count_i++) {
		fiveCounter_i++;
		printf("%c\t", count_i+A);
		
		if(fiveCounter_i == 5) {
			printf("\n");
			for(count2_i = 5; count2_i > 0; count2_i--) {
				printf("%3.1f\t", tab_pf[count_i-count2_i+1]);
			}
			printf("\n");
			fiveCounter_i = 0;
		}
	}
	
	printf("\n%3.1f\n", tab_pf[ALPHABET-1]);
}

// They say I don't work, I don't know why.
// I say I don't work too. Still don't know why.
int computeKey(float * tab_pf) {
	int rank_i = 0;
	int count_i = 0;
	
	for(count_i = 0; count_i < ALPHABET; count_i++) {
		if(tab_pf[count_i] > rank_i) {
			rank_i = count_i;
		}
	}
	
	if(A+rank_i < E) {
		return Z-rank_i-E+1;
	}
	
	return A+rank_i-E;
}
