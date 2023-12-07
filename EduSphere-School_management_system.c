#include <stdio.h>
#include <string.h>

// Function to display the welcome page and identify the user
void welcomePage() {
    printf("Welcome to the School Management System!\n");
    printf("Please identify yourself:\n");
    printf("1. Teacher\n");
    printf("2. Student\n");
}

int main() {
    // Variables to store user choice and name
    int choice;
    char name[50];

    // Display the welcome page
    welcomePage();

    // Get user choice
    printf("Enter your choice (1 for Teacher, 2 for Student): ");
    scanf("%d", &choice);

    // Get user name
    printf("Enter your name: ");
    scanf("%s", name);

    // Display a personalized message based on the user's choice
    if (choice == 1) {
        printf("Hello, %s! You are a teacher.\n", name);
        // Add teacher-related functionality here
    } else if (choice == 2) {
        printf("Hello, %s! You are a student.\n", name);
        // Add student-related functionality here
    } else {
        printf("Invalid choice. Please run the program again and enter a valid choice.\n");
    }

    return 0;
}
