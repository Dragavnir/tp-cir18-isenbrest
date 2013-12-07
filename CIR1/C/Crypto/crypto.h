#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
// Histoire de pas avoir à retenir l'identifiant décimal ASCII de chaque caractère...
#define ALPHABET 26
#define A 65
#define Z 90
#define E 69

// Prototypes

// Partie 1
int testUpperCase(char);
char lowerToUpper(char);
// Partie 2
void encryption(int, char *, char *);
// Partie 3
void decryption(int, char *, char *);
// Partie 4
void freqAnalysis(char *, float *);
void printFreq(float *);
int computeKey(float *);
