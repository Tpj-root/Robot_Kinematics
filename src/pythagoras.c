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


// calculate_triangle_angles_degrees
struct Angles {
    double angleA;
    double angleB;
    double angleC;
};


struct Angles calculate_triangle_angles(double a, double b) {
    struct Angles angles;
    
    angles.angleA = atan(b / a) * (180.0 / M_PI); // Angle opposite side a
    angles.angleB = atan(a / b) * (180.0 / M_PI); // Angle opposite side b
    angles.angleC = 90.0; // Right angle

    return angles;  // Return the struct
}


// Function to display options and handle pagination
int get_user_choice(int start) {
    int choice;

    while (1) {
        // Clear the terminal
        system("clear");

        // Custom header for the current page
        printf("Options %d to %d:\n", start, start + 9);  // Adjusted for the number of options
        printf("What do you want to find?\n");

        // Display specific options
        if (start == 0) {
            printf("0: Opposite side\n");
            printf("1: Hypotenuse\n");
            printf("2: Adjacent side\n");
            printf("3: Calculate angles in triangle\n");
            printf("3: Option \n");
            printf("4: Option \n");
            printf("5: Option \n");
            printf("6: Option \n");
            printf("7: Option \n");
            printf("8: Option \n");
            printf("9: Option \n");
            printf(">: Next page\n");
            printf("<: Previous page\n");
            printf("Enter your choice (0 to 9 or 'q' to quit): ");

        } else if (start == 10) {
            // Add more options if needed for the next page
            printf("10: Option 10\n");
            printf("11: Option 11\n");
            printf("12: Option 12\n");
            printf("13: Option 13\n");
            printf("14: Option 14\n");
            printf("15: Option 15\n");
            printf("16: Option 16\n");
            printf("17: Option 17\n");
            printf("18: Option 18\n");
            printf("19: Option 19\n");
            printf(">: Next page\n");
            printf("<: Previous page\n");
            printf("Enter your choice (10 to 19 or 'q' to quit): ");
        } else if (start == 20) {
            // Placeholder for future options or next page
            printf("20: Option 20\n");
            printf("21: Option 21\n");
            printf("22: Option 22\n");
            printf("23: Option 23\n");
            printf("24: Option 24\n");
            printf("25: Option 25\n");
            printf("26: Option 26\n");
            printf("27: Option 27\n");
            printf("28: Option 28\n");
            printf("29: Option 29\n");
            printf(">: Next page\n");
            printf("<: Previous page\n");
            printf("Enter your choice (20 to 29 or 'q' to quit): ");
        }
        
        // Accept user input
        char input[10];
        scanf("%s", input);

        // Check for pagination input
        if (input[0] == '>') {
            start += 10;  // Move to the next page
        } else if (input[0] == '<') {
            start = (start > 10) ? start - 10 : 0;  // Move to the previous page
        } else if (input[0] == 'q') { // Check for quit command
            exit(0); // Exit the program
        } else {
            choice = atoi(input);  // Convert input to an integer choice
            if (choice >= start && choice < start + 10) {
                return choice;
                //printf("You selected option %d.\n", choice);
                // Handle the selected option here
                break;  // Exit the loop after handling the choice
            } else {
                printf("Invalid choice. Please enter a valid option or a pagination command.\n");
            }
        }

    }
}


// handle_invalid_choice
void handle_invalid_choice() {
    printf("Invalid choice. Please enter 0, 1, 2 or 3.\n");
}


int main(int argc, char *argv[]) {
    int choice;
    double a, b, h;

    // If no arguments are provided, ask the user for input
    if (argc == 1) {
        choice = get_user_choice(0);

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

            case 3:
                // Find adjacent side
                printf("Enter the lengths of the sides a : ");
                scanf("%lf", &a);
                printf("Enter the lengths of the sides b : ");
                scanf("%lf", &b);
                struct Angles angles = calculate_triangle_angles(a, b);
                printf("Angle A: %lf degrees\n", angles.angleA);
                printf("Angle B: %lf degrees\n", angles.angleB);
                printf("Angle C: %lf degrees\n", angles.angleC);
                break;

            default:
                handle_invalid_choice();
                break;
        }
    } else if (argc == 4) {
        // Command-line argument input handling
        choice = atoi(argv[1]);  // Get the choice from command-line arguments
        a = atof(argv[2]);       // First input value
        b = atof(argv[3]);       // Second input value
        struct Angles angles;    // Declare outside the switch block

        switch (choice) {
            case 0:
                // Find opposite side
                printf("%.2f\n", find_opposite(a, b));
                break;

            case 1:
                // Find hypotenuse
                printf("%.2f\n", find_hypotenuse(a, b));
                break;

            case 2:
                // Find adjacent side
                printf("%.2f\n", find_adjacent(a, b));
                break;
            case 3:
                // Find adjacent side
                angles = calculate_triangle_angles(a, b);
                printf("%lf %lf %lf \n", angles.angleA, angles.angleB, angles.angleC);
                break;

            default:
                handle_invalid_choice();
                break;
        }
    } else {
        printf("Invalid number of arguments. Usage:\n");
        printf("../pythagoras <choice> <value1> <value2>\n");
        printf("Where <choice> is 0 for opposite, 1 for hypotenuse, 2 for adjacent\n");
    }

    return 0;
}