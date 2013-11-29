#include <stdio.h>
#include <stdlib.h>
#define MAXL 100

void strcpy(char * dest, const char * src) {
	int i = 0;
	while(src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}	
	dest[i] = '\0';
}

int main() {
	char ch1[MAXL] = "bonjour";
	char ch2[MAXL] = "aaaaaaaaaaaaaaaaaaaaaa";
	
	strcpy(ch2, ch1);
	
	printf("ch1 : %s, ch2 : %s\n", ch1, ch2);
	
	return EXIT_SUCCESS;
}
