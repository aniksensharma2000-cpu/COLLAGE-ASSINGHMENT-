#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d%d", &n, &m);
    
    // Ternary operator: prints the maximum of m and n
    (m > n) ? printf("%d\n", m) : printf("%d\n", n);
    
    return 0;
}


