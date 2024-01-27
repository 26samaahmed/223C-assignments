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
{double side1, side2, side3, angle ,area;
 const double PI = 3.14159;

 printf("Welcome to Euclidean Triangles\n");
 printf("This software was built by and maintained by Systems Programmer Jennifer Lucas.\n");
 time_t current_linux_time;
 current_linux_time = time(NULL);

 //printf("Today is %02d %02d, %02d\n", utc->tm_mon , utc->tm_mday, utc->tm_year+1900);
 printf("This program will manage all of your triangles.\n");
 printf("Enter a float number for each quantity first side, second side, and angle in degrees between\nthose two sides. Separate each quantity by ws. After the third quantity press enter.\n");
 scanf("%lf %lf %lf", &side1, &side2, &angle);
 printf("You entered %5.5f and %5.5f for sides and %5.5f for the angle.\n", side1, side2, angle);

 area = 0.5 * side1 * side2 * sin(angle * PI / 180);
 printf("The area of this triangle is %1f square units.\n", area);


 side3 = sqrt(pow(side1, 2) + pow(side2, 2) - (2 * side1 * side2 * cos(angle * PI / 180)));
 printf("The length of the third side of the triangle is %lf linear units.\n", side3);

 printf("The elapsed time since the Great Epoch is %lu seconds.\n", current_linux_time);
 printf("Have a nice day.\n");
 printf("An integer 0 will be sent to the operating system as a signal of successful execution.  Bye.\n");

 return 0;
}//End of main

