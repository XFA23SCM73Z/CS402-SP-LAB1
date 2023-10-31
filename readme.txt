# Employee Database Project

## Overview
This project is a C program for managing an employee database. It allows the user to perform various operations such as adding new employees, searching for employees by ID or last name, and printing the entire database.

## Features
- Load employee data from a file.
- Print out the entire employee database.
- Lookup employee details using their ID.
- Lookup employee details using their last name.
- Add a new employee to the database.
- Interactive user interface via command-line.

## Prerequisites
- GCC compiler or any standard C compiler.
- Make sure all the project files are in the same directory.


To test the file, 
	1.Open the Terminal in CLion or use an external Terminal application.
	2.Change directory to the project's directory:
	3.Then change directory to the build directory: cd cmake-build-debug
	4.run the executable with the input file like : ./CS402_SP_LAB1 ./input.txt
The program will show the menu choice , then can enter the choice digits to start test.

Sample terminal output:

Successfully opened file './input.txt'

Employee Database Main Menu
1. Print the Database
2. Lookup employee by ID
3. Lookup employee by last name
4. Add an Employee
5. Quit
Enter choice: 1

ID         First Name           Last Name            Salary    
------------------------------------------------------------
165417     Cathryn              Danner               72000     
273225     Matt                 Meeden               69000     
633976     Martine              Marshall             99000     
471163     Robert               Dufour               91000     
499959     Mike                 Griffin              72000     
547935     Daniel               McNamee              71000     
553997     Peter                Olsen                82000     
702234     Jean                 Jones                94000     
784372     Dana                 Parrish              87000     
786785     Ann                  Coddington           82000     
849387     Melissa              Dufour               114000    
485913     Dylan                Steinberg            84000     
935460     Heather              James                98000     
970016     Russ                 Vorobiev             109000    
------------------------------------------------------------

Total number of employees: 14

Employee Database Main Menu
1. Print the Database
2. Lookup employee by ID
3. Lookup employee by last name
4. Add an Employee
5. Quit
Enter choice: 5
Exiting the program.

