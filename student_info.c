#include <stdio.h>
#include <string.h>

#define MAX 100

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

// Function declarations
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

void printLine(char ch, int length) {
    for (int i = 0; i < length; i++) printf("%c", ch);
    printf("\n");
}

int main() {
    int choice;

    do {
        printLine('=', 50);
        printf("      STUDENT INFO MANAGEMENT SYSTEM\n");
        printLine('=', 50);
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printLine('-', 50);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline char

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("\nExiting Program. Thank you!\n"); break;
            default: printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

// Add a new student
void addStudent() {
    if (count >= MAX) {
        printf("Database is full! Cannot add more students.\n");
        return;
    }

    printf("\n\n--- Add New Student ---\n\n");
    printf("Enter Roll No       : ");
    scanf("%d", &students[count].rollNo);
    getchar();
    printf("Enter Name          : ");
    fgets(students[count].name, 50, stdin);
    students[count].name[strcspn(students[count].name, "\n")] = '\0';
    printf("Enter Marks (0-100) : ");
    scanf("%f", &students[count].marks);

    count++;
    printf("Student added successfully!\n\n");
}

// Display all students
void displayStudents() {
    if (count == 0) {
        printf("\nNo student records available.\n\n");
        return;
    }

    printf("\nList of Students:\n\n");
    printLine('-', 50);
    printf("%-10s | %-25s | %-6s\n", "Roll No", "Name", "Marks");
    printLine('-', 50);

    for (int i = 0; i < count; i++) {
        printf("%-10d | %-25s | %-6.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].marks);
    }

    printLine('-', 50);
}

// Search for a student
void searchStudent() {
    int roll, found = 0;
    printf("\nEnter Roll No to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\nStudent Found:\n");
            printLine('-', 30);
            printf("Roll No : %d\n", students[i].rollNo);
            printf("Name    : %s\n", students[i].name);
            printf("Marks   : %.2f\n", students[i].marks);
            printLine('-', 30);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll No %d not found.\n\n", roll);
    }
}

// Update student
void updateStudent() {
    int roll, found = 0;
    printf("\nEnter Roll No to update: ");
    scanf("%d", &roll);
    getchar();

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("Enter New Name       : ");
            fgets(students[i].name, 50, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
            printf("Enter New Marks      : ");
            scanf("%f", &students[i].marks);

            printf("Record updated successfully.\n\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll No %d not found.\n\n", roll);
    }
}

// Delete student
void deleteStudent() {
    int roll, found = 0;
    printf("\nEnter Roll No to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully.\n\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll No %d not found.\n\n", roll);
    }
}
