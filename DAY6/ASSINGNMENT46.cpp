#include<stdio.h>
int main()
{
	int n,m,d,c=0;
	printf("Enter a number :");
	scanf("%d",&n);
	m=n;
	while(n!=0)
	{
		d=n%10;
		n=n/10;
		c=c*10+d;
		
	}
	if(m==c)
	printf(" Palindromic  number");
	else
	printf("Not a palindromic number ");
	
	return 0;
}
