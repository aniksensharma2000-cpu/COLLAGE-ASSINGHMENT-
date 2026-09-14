#include <stdio.h>

int main() {
    float e, r;
    
    printf("Enter electric reading: ");
    if (scanf("%f", &e) != 1) {
        printf("Invalid input.\n");
    }
    if (e < 0) {
        printf("Reading cannot be negative.\n");
    }
    if (e <= 100) {
        r = e * 10.0;
    } 
    else if (e <= 150) {
        r = (100 * 10.0) + (e - 100) * 15.0;
    } 
    else if (e <= 200) {
        r = (100 * 10.0) + (50 * 15.0) + (e - 150) * 20.0;
    } 
    else {
        r = (100 * 10.0) + (50 * 15.0) + (50 * 20.0) + (e - 200) * 25.0;
    }
    printf("Rate = %f\n", r);
    return 0;                    
}