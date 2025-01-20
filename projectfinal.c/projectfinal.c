#include <stdio.h>
#include <string.h>

// Using global arrays since we're avoiding structs
char names[50][50];  // Can store 50 names, each up to 50 characters
int roll_numbers[50];
int ages[50];
float marks[50];
int total_students = 0;

// Function to add a new student
void addStudent() {
    printf("\nEnter student details:\n");
    printf("Name: ");
    scanf(" %[^\n]s", names[total_students]);

    printf("Roll Number: ");
    scanf("%d", &roll_numbers[total_students]);

    printf("Age: ");
    scanf("%d", &ages[total_students]);

    printf("Marks: ");
    scanf("%f", &marks[total_students]);

    total_students++;
    printf("\nStudent added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (total_students == 0) {
        printf("\nNo students found!\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("Name\t\tRoll No\tAge\tMarks\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < total_students; i++) {
        printf("%s\t\t%d\t%d\t%.2f\n", 
            names[i], roll_numbers[i], ages[i], marks[i]);
    }
}

// Function to save records to file
void saveToFile() {
    FILE *file = fopen("students.txt", "w");

    if (file == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    // Writing total number of students first
    fprintf(file, "%d\n", total_students);

    // Writing each student's data
    for (int i = 0; i < total_students; i++) {
        fprintf(file, "%s\n%d\n%d\n%.2f\n", 
            names[i], roll_numbers[i], ages[i], marks[i]);
    }

    fclose(file);
    printf("\nData saved to file successfully!\n");
}

// Function to load records from file
void loadFromFile() {
    FILE *file = fopen("students.txt", "r");

    if (file == NULL) {
        printf("\nNo existing file found!\n");
        return;
    }

    // Reading total number of students
    fscanf(file, "%d", &total_students);

    // Reading each student's data
    for (int i = 0; i < total_students; i++) {
        fscanf(file, " %[^\n]s", names[i]);
        fscanf(file, "%d", &roll_numbers[i]);
        fscanf(file, "%d", &ages[i]);
        fscanf(file, "%f", &marks[i]);
    }

    fclose(file);
    printf("\nData loaded from file successfully!\n");
}

int main() {
    int choice;

    // Load any existing data when program starts
    loadFromFile();

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Save to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}