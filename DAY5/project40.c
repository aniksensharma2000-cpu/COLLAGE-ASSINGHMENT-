
#include <stdio.h>

int main()
{
	int sum = 0;
	for (int number = 1; number <= 20; number++)
	{
		sum += number * 1;
	}
	printf("Sum of the first 20 natural numbers = %d\n", sum);
	return 0;
}

