#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c,d;
    printf("Enter the value of a : \n");
    scanf("%f",&a);
    b=floor(a);
    printf("The floor of %f \n",b);
    printf("Enter the value of c : \n");
    scanf("%f",&c);
    d=ceil(c);
    printf("The ceil of %f \n",d);

}