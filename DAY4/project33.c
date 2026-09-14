#include <stdio.h>

int main() 
{
    float s, t;
    
    printf("enter annual salary: ");
    scanf("%f", &s);
    
    if (s <= 250000) {
        t = 0;
    } 
    else if (s > 250000 && s <= 500000) 
    {
        t = 0.05 * s;
    } 
    else if (s > 500000 && s <= 1000000) 
    {
        t = 0.1 * s;
    } else {
        t = 0.3 * s;
    }
    
    printf("the tax to be paid is %f\n", t);
    return 0;
}