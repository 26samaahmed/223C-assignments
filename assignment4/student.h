// Author: Sama Ahmed
// Contact: 26samahmed@csu.fullerton.edu
// Course ID: CPSC223C
// Due Date: 2024-Mar-14 at 2:00 AM
// Program name: Tokenize

// This program takes the user to input separators. I then print the tokens which is the text in between those
// user-specified separators.

// Program was developed and tested on: Ubuntu

// Programming language: C language
// Date development begun: 2024-Mar-4
// Date of last update:    2024-Mar-13
// Status: Finished Program
// Compile:  gcc -c -Wall -m64 -no-pie -o search.o array_search.c -lm -std=c2x
// Link:  gcc -m64 -no-pie -o search.out search.o -lm -std=c2x

//======== Begin source code ==========

/* every student has:
 1. a name (array of char)
 2. cwid (unsigned int)
 3. major (array of char)
 4. class standing (enum class)
 5. zip code (unsigned int)
 */

// Part 1: Read text file and write data to a binary file of structs

struct Student {
  char * name[100];
  unsigned int cwId;
  char * major[100];
  enum classStanding
  {
    freshman,
    sophomore,
    junior,
    senior
  };
  unsigned int zipCode;
};

#include <stdio.h> //Provides access to printf and scanf
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  FILE *file; // Pointer to input file
  FILE *new_file;
  const unsigned int max_length_file_name = 64;
  const unsigned int max_search_length = 32;
  char file_name[max_length_file_name];
  char input[max_search_length];

  printf("%s", "Welcome to Manage Academic Data\n\n");
  printf("Please enter the name of the text file: ");
  scanf("%s", file_name);

  file = fopen(file_name, "r"); // open the file for reading

  // Prompt the user to enter a valid file name that's in the directory
  while (file == NULL) {
    printf("%s", "Sorry. File was not found. Try again.\n");
    printf("Please enter the name of your file: ");
    scanf("%s", file_name);
    file = fopen(file_name, "r"); // open the file for reading
  }
  printf("You entered %s", file_name);
}
