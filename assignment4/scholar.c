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

  int num_of_lines = 0;
  char *myData[50]; // the array to hold each line in the file.
  char temp[1024];  // temporary var to store each line
  // read line from file and store them in array. This will keep going until we reach NULL which means EOF

  while (fgets(temp, 1024, file))
  {
    // Check if the we have a new line to replace it with a null character
    int length = strlen(temp);
    if (temp[length - 1] == '\n')
    {
      temp[length - 1] = '\0';
    }

    // allocate memory for the current line
    myData[num_of_lines] = (char *)malloc((strlen(temp) + 1) * sizeof(char));

    // copy whatever is in the temp variable to store it in the myData array
    strcpy(myData[num_of_lines], temp);

    // Increment line counter
    num_of_lines++;
  }


  printf("\nYou entered %s\n", file_name);
  char *dot;
  dot = strrchr(file_name, '.');
  strcpy(dot, ".bin");
  printf("The file name is %s\n", file_name);
  binaryFile = fopen(file_name, "wb");

  printf("The output file name is %s\n", file_name);

  // Loop through each line and print the string
  struct Student person;
  for (unsigned int i = 0; i < num_of_lines; i++)
  {
    printf("%s\n", myData[i]);
    fwrite(&person, sizeof(struct Student), 1, binaryFile);
    // fprintf(binaryFile, "%s\n", myData[i]);
  }

  printf("\n");







//   FILE *st_data = fopen(file_name, "r+b");
//   struct Student person;
//   while (0 < fread(&person, sizeof(struct Student), 1, st_data))
//   {
//     printf("name = %s\n", person.name);
//     printf("cwid = %d\n", person.cwId);
//     printf("major = %s\n", person.major);
//     // switch (person.level) {
//     //   case 1:
//     //     printf("Class level = freshman");
//     //     break;
//     //   case 2:
//     //     printf("Class level = sophomore");
//     //     break;
//     //   case 3:
//     //     printf("Class level = junior");
//     //     break;
//     //   case 4:
//     //     printf("Class level = senior");
//     //     break;
//     // }
//     // switch case for class standing
//     printf("zip = %d\n", person.zipCode);
//   }
 }
