// Author: Sama Ahmed
// Contact: 26samahmed@csu.fullerton.edu
// Course ID: CPSC223C
// Due Date: 2024-Apr-16 at 11:59 PM
// Program name: Binary

// This program takes the user to input separators. I then print the tokens which is the text in between those
// user-specified separators.

// Program was developed and tested on: Ubuntu

// Programming language: C language
// Date development begun: 2024-Apr-12
// Date of last update:    2024-Apr-12
// Status: Open text file for input and binary file for output
// Compile:  gcc -c -Wall -m64 -no-pie -o student.o student.h -lm -std=c2x
// Link:  gcc -m64 -no-pie -o output.out student.o -lm -std=c2x

//======== Begin source code ==========

#include <stdio.h> //Provides access to printf and scanf
#include <string.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[])
{

  FILE *file; // Pointer to input file
  FILE *binaryFile;
  const unsigned int max_length_file_name = 64;
  char file_name[max_length_file_name];

  printf("%s", "Welcome to Manage Academic Data\n\n");
  printf("Please enter the name of the text file: ");
  scanf("%s", file_name);

  file = fopen(file_name, "r"); // open the file for reading

  // Prompt the user to enter a valid file name that's in the directory
  while (file == NULL)
  {
    printf("%s", "Sorry. File was not found. Try again.\n");
    printf("Please enter the name of your file: ");
    scanf("%s", file_name);
    file = fopen(file_name, "r"); // open the file for reading
  }
  printf("You entered %s\n", file_name);
  char *dot;
  dot = strrchr(file_name, '.');
  strcpy(dot, ".bin");
  binaryFile = fopen(file_name, "w");

  printf("The output file name is %s\n", file_name);

  // open text file for input
  // read the text file
  // open binary file for output

  /*
    // open the text file for input and the binary file for output
    FILE *st_data = fopen(file_name, "r+b");
    struct Student person;
    enum
    while (0 < fread(&person, sizeof(struct Student), 1, st_data)) {
      printf("name = %s\n", person.name);
      printf("cwid = %d\n", person.cwId);
      printf("major = %s\n", person.major);
      switch (class.level) {
        case 1:
          printf("Class level = freshman");
          break;
        case 2:
          printf("Class level = sophomore");
          break;
        case 3:
          printf("Class level = junior");
          break;
        case 4:
          printf("Class level = senior");
          break;
      }
      // switch case for class standing
      printf("zip = %d\n", person.zipCode);
    }

  */
}
