//Author: Sama Ahmed
//Contact: 26samahmed@csu.fullerton.edu
//Course ID: CPSC223C
//Due Date: 2024-Feb-21 at 11:59
//Program name: Read and Output File

//purpose

//Program was developed and tested on: Ubuntu

//Programming language: C language
//Date development begun: 2024-Feb-10
//Date of last update:    2024-Feb-20
//Status: Ask user to enter a string to search for until they enter control d
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
  //int char_count;
  //char character;
  //const unsigned int max_length_file_name = 64;
  const unsigned int max_search_length = 32;
  //char file_name[max_length_file_name];
  printf("%s", "Welcome to Great String Search brought to you by Sama Ahmed.\n");
  //printf("Please enter the name of your file: ");
  //scanf("%s", file_name);

  // open the file in read only mode
  //file_name[strlen(file_name) - 1] = '\0';
  file = fopen("sheep.txt", "r"); // open the file for reading

  //checking if the file exists, might want to do a do while loop, while the file == NULL, keep prompting the user to enter a filename
  // while (NULL == file) {
  //   printf("%s", "Sorry. File was not found. Try again.\n");
  //   printf("Please enter the name of your file: ");
  //   //scanf("%s", file_name);
  // }

  if (file != NULL) {
    printf("\nThe file has been opened with read permission.\n");
    fseek(file, 0L, SEEK_END);
    long fileLength = ftell(file); // gets the size of the file
    printf("The file contains %lu chars.\n", fileLength);
    rewind(file);

    char *arr;
    arr = malloc(fileLength);           // dynamically allocating memory with the same size as the file
    int c;
    size_t n = 0;
    while((c = fgetc(file)) != EOF) {   // as long as we haven't reached the end of file, keep looping
      arr[n++] = (char)c;   // store each character associated with each index
    }
    rewind(file);
    arr[n] = '\0';

    // Testing Purposes
    for (int i = 0; i < strlen(arr); i++) {   // looping through the array of characters
      printf("%c", arr[i]);                   // printing the character at that index
    }

    printf("\nThe file has been copied to a one-dimensional array.\n");


    // ask the user to enter a short string to search for
    while (!feof(stdin)) {
      char input[max_search_length];
      int i = 0;
      int location[fileLength]; // initializing an array of integers with the same size as the file
      int loc = 0;
      printf("\nEnter a string to find or enter cntl+d to terminate: ");
      scanf("%s", input);
      printf("%s was found at positions ", input);
      if (input == ' ' || strncmp(arr+i, input, strlen(input)) != 0) {
        printf("%s ", "none");
      }
      while (i < strlen(arr) - strlen(input)) {     // as long as we still have characters left
        if (strncmp(arr+i, input, strlen(input)) == 0) {
          location[loc] = i;  // store the position of the found character in the array of positions
          printf("%d ", i + 2);
          loc++;
        }
        i++;
      }
      printf("%s", "\n");
    }

    printf("%s", "\n");
    printf("Thank you for using this search program.\n");
    printf("Have a good day. We hope you enjoyed the string search.\n");
    printf("Come back any time for more searching. Bye\n");
    fclose(file);
  }
  return 0;
}//End of main
