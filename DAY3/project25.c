#include <stdio.h>

int main() {
    int ns, hr, m, s;

    printf("Input no. of sec: ");
    scanf("%d", &ns);

    hr = ns / 3600;
    ns = ns % 3600;

    m = ns / 60;
    s = ns % 60;

    printf("%d hr(s)\n", hr);
    printf("%d Min(s)\n", m);
    printf("%d sec(s)\n", s);

    return 0;
}