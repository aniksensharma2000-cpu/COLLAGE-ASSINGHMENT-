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
		c=c+d*d*d;
		
	}
	if(m==c)
	printf("Amstrong number");
	else
	printf(" not a amstrong number ");
	
	return 0 ;
	
}
