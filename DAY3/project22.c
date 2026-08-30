#include <stdio.h>
int main()
{
	float basic,da,hra,sl,as;
	
	printf("enter basic\n");
		scanf("%f",&basic);
		da=0.5*basic;
	hra=0.1*basic;
	sl=basic+da+hra+5000;
	as=sl*12;
		printf("the anuual%f\n",as);
		return 0;

}
