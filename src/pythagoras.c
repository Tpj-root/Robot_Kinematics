#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate hypotenuse
double find_hypotenuse(double a, double b) {
    return sqrt(a * a + b * b);
}

// Function to calculate opposite side
double find_opposite(double h, double adjacent) {
    return sqrt(h * h - adjacent * adjacent);
}

// Function to calculate adjacent side
double find_adjacent(double h, double opposite) {
    return sqrt(h * h - opposite * opposite);
}

int main(int argc, char *argv[]) {
    int choice;
    double a, b, h;

    // If no arguments are provided, ask the user for input
    if (argc == 1) {
        printf("What do you want to find?\n");
        printf("0: Opposite side\n");
        printf("1: Hypotenuse\n");
        printf("2: Adjacent side\n");
        printf("Enter your choice (0, 1, or 2): ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                // Find opposite side
                printf("Enter the length of the hypotenuse: ");
                scanf("%lf", &h);
                printf("Enter the length of the adjacent side: ");
                scanf("%lf", &a);
                b = find_opposite(h, a);
                printf("The length of the opposite side is: %.2f\n", b);
                break;

            case 1:
                // Find hypotenuse
                printf("Enter the length of side a (opposite or adjacent): ");
                scanf("%lf", &a);
                printf("Enter the length of side b (other side): ");
                scanf("%lf", &b);
                h = find_hypotenuse(a, b);
                printf("The length of the hypotenuse is: %.2f\n", h);
                break;

            case 2:
                // Find adjacent side
                printf("Enter the length of the hypotenuse: ");
                scanf("%lf", &h);
                printf("Enter the length of the opposite side: ");
                scanf("%lf", &b);
                a = find_adjacent(h, b);
                printf("The length of the adjacent side is: %.2f\n", a);
                break;

            default:
                printf("Invalid choice. Please enter 0, 1, or 2.\n");
                break;
        }
    } else if (argc == 4) {
        // Command-line argument input handling
        choice = atoi(argv[1]);  // Get the choice from command-line arguments
        a = atof(argv[2]);       // First input value
        b = atof(argv[3]);       // Second input value

        switch (choice) {
            case 0:
                // Find opposite side
                //printf("You chose to find the opposite side.\n");
                //printf("Hypotenuse: %.2f, Adjacent: %.2f\n", a, b);
                //printf("The length of the opposite side is: %.2f\n", find_opposite(a, b));
                printf("%.2f\n", find_opposite(a, b));
                break;

            case 1:
                // Find hypotenuse
                // printf("You chose to find the hypotenuse.\n");
                // printf("Side a: %.2f, Side b: %.2f\n", a, b);
                // printf("The length of the hypotenuse is: %.2f\n", find_hypotenuse(a, b));
                printf("%.2f\n", find_hypotenuse(a, b));
                break;

            case 2:
                // Find adjacent side
                // printf("You chose to find the adjacent side.\n");
                // printf("Hypotenuse: %.2f, Opposite: %.2f\n", a, b);
                // printf("The length of the adjacent side is: %.2f\n", find_adjacent(a, b));
                printf("%.2f\n", find_adjacent(a, b));
                break;

            default:
                printf("Invalid choice. Please use 0, 1, or 2.\n");
                break;
        }
    } else {
        printf("Invalid number of arguments. Usage:\n");
        printf("./program <choice> <value1> <value2>\n");
        printf("Where <choice> is 0 for opposite, 1 for hypotenuse, 2 for adjacent\n");
    }

    return 0;
}

