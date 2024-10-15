#include <stdio.h>
#include <stdlib.h>

// Function to display options and handle pagination
void display_options(int start) {
    int choice;

    while (1) {
        // Clear the terminal
        system("clear");

        // Custom header for the current page
        printf("Options %d to %d:\n", start, start + 2);  // Adjusted for the number of options
        printf("What do you want to find?\n");

        // Display specific options
        if (start == 0) {
            printf("0: Opposite side\n");
            printf("1: Hypotenuse\n");
            printf("2: Adjacent side\n");
        } else if (start == 10) {
            // Add more options if needed for the next page
            printf("10: Option 10\n");
            printf("11: Option 11\n");
            printf("12: Option 12\n");
        } else if (start == 20) {
            // Placeholder for future options or next page
            printf("20: Option 20\n");
            printf("21: Option 21\n");
            printf("22: Option 22\n");
        }
        
        printf(">: Next page\n");
        printf("<: Previous page\n");
        printf("Enter your choice: ");

        // Accept user input
        char input[10];
        scanf("%s", input);

        // Check for pagination input
        if (input[0] == '>') {
            start += 10;  // Move to the next page
        } else if (input[0] == '<') {
            start = (start > 10) ? start - 10 : 0;  // Move to the previous page
        } else {
            choice = atoi(input);  // Convert input to an integer choice
            if (choice >= start && choice < start + 10) {
                printf("You selected option %d.\n", choice);
                // Handle the selected option here
                break;  // Exit the loop after handling the choice
            } else {
                printf("Invalid choice. Please enter a valid option or a pagination command.\n");
            }
        }
    }
}

int main() {
    // Start displaying from the first page
    display_options(0);
    
    return 0;
}
