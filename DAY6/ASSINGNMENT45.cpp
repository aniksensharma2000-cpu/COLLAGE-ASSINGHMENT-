#include<stdio.h>
int main()
{
	int d,n,c=0;
	printf("Enter a number :");
	scanf("%d",&n);
	
	while (n!=0);
	{
		d=n%10;
			c=c*10+d;
		n=n/10;
		
	}
	printf("%d",c);
	return 0;
}
