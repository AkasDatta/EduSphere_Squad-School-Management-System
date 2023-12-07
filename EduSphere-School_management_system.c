#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent a class
struct Class {
    char name[50];
    char teacher[50];
    char genre[50];
    char details[200];
    char classTime[50];
    int studentQuantity;
    int enrolled;  // Flag to indicate whether a student is enrolled
};

// Function prototypes
void welcomePage();
void studentMenu(struct Class classes[], int numClasses);
void searchAndEnroll(struct Class classes[], int numClasses);
void enrollInClass(struct Class *class);
void checkout(struct Class classes[], int numClasses);
void teacherMenu(struct Class classes[], int numClasses);
void viewInventory(struct Class classes[], int numClasses);
void addNewClass(struct Class classes[], int *numClasses);
void deleteClass(struct Class classes[], int *numClasses);
void updateClassQuantity(struct Class classes[], int numClasses);

// Function to display the welcome page
void welcomePage() {
    printf("Welcome to the School Management System!\n");
    printf("Please identify yourself:\n");
    printf("1. Teacher\n");
    printf("2. Student\n");
}

// Function to enroll in a class
void enrollInClass(struct Class *class) {
    // Check if the class is in stock
    if (class->studentQuantity > 0) {
        // Ask if the student wants to enroll
        char enrollChoice;
        printf("Do you want to enroll in this class? (y/n): ");
        scanf(" %c", &enrollChoice);

        // Enroll in multiple classes if desired
        while (enrollChoice == 'y' || enrollChoice == 'Y') {
            printf("Enrolled in the class!\n");
            class->enrolled = 1;  // Set the enrolled flag
            class->studentQuantity--; // Decrease available student quantity
            printf("Do you want to enroll in another class? (y/n): ");
            scanf(" %c", &enrollChoice);
        }
    } else {
        printf("Sorry, this class is out of stock.\n");
    }
}

// Function to display the student menu
void studentMenu(struct Class classes[], int numClasses) {
    int option;
    
    do {
        printf("\nStudent Menu:\n");
        printf("1. Search for a class and enroll\n");
        printf("2. List all classes\n");
        printf("3. View class name and details\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");

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
                    printf("   Teacher: %s\n", classes[i].teacher);
                    printf("   Genre: %s\n", classes[i].genre);
                    printf("   Class Time: %s\n", classes[i].classTime);
                    printf("   Student Quantity: %d\n", classes[i].studentQuantity);
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
                // Implement checkout functionality
                checkout(classes, numClasses);
                break;

            case 5:
                printf("Exiting the Student Menu.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (option != 5);
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
                enrollInClass(&classes[i]);  // Enroll in the class
            }

            matchFound = 1;
        }
    }

    if (!matchFound) {
        printf("No matching classes found.\n");
    }
}

// Function to process checkout
void checkout(struct Class classes[], int numClasses) {
    printf("Checkout process initiated...\n");
    // Add any additional checkout logic here
    // This could include generating a receipt, updating student records, etc.
    printf("Checkout completed. Thank you for using the School Management System!\n");
}

// Function to validate the teacher password
bool validateTeacherPassword() {
    char password[50];
    printf("Enter the teacher password: ");
    scanf("%s", password);

    // Compare the entered password with the correct password
    return strcmp(password, "111111") == 0; // Change "your_teacher_password" to the actual password
}

// Function to display the teacher menu
void teacherMenu(struct Class classes[], int numClasses) {
    // Validate the teacher password
    if (!validateTeacherPassword()) {
        printf("Incorrect password. Access denied.\n");
        return;
    }

    int option;

    do {
        printf("\nTeacher Menu:\n");
        printf("1. View inventory\n");
        printf("2. Add a new class\n");
        printf("3. Delete a class\n");
        printf("4. Update class quantity\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Implement view inventory functionality
                viewInventory(classes, numClasses);
                break;

            case 2:
                // Implement adding a new class functionality
                addNewClass(classes, &numClasses);
                break;

            case 3:
                // Implement deleting a class functionality
                deleteClass(classes, &numClasses);
                break;

            case 4:
                // Implement updating class quantity functionality
                updateClassQuantity(classes, numClasses);
                break;

            case 5:
                printf("Exiting the Teacher Menu.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (option != 5);
}

// Function to view inventory
void viewInventory(struct Class classes[], int numClasses) {
    printf("Inventory:\n");
    for (int i = 0; i < numClasses; i++) {
        printf("%d. %s\n", i + 1, classes[i].name);
        printf("   Teacher: %s\n", classes[i].teacher);
        printf("   Genre: %s\n", classes[i].genre);
        printf("   Class Time: %s\n", classes[i].classTime);
        printf("   Student Quantity: %d\n", classes[i].studentQuantity);
    }
}

// Function to add a new class
void addNewClass(struct Class classes[], int *numClasses) {
    // Implement the logic to add a new class
    // You can prompt the teacher to enter details for the new class
    // and add it to the classes array
    printf("Enter details for the new class:\n");

    // Increment the number of classes
    (*numClasses)++;

    // Get details for the new class
    printf("Name: ");
    scanf("%s", classes[*numClasses - 1].name);

    printf("Teacher: ");
    scanf("%s", classes[*numClasses - 1].teacher);

    printf("Genre: ");
    scanf("%s", classes[*numClasses - 1].genre);

    printf("Details: ");
    scanf("%s", classes[*numClasses - 1].details);

    printf("Class Time: ");
    scanf("%s", classes[*numClasses - 1].classTime);

    printf("Student Quantity: ");
    scanf("%d", &classes[*numClasses - 1].studentQuantity);

    classes[*numClasses - 1].enrolled = 0; // Initialize enrolled flag to 0

    printf("New class added successfully!\n");
}

// Function to delete a class
void deleteClass(struct Class classes[], int *numClasses) {
    // Implement the logic to delete a class
    // You can prompt the teacher to enter the class index or name
    // and then remove it from the classes array
    int classIndex;
    printf("Enter the ID of the class you want to delete: ");
    scanf("%d", &classIndex);

    if (classIndex >= 1 && classIndex <= *numClasses) {
        // Shift the classes array to remove the specified class
        for (int i = classIndex - 1; i < *numClasses - 1; i++) {
            strcpy(classes[i].name, classes[i + 1].name);
            strcpy(classes[i].teacher, classes[i + 1].teacher);
            strcpy(classes[i].genre, classes[i + 1].genre);
            strcpy(classes[i].details, classes[i + 1].details);
            strcpy(classes[i].classTime, classes[i + 1].classTime);
            classes[i].studentQuantity = classes[i + 1].studentQuantity;
            classes[i].enrolled = classes[i + 1].enrolled;
        }

        // Decrement the number of classes
        (*numClasses)--;

        printf("Class deleted successfully!\n");
    } else {
        printf("Invalid class ID.\n");
    }
}

// Function to update class quantity
void updateClassQuantity(struct Class classes[], int numClasses) {
    // Implement the logic to update the quantity of a class
    // You can prompt the teacher to enter the class index or name
    // and then update the quantity
    int classIndex;
    printf("Enter the ID of the class you want to update: ");
    scanf("%d", &classIndex);

    if (classIndex >= 1 && classIndex <= numClasses) {
        printf("Enter the new quantity for the class: ");
        scanf("%d", &classes[classIndex - 1].studentQuantity);

        printf("Class quantity updated successfully!\n");
    } else {
        printf("Invalid class ID.\n");
    }
}

int main() {
    // Dummy data for classes
    struct Class classes[3] = {
        {"Math", "Mr. Smith", "Mathematics", "Introduction to Mathematics", "Monday 9:00 AM", 20, 0},
        {"Science", "Ms. Johnson", "Science", "Basic Science Concepts", "Wednesday 2:00 PM", 34, 0},
        {"History", "Mr. Davis", "History", "World History Overview", "Friday 11:00 AM", 10, 0}
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
        // Call the teacher menu
        teacherMenu(classes, 3);  // Assuming there are 3 classes in the example
    } else if (choice == 2) {
        printf("Hello, %s! You are a student.\n", name);
        // Call the student menu
        studentMenu(classes, 3);  // Assuming there are 3 classes in the example
    } else {
        printf("Invalid choice. Please run the program again and enter a valid choice.\n");
    }

    return 0;
}
