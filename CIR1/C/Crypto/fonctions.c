#include "crypto.h"

int testUpperCase(char letter_c) {
	if(letter_c >= 65 && letter_c <= 90) {
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
				*code_pc = key_i+*code_pc-26;
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
				*decode_pc = *decode_pc-key_i+26;
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
