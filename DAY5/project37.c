
#include <stdio.h>

int main()
{
	int sum = 0;
	for (int number = 1; number <= 10; number++)
	{
		sum += number * number;
	}
	printf("Sum of squares of the first 10 natural numbers = %d\n", sum);
	return 0;
}

