#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to convert degrees to radians
double degrees_to_radians(double degrees) {
    return degrees * (PI / 180.0);
}

// Function to rotate a point (x, y) by an angle (in degrees)
void rotate_point(double x, double y, double angle, double *new_x, double *new_y) {
    double radians = degrees_to_radians(angle);
    *new_x = x * cos(radians) - y * sin(radians);
    *new_y = x * sin(radians) + y * cos(radians);
}

// Function to calculate the polar coordinates
void cartesian_to_polar(double x, double y, double *r, double *theta) {
    *r = sqrt(x * x + y * y);
    *theta = atan2(y, x) * (180.0 / PI); // Convert to degrees
}

int main() {
    double x, y, angle;
    
    // Input Cartesian coordinates and angle
    printf("Enter the coordinates (x, y): ");
    scanf("%lf %lf", &x, &y);
    printf("Enter the rotation angle in degrees: ");
    scanf("%lf", &angle);

    // Rotate the point
    double new_x, new_y;
    rotate_point(x, y, angle, &new_x, &new_y);
    
    // Convert to polar coordinates
    double r, theta;
    cartesian_to_polar(new_x, new_y, &r, &theta);

    // Output results
    printf("New Cartesian Coordinates: (%.4lf, %.4lf)\n", new_x, new_y);
    printf("Polar Coordinates: (r = %.4lf, theta = %.4lf degrees)\n", r, theta);

    return 0;
}

