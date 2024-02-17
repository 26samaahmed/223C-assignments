//Author: Sama Ahmed
//Contact: 26samahmed@csu.fullerton.edu
//Course ID: CPSC223C
//Due Date: 2024-Feb-21 at 11:59
//Program name: Read and Output File

//purpose

//Program was developed and tested on: Ubuntu

//Programming language: C language
//Date development begun: 2024-Feb-10
//Date of last update:    2024-Feb-17
//Status: copy all characters from file to an array
//Compile:  gcc -c -Wall -m64 -no-pie -o search.o array_search.c -lm -std=c2x
//Link:  gcc -m64 -no-pie -o search.out search.o -lm -std=c2x


//======== Begin source code ==========

#include <stdio.h>     //Provides access to printf and scanf
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
  // Ask the user for input (name of txt file that we want to read)
  FILE *file; // Pointer to input file
 // long int file_size; // calculate the size of the file
  int char_count;
  //char character;
  const unsigned int max_length_file_name = 64;
  char file_name[max_length_file_name];
  printf("%s", "Welcome to Great String Search brought to you by Sama Ahmed.\n");
  //printf("Please enter the name of your file: ");
  //scanf("%s", file_name);

  // open the file in read only mode
  //file_name[strlen(file_name) - 1] = '\0';
  file = fopen("sheep.txt", "r"); // open the file for reading

  // checking if the file exists, might want to do a do while loop, while the file == NULL, keep prompting the user to enter a filename
  if (NULL == file) {
    printf("%s", "Sorry. File was not found. Try again.\n");
    printf("Please enter the name of your file: ");
    scanf("%s", file_name);
  } else {
    printf("Test Status: found\n");
  }

  printf("The file has been opened with read permission.\n");
  fseek(file, 0L, SEEK_END);
  long fileLength = ftell(file); // gets the size of the file
  fseek(file, 0L, SEEK_SET);
  printf("The file contains %lu chars.\n", fileLength);

  char *arr;
  arr = malloc(fileLength);
  int c;
  size_t n = 0;
  while((c = fgetc(file)) != EOF) {
    arr[n++] = (char)c;
  }
  arr[n] = '/0';

  for (int i = 0; i < strlen(arr); i++) {
    printf("%c ", arr[i]);
  }

    printf("The file has been copied to a one-dimensional array.\n");

  // ask the user to enter a short string to search for

  // Find all occurrences of that string

  // Ask the user for another string to search for unless they exit by control d

  // If user enters an empty string or if the string is not present, then print that the string was not found.

  printf("Have a good day. We hope you enjoyed the string search.\n");
  printf("Come back any time for more searching. Bye\n");
  return 0;
}//End of main
