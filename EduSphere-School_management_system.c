#include <stdio.h>
#include <string.h>

// Structure to represent a class
struct Class {
    char name[50];
    char teacher[50];
    char genre[50];
    char details[200];
    int enrolled;  // Flag to indicate whether a student is enrolled
};

// Function prototypes
void welcomePage();
void studentMenu(struct Class classes[], int numClasses);
void searchAndEnroll(struct Class classes[], int numClasses);

// Function to display the welcome page
void welcomePage() {
    printf("Welcome to the School Management System!\n");
    printf("Please identify yourself:\n");
    printf("1. Teacher\n");
    printf("2. Student\n");
}

// Function to display the student menu
void studentMenu(struct Class classes[], int numClasses) {
    int option;
    
    do {
        printf("\nStudent Menu:\n");
        printf("1. Search for a class and enroll\n");
        printf("2. List all classes\n");
        printf("3. View class name and details\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Implement search and enroll functionality
                searchAndEnroll(classes, numClasses);
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

// Function to search for a class and enroll
void searchAndEnroll(struct Class classes[], int numClasses) {
    char searchCriteria[50];
    printf("Enter the class name, teacher name, or genre to search: ");
    scanf("%s", searchCriteria);

    int matchFound = 0;

    for (int i = 0; i < numClasses; i++) {
        if (strstr(classes[i].name, searchCriteria) != NULL ||
            strstr(classes[i].teacher, searchCriteria) != NULL ||
            strstr(classes[i].genre, searchCriteria) != NULL) {

            // Display the search result
            printf("Match found!\n");
            printf("Class Name: %s\n", classes[i].name);
            printf("Teacher: %s\n", classes[i].teacher);
            printf("Genre: %s\n", classes[i].genre);
            printf("Details: %s\n", classes[i].details);

            // Check if the student is already enrolled
            if (classes[i].enrolled) {
                printf("You are already enrolled in this class.\n");
            } else {
                // Ask if the student wants to enroll
                char enrollChoice;
                printf("Do you want to enroll in this class? (y/n): ");
                scanf(" %c", &enrollChoice);

                if (enrollChoice == 'y' || enrollChoice == 'Y') {
                    printf("Enrolled in the class!\n");
                    classes[i].enrolled = 1;  // Set the enrolled flag
                } else {
                    printf("Not enrolled in the class.\n");
                }
            }

            matchFound = 1;
        }
    }

    if (!matchFound) {
        printf("No matching classes found.\n");
    }
}

int main() {
    // Dummy data for classes
    struct Class classes[3] = {
        {"Math", "Mr. Smith", "Mathematics", "Introduction to Mathematics", 0},
        {"Science", "Ms. Johnson", "Science", "Basic Science Concepts", 0},
        {"History", "Mr. Davis", "History", "World History Overview", 0}
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
