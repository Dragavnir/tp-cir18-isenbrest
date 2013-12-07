#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define ALPHABET 26
#define A 65
#define Z 90
#define E 69

// Prototypes

int testUpperCase(char);
char lowerToUpper(char);
void encryption(int, char *, char *);
void decryption(int, char *, char *);
void freqAnalysis(char *, float *);
void printFreq(float *);
int computeKey(float *);
