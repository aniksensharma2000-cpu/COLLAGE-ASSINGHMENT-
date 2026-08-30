#include <stdio.h>

int main() {
    int ndays, y, m, d;

    printf("Input no. of days: ");
    scanf("%d", &ndays);

    y = ndays / 365;
    ndays = ndays % 365;

    m = ndays / 30;
    d = ndays % 30;

    printf("%d Year(s)\n", y);
    printf("%d Month(s)\n", m);
    printf("%d Day(s)\n", d);

    return 0;
}