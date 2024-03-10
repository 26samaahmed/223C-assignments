// Author: Sama Ahmed
// Contact: 26samahmed@csu.fullerton.edu
// Course ID: CPSC223C
// Due Date: 2024-Mar-13 at 11:59
// Program name: Tokenize

// Purpose

// Program was developed and tested on: Ubuntu

// Programming language: C language
// Date development begun: 2024-Mar-4
// Date of last update:    2024-Mar-9
// Status: Placed tokens in array
// Compile:  gcc -c -Wall -m64 -no-pie -o search.o array_search.c -lm -std=c2x
// Link:  gcc -m64 -no-pie -o search.out search.o -lm -std=c2x

//======== Begin source code ==========

#include <stdio.h> //Provides access to printf and scanf
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  FILE *file; // Pointer to input file
  const unsigned int max_length_file_name = 64;
  const unsigned int max_search_length = 32;
  char file_name[max_length_file_name];
  char input[max_search_length];

  printf("%s", "Welcome to Tokenizer brought to you by Sama Ahmed\n\n");
  printf("Please enter the name of your file: ");
  scanf("%s", file_name);

  file = fopen(file_name, "r"); // open the file for reading
  file_name[strlen(file_name) - 1] = '\0';

  // Prompt the user to enter a valid file name that's in the directory
  while (file == NULL) {
    printf("%s", "Sorry. File was not found. Try again.\n");
    printf("Please enter the name of your file: ");
    scanf("%s", file_name);
    file = fopen(file_name, "r"); // open the file for reading
  }


  // If the file exists then ask the user for their input to search
  if (file != NULL) {
    printf("\nThe file has been opened with read permission.\n");
    fseek(file, 0L, SEEK_END);
    long fileLength = ftell(file); // gets the size of the file
    printf("The file contains %lu chars.\n", fileLength + 1);
    rewind(file);

    char *arr;
    arr = malloc(fileLength); // dynamically allocating memory with the same size as the file
    int character;
    size_t counter = 0;
    while ((character = fgetc(file)) != EOF) {      // as long as we haven't reached the end of file, keep looping
      // TODO: replace any newlines found with a space
      if (character == '\n') {
        putchar(' ');
      }else {
        arr[counter++] = (char)character;             // store each character associated with each index
      }
    }

    rewind(file);

    printf("The file has been copied to a one-dimensional array and all newlines have been replace by the space character.\n");

    printf("%s", "\nThe first 32 bytes of the one-dimensional array are: \n");
    for (unsigned int i = 0; i < strlen(arr) / 3; i++) {
      printf("%c", arr[i]);
    }
    printf("%s", "\nEnter some characters for the separator string and press enter: ");
    scanf("%s", input);

    // Get the first token.
    // The first parameter is the array of chars to be tokenized and the second parameters contains the separators
    char *token_arr[fileLength];
    int token_count = 0;
    token_count++;
    token_arr[token_count] = strtok(arr, input);

    printf("%s", "The tokens were found and placed into a two-dimensional array of char.  Here are the contents of the token array in forward order.\n\n");

    printf("%s\n", token_arr[token_count]); // Print First Token

    char * token;
    while (NULL != (token = strtok(NULL, input))) {
      token_arr[token_count] = token;
      printf("%s\n", token_arr[token_count]);
      token_count++;
    }

    printf("\nNumber of tokens is %d", token_count);
    printf("%s", "\n");

    // TODO: write the array of tokens so same current file name but with the extension .tok which is a token file
    // TODO: Get the size of the token file

    fclose(file);
  }

    return 0;
} // End of main
