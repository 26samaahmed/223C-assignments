//Author: Sama Ahmed
//Contact: 26samahmed@csu.fullerton.edu

//Program name: Current Time

//Historically the C language only made provision for 32-bit random numbers.  Today we live in a computational world
//shere the norm is 64-bit processing for everything.  How do C programmers create 64-bit random integers for use in
//modern applications?  This program provides a solution to that question.  The author does not know if it is the 'best'
//solution, but at least this program provides some insight into creating numerically large integral random values.

//Programming language: C language
//Date development begun: 2024-Jan-23
//Date of last update:    2024-Feb-3
//Status: Finished the program

//Compile:  gcc -c -Wall -m64 -no-pie -o current.o current.c -std=c2x
//Link:  gcc -m64 -no-pie -o time.out current.o -std=c2x

//======== Begin source code ==========

#include <stdio.h>     //Provides access to printf and scanf
#include <math.h>      //Provides access to ldexp
#include <time.h>
#include <sys/time.h>

// Create a function that changes the month integer into the month name.
char * monthName(unsigned int number) {
  char * month;
  switch(number) {
    case 1:
        month = "January";
        break;
    case 2:
        month = "February";
        break;
    case 3:
        month = "March";
        break;
    case 4:
        month = "April";
        break;
    case 5:
        month = "May";
        break;
    case 6:
        month = "June";
        break;
    case 7:
        month = "July";
        break;
    case 8:
        month = "August";
        break;
    case 9:
        month = "September";
        break;
    case 10:
        month = "October";
        break;
    case 11:
        month = "November";
        break;
    case 12:
        month = "December";
        break;
   }
  return month;
}

int main(int argc, char* argv[])
{double side1, side2, side3, angle ,area;
 const double PI = 3.14159;

 printf("%s", "Welcome to Euclidean Triangles\n");
 printf("%s", "This software was built by and maintained by Systems Programmer Jennifer Lucas.\n");
 time_t current_linux_time;
 current_linux_time = time(NULL);
 struct tm * broken = localtime(&current_linux_time);

 // Convert from military time to standard time by subtracting 12 if the current hour is between 12pm and 12am
 if (broken->tm_hour > 12) {
   broken->tm_hour -= 12;
 }

 printf("Today is %s %d, %04d at %d:%02d", monthName(broken->tm_mon + 1),
                                              broken->tm_mday,
                                              broken->tm_year+1900,
                                              broken->tm_hour,
                                              broken->tm_min);

 // Print PM or AM depending on whether its during the day or after midnight
 if (broken->tm_hour - 12 < 12) {
   printf("%s", "pm\n");
 } else {
   printf("%s", "am\n");
 }

 printf("%s", "This program will manage all of your triangles.\n");
 printf("%s", "Enter a float number for each quantity first side, second side, and angle in degrees between those two sides. Separate each quantity by ws. After the third quantity press enter.\n");
 scanf("%lf %lf %lf", &side1, &side2, &angle);

 // Check if there are any invalid inputs (negative inputs)
 if (side1 < 0 ||side2 < 0 || angle < 0) {
  printf("You entered %5.5f, %5.5f, and %5.5f.\n", side1, side2, angle);
  printf("%s", "There are invalid data among these inputs. Please run this program again\n");
 } else {
  printf("You entered %5.5f and %5.5f for sides and %5.5f for the angle.\n", side1, side2, angle);

  // Caclulate the area of triangle using this formula
  area = 0.5 * side1 * side2 * sin(angle * PI / 180);
  printf("The area of this triangle is %5f square units.\n", area);

  // Calculate the the 3rd side of the triangle using this formula
  side3 = sqrt(pow(side1, 2) + pow(side2, 2) - (2 * side1 * side2 * cos(angle * PI / 180)));
  printf("The length of the third side of the triangle is %lf linear units.\n", side3);

  printf("The elapsed time since the Great Epoch is %lu seconds.\n", current_linux_time);
 }
 printf("%s", "Have a nice day.\n");
 printf("%s", "An integer 0 will be sent to the operating system as a signal of successful execution.  Bye.\n");

 return 0;
}//End of main
