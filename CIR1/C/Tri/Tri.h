#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <time.h>

#define TAILLE		10
#define LG_MAX		1000

void tri_insertion(int *tab, int n);
int comp_int(const int *a, const int *b);
int comp_string(const void *a, const void *b);
