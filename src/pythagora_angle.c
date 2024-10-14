#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c; // sides of the triangle
    printf("Enter the lengths of the sides (a, b): ");
    
    // Update the scanf to read input correctly, expect space-separated values
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input. Please enter two numbers separated by a space.\n");
        return 1; // Exit if the input is not valid
    }

    // Calculate the hypotenuse
    c = sqrt(a * a + b * b); 

    // Calculate angles in degrees
    double angleA = atan(b / a) * (180.0 / M_PI); // Angle opposite side a
    double angleB = atan(a / b) * (180.0 / M_PI); // Angle opposite side b
    double angleC = 90.0; // Right angle

    // Print the angles
    printf("Angle A: %lf degrees\n", angleA);
    printf("Angle B: %lf degrees\n", angleB);
    printf("Angle C: %lf degrees\n", angleC);

    return 0;
}
