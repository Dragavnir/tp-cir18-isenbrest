#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define LG_MAX 10000
#define ALPHABET 26

// Prototypes

// Partie 1
int testUpperCase(char);
char lowerToUpper(char);
// Partie 2
void encryption(int, char *, char *);
// Partie 3
void decryption(int, char *, char *);
// Partie 4
float * freqAnalysis(char *);
void printFreq(float *);
int computeKey(float *);
