#include <stdio.h>
#include <math.h>
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num );
    printf("Square root of %d is %f\n", num, sqrt(num));
    return 0;
}