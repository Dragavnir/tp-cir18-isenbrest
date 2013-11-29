#include <stdio.h>
#include <stdlib.h>
#define MAXL 100

void strcpy(char * dest, const char * src) {
	while(*src != '\0') {
		*dest = *src;
		src++;
		dest++;
	}	
	*dest = '\0';
}

int main() {
	char ch1[MAXL] = "bonjour";
	char ch2[MAXL];
	
	strcpy(ch2, ch1);
	
	printf("ch1 : %s, ch2 : %s\n", ch1, ch2);
	
	return EXIT_SUCCESS;
}
