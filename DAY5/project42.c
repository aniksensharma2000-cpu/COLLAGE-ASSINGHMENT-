#include <stdio.h>

int main(){
	int number;

	printf("Enter a positive integer: ");
	scanf("%d", &number);

	if (number <= 0)
	{
		printf("Please enter a positive integer.\n");
		return 1;
	}

	printf("Factors of %d are: ", number);

	for (int factor = 1; factor <= number; factor++)
	{
		if (number % factor == 0)
		{
			printf("%d ", factor);
		}
	}

	printf("\n");

	return 0;
}
