#include <stdio.h>
#include <string.h>

// Structure to represent a class
struct Class {
    char name[50];
    char details[200];
};

// Function prototype
void welcomePage();

// Function to display the student menu
void studentMenu(struct Class classes[], int numClasses) {
    int option;
    
    do {
        printf("\nStudent Menu:\n");
        printf("1. Search for a class\n");
        printf("2. List all classes\n");
        printf("3. View class name and details\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Implement search for a class functionality
                // You can prompt the user to enter a class name or other criteria for searching
                printf("Searching for a class...\n");
                break;

            case 2:
                // Implement listing all classes functionality
                printf("List of all classes:\n");
                for (int i = 0; i < numClasses; i++) {
                    printf("%d. %s\n", i + 1, classes[i].name);
                }
                break;

            case 3:
                // Implement viewing class name and details functionality
                // You can prompt the user to enter the class index or name
                printf("Enter the index of the class you want to view: ");
                int classIndex;
                scanf("%d", &classIndex);

                if (classIndex >= 1 && classIndex <= numClasses) {
                    printf("Class Name: %s\n", classes[classIndex - 1].name);
                    printf("Class Details: %s\n", classes[classIndex - 1].details);
                } else {
                    printf("Invalid class index.\n");
                }
                break;

            case 4:
                printf("Exiting the Student Menu.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (option != 4);
}

// Function to display the welcome page
void welcomePage() {
    printf("Welcome to the School Management System!\n");
    printf("Please identify yourself:\n");
    printf("1. Teacher\n");
    printf("2. Student\n");
}

int main() {
    // Dummy data for classes
    struct Class classes[3] = {
        {"Math", "Introduction to Mathematics"},
        {"Science", "Basic Science Concepts"},
        {"History", "World History Overview"}
    };

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
        // Call the student menu
        studentMenu(classes, 3);  // Assuming there are 3 classes in the example
    } else {
        printf("Invalid choice. Please run the program again and enter a valid choice.\n");
    }

    return 0;
}
