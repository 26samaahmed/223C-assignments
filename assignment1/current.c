//Author: Sama Ahmed
//Contact: 26samahmed@csu.fullerton.edu

//Program name: Current Time

//Historically the C language only made provision for 32-bit random numbers.  Today we live in a computational world
//shere the norm is 64-bit processing for everything.  How do C programmers create 64-bit random integers for use in
//modern applications?  This program provides a solution to that question.  The author does not know if it is the 'best'
//solution, but at least this program provides some insight into creating numerically large integral random values.

//Programming language: C language
//Date development begun: 2024-Jan-23
//Date of last update:    2024-Jan-26
//Status: Calculting time and area

//Compile:  gcc -c -Wall -m64 -no-pie -o current.o current.c -std=c2x
//Link:  gcc -m64 -no-pie -o time.out current.o -std=c2x


//======== Begin source code ==========

#include "stdio.h"     //Provides access to printf and scanf
#include <math.h>      //Provides access to ldexp
#include <time.h>
#include <sys/time.h>

int main(int argc, char* argv[])
{double input_1 = 0.0;
 double input_2 = 0.0;
 double input_3 = 0.0;

 printf("Welcome to Euclidean Triangles\n");
 printf("This software was built by and maintained by Systems Programmer Jennifer Lucas.\n");
 time_t current_linux_time;
 current_linux_time = time(NULL);
 struct tm * broken = localtime(&current_linux_time);
 printf("Today is %04d-%02d-%02d\n", broken->tm_year+1900, broken->tm_mon+1, broken->tm_mday);
 printf("This program will manage all of your triangles.\n");
 printf("Enter a float number for each quantity first side, second side, and angle in degrees between\nthose two sides. Separate each quantity by ws. After the third quantity press enter.\n");
 scanf("%lf %lf %lf", &input_1, &input_2, &input_3);

 printf("You entered %5.5f and %5.5f for sides and %5.5f for the angle.\n", input_1, input_2, input_3);

 printf("The length of the third side of the triangle is linear units.\n");
 printf("The elapsed time since the Great Epoch is seconds.\n");
 printf("Have a nice day.");
 printf("An integer 0 will be sent to the operating system as a signal of successful execution.  Bye.");

 return 0;
}//End of main

