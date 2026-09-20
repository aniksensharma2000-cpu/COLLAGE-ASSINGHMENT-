#include<stdio.h>
int main()
{
	int d, n,c=0;
	printf("Enter a number :");
	scanf("%d",&n);
	
	while(n!=0)
	{
		d=n%10;
		n=n/10;
		c=c+d;
		
	}printf("the sum of the digits are %d",c);
	return 0;
}
