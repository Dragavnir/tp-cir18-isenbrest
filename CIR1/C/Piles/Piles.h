#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#define MAX_PILE 5

int push(int data, int *stack, int *indice_top);
int pop(int *stack, int *indice_top, int * data);
int peek(int *stack, int indice_top, int * data);
int empty(int indice_top);
int full(int indice_top);
