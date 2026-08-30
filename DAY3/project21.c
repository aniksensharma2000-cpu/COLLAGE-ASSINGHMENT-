#include <stdio.h>

int main() {
  
    int roll1;
    float sub1, sub2, sub3, sub4, sub5;
    float total1, per1;
    int roll2;
    float subj1, subj2, subj3, subj4, subj5;
    float total2, per2;
    printf("Enter Roll Number for Student 1: ");
    scanf("%d", &roll1);
    printf("Enter marks for 5 subjects for Student 1: ");
    scanf("%f %f %f %f %f", &sub1, &sub2, &sub3, &sub4, &sub5);
    printf("\nEnter Roll Number for Student 2: ");
    scanf("%d", &roll2);
    printf("Enter marks for 5 subjects for Student 2: ");
    scanf("%f %f %f %f %f", &subj1, &subj2, &subj3, &subj4, &subj5);
    total1 = sub1 + sub2 + sub3 + sub4 + sub5;
    total2= subj1 + subj2 + subj3 + subj4 + subj5;
    per1 = (total1 / 500.0) * 100;
    per2 = (total2 / 500.0) * 100;
    (per1 > per2)?printf(" Roll No: %d\n", roll1):(per2 > per1)? printf("Roll No: %d\n", roll2): printf("\nBoth students have the same percentage (%.2f%%).\n", per1);

    return 0;
}
