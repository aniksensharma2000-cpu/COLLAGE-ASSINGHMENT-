#include <stdio.h>
int main() {
    int choice;
    float area, r, side, length, breadth, base, height;
    printf("Choose a shape to find the area:\n");
    printf("1. Circle\n");
    printf("2. Square\n");
    printf("3. Rectangle\n");
    printf("4. Triangle\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter radius of the circle: ");
            scanf("%f", &r);
            area = 3.14159 * r * r;
            printf("Area of the circle = %.2f\n", area);
            break;
        case 2:
            printf("Enter side of the square: ");
            scanf("%f", &side);
            area = side * side;
            printf("Area of the square = %.2f\n", area);
            break;
        case 3:
            printf("Enter length and breadth of the rectangle: ");
            scanf("%f %f", &length, &breadth);
            area = length * breadth;
            printf("Area of the rectangle = %.2f\n", area);
            break;
        case 4:
            printf("Enter base and height of the triangle: ");
            scanf("%f %f", &base, &height);
            area = 0.5 * base * height;
            printf("Area of the triangle = %.2f\n", area);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}