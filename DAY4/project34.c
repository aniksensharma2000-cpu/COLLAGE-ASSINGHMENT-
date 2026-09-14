#include <stdio.h>
int main()
{
    int n, y = 0, m = 0, d = 0;
    printf("enter days :");
    scanf("%d", &n);
    if (n >= 365){
        y = n / 365;
        m = (n % 365) / 30;
        d = n - (y * 365) - (m * 30);
    }
    else if (n >= 30){
        m = n / 30;
        d = n % 30;
    } else {
        d = n;
    }
    printf("%d years, %d months, %d days", y, m, d);
    return 0;
}