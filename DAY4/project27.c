#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        return 1;
    }

    if (a > b && a >= c) {
        printf("%d is the greatest\n", a);
    } else if (b >= a && b >= c) {
        printf("%d is the greatest\n", b);
    } else {
        printf("%d is the greatest\n", c);
    }

    return 0;
}