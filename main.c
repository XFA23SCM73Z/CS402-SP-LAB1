#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "readfile.h"
#include <string.h>
#define MAX_EMPLOYEES 1024

void printDatabase(Employee employees[], int count) {
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "First Name", "Last Name", "Salary");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%-10d %-20s %-20s %-10d\n",
               employees[i].id,
               employees[i].first_name,
               employees[i].last_name,
               employees[i].salary);
    }
    printf("------------------------------------------------------------\n");
    printf("\nTotal number of employees: %d\n", count);

}
int lookupByID(Employee employees[], int count, int id) {
    for (int i = 0; i < count; ++i) {
        if (employees[i].id == id) {
            printEmployee(&employees[i]);
            return i;
        }
    }
    return -1; // Not found
}
int lookupByLastName(Employee employees[], int count, char *lastName) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(employees[i].last_name, lastName) == 0) {
            printEmployee(&employees[i]);
            return i;
        }
    }
    return -1; // Not found
}
void addEmployee(Employee employees[], int *count) {
    // Check if the database is full
    if (*count >= MAX_EMPLOYEES) {
        printf("Error: Database is full.\n");
        return;
    }

    Employee newEmployee;

    // Prompt for ID
    printf("Enter new employee ID (6 digits): ");
    scanf("%d", &newEmployee.id);
    while (getchar() != '\n');  // Clear the input buffer

    if (newEmployee.id < 100000 || newEmployee.id > 999999) {
        printf("Error: Invalid ID. Must be a six-digit number.\n");
        return;
    }

    // Prompt for first name
    printf("Enter new employee's first name: ");
    scanf("%63s", newEmployee.first_name);
    while (getchar() != '\n');  // Clear the input buffer

    // Prompt for last name
    printf("Enter new employee's last name: ");
    scanf("%63s", newEmployee.last_name);
    while (getchar() != '\n');  // Clear the input buffer

    // Prompt for salary
    printf("Enter new employee's salary (30000 - 150000): ");
    scanf("%d", &newEmployee.salary);
    while (getchar() != '\n');  // Clear the input buffer

    if (newEmployee.salary < 30000 || newEmployee.salary > 150000) {
        printf("Error: Invalid salary. Must be between $30,000 and $150,000.\n");
        return;
    }

    // Once all fields are entered and validated:
    employees[*count] = newEmployee;  // Add the new employee to the array
    (*count)++;                       // Increment the employee count

    printf("New employee added successfully. Total employees: %d\n", *count);
}




int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int menuChoice;
    int id;
    char lastName[MAX_NAME];

    // Initialize the file reading library
    if (open_file(argv[1]) != 0) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        return EXIT_FAILURE;
    } else {
        printf("Successfully opened file '%s'\n", argv[1]);

    }

    while (employeeCount < MAX_EMPLOYEES) {
        int readID, readSalary;
        char readFirstName[MAX_NAME], readLastName[MAX_NAME];

        if (read_int(&readID) == 0) {
            fprintf(stderr, "The total employee count is %d\n", employeeCount);
            break;
        }

        if (read_string(readFirstName, MAX_NAME) != 0) {
            //fprintf(stderr, "Error reading first name for employee %d\n", employeeCount + 1);
            break;
        }
        if (read_string(readLastName, MAX_NAME) != 0) {
            //fprintf(stderr, "Error reading last name for employee %d\n", employeeCount + 1);
            break;
        }
        if (read_int(&readSalary) == 0) {
           // fprintf(stderr, "Error reading salary for employee %d\n", employeeCount + 1);
            break;
        }

        // Debug print to verify the read data
        //printf("Debug: Read employee: ID: %d, First Name: %s, Last Name: %s, Salary: %d\n",
         //      readID, readFirstName, readLastName, readSalary);

        employees[employeeCount].id = readID;
        strncpy(employees[employeeCount].first_name, readFirstName, MAX_NAME - 1);
        employees[employeeCount].first_name[MAX_NAME - 1] = '\0'; // Ensure null-termination
        strncpy(employees[employeeCount].last_name, readLastName, MAX_NAME - 1);
        employees[employeeCount].last_name[MAX_NAME - 1] = '\0'; // Ensure null-termination
        employees[employeeCount].salary = readSalary;
        employeeCount++;
    }

    // Close the file as it is no longer needed
    close_file();

    // Main menu loop
    do {
        printf("\nEmployee Database Main Menu\n");
        printf("1. Print the Database\n");
        printf("2. Lookup employee by ID\n");
        printf("3. Lookup employee by last name\n");
        printf("4. Add an Employee\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &menuChoice);
        if (menuChoice < 1 || menuChoice > 5) {
            printf("Hey, %d is not between 1 and 5, try again...\n", menuChoice);
        } else {
            switch (menuChoice) {
                case 1:
                    printDatabase(employees, employeeCount);
                    break;
                case 2:
                    printf("Enter employee ID: ");
                    scanf("%d", &id);
                    if (lookupByID(employees, employeeCount, id) == -1) {
                        printf("Employee with ID %d not found.\n", id);
                    }
                    break;
                case 3:
                    printf("Enter employee last name: ");
                    scanf("%63s", lastName); // Assuming last names are less than 64 characters
                    if (lookupByLastName(employees, employeeCount, lastName) == -1) {
                        printf("Employee with last name %s not found.\n", lastName);
                    }
                    break;
                case 4:
                    // prompt for each field, validate it, and if validation passes,
                    // add the employee to the array and increment `employeeCount`.
                    addEmployee(employees, &employeeCount);
                    break;
                case 5:
                    printf("Exiting the program.\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        }
    } while (menuChoice != 5);

    return EXIT_SUCCESS;
}

