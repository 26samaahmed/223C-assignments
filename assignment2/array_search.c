//Author: Sama Ahmed
//Contact: 26samahmed@csu.fullerton.edu
//Course ID: CPSC223C
//Due Date: 2024-Feb-21 at 11:59
//Program name: Read and Output File

//purpose

//Program was developed and tested on: Ubuntu

//Programming language: C language
//Date development begun: 2024-Feb-10
//Date of last update:    2024-Feb-12
//Status: Print the file size
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
  //long int file_size; // calculate the size of the file
  //int char_count = 0;
  //char character;
  const unsigned int max_length_file_name = 64;
  //char file_name[max_length_file_name];
  printf("%s", "Welcome to Great String Search brought to you by Sama Ahmed.\n");
  //printf("Please enter the name of your file: %s", file_name);

  // open the file in read only mode
  //file_name[strlen(file_name-1)] = '\0';
  file = fopen("sheep.txt", "r"); // open the file for reading
  fseek(file, 0L, SEEK_END);
  long fileLength = ftell(file); // gets the size of the file
  printf("The size of this file is %lu.\n", fileLength);
  char my_array[1000];
  fgets(my_array, 1000, file);
  printf("%s", my_array);
  fclose(file);

  // checking if the file exists
  //if (file == NULL) {
    //printf("%s", "Sorry. File was not found. Try again.\n");
    //printf("Please enter the name of your file: %s\n", file_name);
  //} else {
   // printf("found");
  //}

  //printf("The file has been opened with read permission.\n");

  // Compute the size of the file in bytes
  //file_size = ftell(file);
  // For testing purposes, print to see if the size of the file is printed.
  //printf("Size of this file is %ld", file_size);

  //for (character = getc(file); character != EOF; character = getc(file)) { // scanning through the file so that  can track char count
   // char_count += 1;
  //}
  //printf("The file contains %i chars", char_count);
  //printf("The file has been copied to a one-dimensional array.\n");


  // Declare an array of char that us the same size as the file size

  // copy all data from the file to the array of chars

  // ask the user to enter a short string to search for

  // Find all occurrences of that string

  // Ask the user for another string to search for unless they exit by control d

  // If user enters an empty string or if the string is not present, then print that the string was not found.


 return 0;
}//End of main
