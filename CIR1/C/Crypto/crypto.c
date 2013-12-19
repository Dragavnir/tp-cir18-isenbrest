#include "crypto.h"

int main() {
	// Variables contenues dans le squelette annexé à l'énoncé
	char * name_pc = "ABOLIVIER";
	char * firstName_pc = "Brendan";
	char * text1_pc = "CeCI EsT uN BeaU MeSsAGE !";
	char * text2_pc = "Ave Caesar, moritori te salutant!";
	char * code3_pc = "ZNVGER PBEORNH, FHE HA NEOER CREPUR, GRANVG RA FBA ORP HA SEBZNTR. ZNVGER ERANEQ CNE Y'BQRHE NYYRPUR, YHV GVAG N CRH CERF PR YNATNTR : RG OBAWBHE ZBAFVRHE QH PBEORNH. DHR IBHF RGRF WBYV! DHR IBHF ZR FRZOYRM ORNH! FNAF ZRAGVE, FV IBGER ENZNTR FR ENCCBEGR N IBGER CYHZNTR IBHF RGRF YR CURAVK QRF UBGRF QR PRF OBVF. N PRF ZBGF YR PBEORNH AR FR FRAG CNF QR WBVR; RG CBHE ZBAGERE FN ORYYR IBVK, VY BHIER HA YNETR ORP YNVFFR GBZORE FN CEBVR. YR ERANEQ F'RA FNVFVG RG QVG : ZBA OBA ZBAFVRHE, NCERARM DHR GBHG SYNGGRHE IVG NH QRCRAF QR PRYHV DHV Y'RPBHGR : PRGGR YRPBA INHG OVRA HA SEBZNTR FNAF QBHGR. YR PBEORNH UBAGRHK RG PBASHF WHEN ZNVF HA CRH CYHF GNEQ, DH'BA AR Y'L CERAQENVG CYHF.";
	char * message1_pc = "VERCINGETORIX";
	char * message2_pc = "En l'occurrence l'imbecillite est un dilemme etymologique !";
	// Variables partie 2
	int key1_i = 3;
	char code1_pc[LG_MAX+1];
	int key2_i = 20;
	char code2_pc[LG_MAX+1];
	// Variables partie 3
	char decode1_pc[LG_MAX+1];
	char decode2_pc[LG_MAX+1];
	// Variables partie 4
	float * freq_pf = NULL;
	char decode3_pc[LG_MAX+1];
		
	printf("\n*** Programme de %s %s N1 2013-2014 ***\n", firstName_pc, name_pc);
	
	printf("\n---------------------- Part 1 ----------------------\n");
	
	printf("\nText 1 : \n\n");	
	printf("%s\tsize = %d\n", text1_pc, (int)strlen(text1_pc));
	while(*text1_pc != '\0') {
	// Affichage caractère par caractère
		printf("%d", testUpperCase(*text1_pc));
		text1_pc++;
	}
	
	printf("\n\n");
	
	printf("Text 2 : \n\n");
	printf("%s\tsize = %d\n", text2_pc, (int)strlen(text2_pc));
	while(*text2_pc != '\0') {
	// Affichage caractère par caractère
		printf("%c", lowerToUpper(*text2_pc));
		text2_pc++;
	}
	
	// Le reste du main() n'étant que de l'affichage et des appels de fonctions, je ne juge pas utile de commenter après cette ligne
	printf("\n\n");
	
	printf("\n---------------------- Part 2 ----------------------\n");
	
	printf("\nMessage 1 : \n\n");
	printf("%s\tsize = %d\n", message1_pc, (int)strlen(message1_pc));
	printf("\nKey 1 : \n\n");
	printf("%d\n", key1_i);
	
	encryption(key1_i, message1_pc, code1_pc);
	
	printf("\nCode 1 : \n\n");
	printf("%s\tsize = %d\n", code1_pc, (int)strlen(code1_pc));
	
	printf("\nMessage 2 : \n\n");
	printf("%s\tsize = %d\n", message2_pc, (int)strlen(message2_pc));
	printf("\nKey 2 : \n\n");
	printf("%d\n", key2_i);
	
	encryption(key2_i, message2_pc, code2_pc);
	
	printf("\nCode 2 : \n\n");
	printf("%s\tsize = %d\n", code2_pc, (int)strlen(code2_pc));
	
	printf("\n\n");
	
	printf("\n---------------------- Part 3 ----------------------\n");
	
	decryption(key1_i, code1_pc, decode1_pc);
	
	printf("\nDecode 1 : \n\n");
	printf("%s\tsize = %d\n", decode1_pc, (int)strlen(decode1_pc));
	
	decryption(key2_i, code2_pc, decode2_pc);
	
	printf("\nDecode 2 : \n\n");
	printf("%s\tsize = %d\n", decode2_pc, (int)strlen(decode2_pc));
	
	
	printf("\n\n");

	printf("\n---------------------- Part 4 ----------------------\n");
	
	printf("\nCode 3 : \n\n");
	printf("%s\tsize = %d\n\n", code3_pc, (int)strlen(code3_pc));
	
	freq_pf = freqAnalysis(code3_pc);
	
	if(!freq_pf) {
		printf("\nPas assez de mémoire pour continuer : Arrêt du programme...\n\n");
		return EXIT_FAILURE;
	}
	
	printFreq(freq_pf);
	
	printf("\nEstimated key : \n\n");
	printf("%d\n", computeKey(freq_pf));
	
	decryption(computeKey(freq_pf), code3_pc, decode3_pc);
	
	printf("\nDecode 3 : \n\n");
	printf("%s\tsize = %d\n\n", decode3_pc, (int)strlen(decode3_pc));

	return EXIT_SUCCESS;
}
