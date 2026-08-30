#include <stdio.h>

int main() {
    int num1;
    printf("Enter number: ");
    scanf("%d",&num1);
    (num1%4==0)?printf("leap year"):printf("not leap year");

    return 0;
}
