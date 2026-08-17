#include <stdio.h>
int main(){
    int p,t,r,i;
    printf("enter principle, time and rate: ");
    scanf("%d %d %d",&p,&t,&r);
    i=(p*t*r)/100;
    printf("simple interest=%d",i);
    return 0;
}