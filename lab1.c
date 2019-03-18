#include <stdio.h>

int main() {
	const int maxSize = 32;
	int firstDigit;

	char userInput(maxSize);

	fgets( userInput, maxSize, stdin );

	if ( userInput[0] >= '0' && userInput[0] <= '9' ) {
		firstDigit = userInput[0] - '0';
		printf("The first digit is %d\n", firstDigit);
	}
}


#include <stdio.h>
#include <stdlib.h>

int main() {
	int size = 0;
	int firstDigit = 0;

	char *userInput;

	printf("How much do you want to type? ");
	scanf("%d\n", &size);

	userInput(char *) malloc (size * sizeof(char));
	fgets( userInput, size, stdin);

	if (userInput[0] >= '0' && userInput[0] <= '9')
}