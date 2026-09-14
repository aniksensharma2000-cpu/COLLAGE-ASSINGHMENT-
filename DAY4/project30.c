#include <stdio.h>

int main() {
    char ch;
    printf("Enter H or T for Heads and Tails: ");
  
    scanf(" %c", &ch); 

    if (ch == 'H' || ch == 'h') {
        printf("Captain 1 win\n");
    } else {
        printf("Captain 2 win\n");
    }

    return 0;
}