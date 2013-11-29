#include <stdlib.h>
#include <stdio.h>

void swap(int * pa, int * pb) {
	int c = *pa;
	*pa = *pb;
	*pb = c;
}

int main() {
	int i = 1, j = 0;
	swap(&i,&j);
	printf("i = %d, j = %d\n", i, j);
	return EXIT_SUCCESS;
}
