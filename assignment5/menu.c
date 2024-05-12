// Author: Sama Ahmed
// Contact: 26samahmed@csu.fullerton.edu
// Course ID: CPSC223C
// Due Date: 2024-May-13 at 11:59 PM
// Program name: Menu Options for Binary file

// This program takes the user to input separators. I then print the tokens which is the text in between those
// user-specified separators.

// Program was developed and tested on: Ubuntu

// Programming language: C language
// Date development begun: 2024-May-11
// Date of last update:    2024-May-11
// Status: Worked on options M, X, P, O, F. I have N and R left
// Compile:  gcc -c -Wall -m64 -no-pie -o menu.o menu.c -lm -std=c2x
// Link:  gcc -m64 -no-pie -o menu.out menu.o -lm -std=c2x

//======== Begin source code ==========

#include <stdio.h> //Provides access to printf and scanf
#include <string.h>
#include <stdlib.h>
#include "student.h"

// Convert to the value to string
const char *convertEnum(enum classLevel level)
{
  switch (level)
  {
  case freshman:
    return "freshman";
  case sophomore:
    return "sophomore";
  case junior:
    return "junior";
  case senior:
    return "senior";
  default:
    return "unknown";
  }
}

// Display all the options for the user to choose from
void show_menu() {
  printf("O = Output all student records\n");
  printf("F = Find and show a student by cwid number\n");
  printf("P = Position: show the struc data at a given position.\n");
  printf("M = Menu: show this menu\n");
  printf("N = New student will be added to the student roster file.\n");
  printf("R = Remove a student’s data\n");
  printf("X = Exit from this program.\n");
}

// Display the data in the binary file
void display_output() {
  FILE *st_data = fopen("csuf.bin", "r+b");
  struct Student student;
  int counter = 0;
  while (fread(&student, sizeof(struct Student), 1, st_data) > 0)
  {
    ++counter;
    printf("name = %s\n", student.name);
    printf("cwid = %d\n", student.cwId);
    printf("major = %s\n", student.major);
    printf("class level = %s\n", convertEnum(student.level));
    printf("zip = %d\n", student.zipCode);
    printf("\n\n-------------------------------------\n\n");
  }
  printf("Number of data records is %d.\n", counter);

  //TODO: If there is negative cwid, then do not ouput the data.
  //TODO: Fix the last student record being printed twice.
}

void display_at_position() {
  int index = 0;
  printf("What position do you wish to view? ");
  scanf("%d", &index);
  printf("\nThe data record at position %d is this.\n", index);


  FILE *st_data = fopen("csuf.bin", "r+b");
  struct Student student;
  int counter = 0;
  while (fread(&student, sizeof(struct Student), 1, st_data) > 0)
  {
    // if we reach the specified position then print the data
    if (counter == index) {
      printf("name = %s\n", student.name);
      printf("cwid = %d\n", student.cwId);
      printf("major = %s\n", student.major);
      printf("class level = %s\n", convertEnum(student.level));
      printf("zip = %d\n", student.zipCode);
      break;
    } else {
      // Otherwise, move to the next index
      ++counter;
    }
  }
}

void display_by_cwid() {
  int campusWideID;
  printf("Please enter a student's CWID to see their record: ");
  scanf("%d", &campusWideID);
  printf("\nThe data record for the student with cwid %d is this.\n\n", campusWideID);
  FILE *st_data = fopen("csuf.bin", "r+b");
  struct Student student;
  int counter = 0;
  while (fread(&student, sizeof(struct Student), 1, st_data) > 0)
  {
    // if we find the campus wide id then print the data
    if (student.cwId == campusWideID)
    {
      printf("name = %s\n", student.name);
      printf("cwid = %d\n", student.cwId);
      printf("major = %s\n", student.major);
      printf("class level = %s\n", convertEnum(student.level));
      printf("zip = %d\n", student.zipCode);
      break;
    }
    else
    {
      // Otherwise, move to the next index
      ++counter;
    }
  }
}

int main(int argc, char *argv[])
{
  printf("\nWelcome to student roster file\n");
  printf("We keep your records current.\n");
  printf("The program is maintained by by Sama Ahmed\n\n");
  printf("Please Select one of the following options by entering the associated single character.\n");
  show_menu();
  printf("\n");

  char selection;
  printf("Please make a selection: ");

  // Loop until user enters X
  while ((selection=getchar()) != 'X') {
    getchar();

    printf("\n");
    switch (selection)
    {
    case 'O':
      display_output();
      printf("\n");
      break;

    case 'F':
      display_by_cwid();
      printf("\n");
      break;

    case 'P':
      display_at_position();
      printf("\n");
      break;

    case 'M':
      show_menu();
      printf("\n");
      break;

    case 'N':
      /* call function */
      break;

    case 'R':
      /* call function */
      break;

    default:
      printf("Unknown. Please try again.\n");
      printf("\n");
      break;
    }

    printf("Please enter a selection: ");
  }
  printf("\nThank you for using the Student Record System.\n");
  printf("You may use this software any time. Bye.\n");
}
