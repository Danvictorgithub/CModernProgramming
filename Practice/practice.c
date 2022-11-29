#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int gcd(int a, int b) {
	if (a % b == 0){
		return b;
	}
	else {
		return gcd(a / b, a % b);
	}
}
int main() {
	// get 5 words
	// char *wordlist[5] = {0};
	// char word[25], *temp;
	// for (int i = 0; i < 4; i++) {
	// 	scanf("%s",word);

	// 	temp = malloc(sizeof(char) + strlen(word));
	// 	strcpy(temp,word);
	// 	wordlist[i]= temp;
	// 	printf("copied: %s\n", temp);
	// }
	// printf("The sentence is:\n");
	// for (int i = 0; i < 4;i++) {
	// 	printf("%s ", wordlist[i]);
	// }
	printf("%d",gcd(4,24));
	return 0;
}
