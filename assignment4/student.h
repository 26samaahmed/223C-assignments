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
// Compile:  gcc -c -Wall -m64 -no-pie -o student.o student.h -lm -std=c2x
// Link:  gcc -m64 -no-pie -o output.out student.o -lm -std=c2x

//======== Begin source code ==========

enum classLevel
{
  freshman,
  sophomore,
  junior,
  senior
};

struct Student {
  char name[100];
  unsigned int cwId;
  char major[100];
  enum classLevel level;
  unsigned int zipCode;
};
