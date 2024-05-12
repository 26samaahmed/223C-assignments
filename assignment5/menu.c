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
// Status: Added Menu and worked on options M and X.
// Compile:  gcc -c -Wall -m64 -no-pie -o menu.o menu.c -lm -std=c2x
// Link:  gcc -m64 -no-pie -o menu.out menu.o -lm -std=c2x

//======== Begin source code ==========

#include <stdio.h> //Provides access to printf and scanf
#include <string.h>
#include <stdlib.h>
#include "student.h"

void show_menu() {
  printf("O = Output all student records\n");
  printf("F = Find and show a student by cwid number\n");
  printf("P = Position: show the struc data at a given position.\n");
  printf("M = Menu: show this menu\n");
  printf("N = New student will be added to the student roster file.\n");
  printf("R = Remove a student’s data\n");
  printf("X = Exit from this program.\n");
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
      /* call function */
      break;

    case 'F':
      /* call function */
      break;

    case 'P':
      /* call function */
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
      break;
    }

    printf("Please enter a selection: ");
  }
  printf("\nThank you for using the Student Record System.\n");
  printf("You may use this software any time. Bye.\n");
}
