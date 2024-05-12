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
// Date of last update:    2024-Apr-16
// Status: Put text in binary file and read it then print to terminal
// Compile:  gcc -c -Wall -m64 -no-pie -o read.o read.c -lm -std=c2x
// Link:  gcc -m64 -no-pie -o r.out read.o -lm -std=c2x

//======== Begin source code ==========

#include <stdio.h> //Provides access to printf and scanf
#include <string.h>
#include <stdlib.h>
#include "student.h"

const char* convertEnum( enum classLevel level) {
  switch (level) {
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

int main(int argc, char *argv[])
{
  FILE *file; // Pointer to input file
  const unsigned int max_length_file_name = 64;
  char file_name[max_length_file_name];

  printf("%s", "Welcome to Manage Academic Data\n");
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
  printf("The file name is %s\n", file_name);

  FILE *st_data = fopen(file_name, "r+b");
  struct Student person2;

  while (fread(&person2, sizeof(struct Student), 1, st_data) > 0)
  {
      printf("name = %s\n", person2.name);
      printf("cwid = %d\n", person2.cwId);
      printf("major = %s\n", person2.major);
      printf("class level = %s\n", convertEnum(person2.level));
      printf("zip = %d\n", person2.zipCode);
  }

  printf("The binary file was created.\n");
  printf("Bye\n");

}
