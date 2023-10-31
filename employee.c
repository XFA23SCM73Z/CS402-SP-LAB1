#include "employee.h"
#include <stdio.h>

// Function to print a single employee's information
void printEmployee(const Employee *emp) {
    printf("\nEmployee ID: %d\n", emp->id);
    printf("First Name: %s\n", emp->first_name);
    printf("Last Name: %s\n", emp->last_name);
    printf("Salary: %d\n", emp->salary);
}