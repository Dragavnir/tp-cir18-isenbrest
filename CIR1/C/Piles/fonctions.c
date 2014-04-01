#include "Piles.h"

int push(int data, int *stack, int *indice_top) {
	if(!full(indice_top)) {
		(*indice_top)++;
		stack[*indice_top] = data;
		return 1;
	} else {
		return 0;
	}
}

int pop(int *stack, int *indice_top, int *data) {
	if(!empty(*indice_top)) {
		*data = stack[*indice_top];
		(*indice_top)--;
		return 1;
	} else {
		return 0;
	}
}

int peek(int *stack, int indice_top, int *data) {
	if(!empty(indice_top)) {
		*data = stack[indice_top];
		return 1;
	} else {
		return 0;
	}
}

int empty(int indice_top) {
	if(indice_top < 0) {
		return 1;
	} else {
		return 0;
	}
}

int full(int indice_top) {
	if(indice_top == MAX_PILE-1) {
		return 1;
	} else {
		return 0;
	}
}
