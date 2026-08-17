#include <stdio.h>
int main(){
    int num,last_digit;
    printf("enter a number: ");
    scanf("%d",&num);
    last_digit= num-(num/10)*10;
    printf("last digit=%d",last_digit);
    return 0;
}