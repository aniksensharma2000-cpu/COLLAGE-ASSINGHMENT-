#include <stdio.h>
int main() {
    int number, first_digit, second_digit, third_digit, sum;
    printf("Enter a 3-digit number: ");
    scanf("%d", &number);
    first_digit = number / 100;
    second_digit = (number / 10) % 10;
    third_digit = number % 10;
    sum = first_digit + second_digit + third_digit;
    printf("The sum of the digits is: %d\n", sum);
    return 0;
}
