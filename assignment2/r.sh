#!/bin/bash

#Author: Sama Ahmed
#Author email: 26samahmed@csu.fullerton.edu

#Program name: Time and Triangle Area


echo "Remove old un-needed files, if any."
rm *.o
rm *.out

echo "Compile the C main function search.c according to C standard 2017"
gcc -c -Wall -m64 -no-pie -o search.o array_search.c -lm -std=c2x

echo "Link object files"
gcc -m64 -no-pie -o search.out search.o -lm -std=c2x

echo "Run the program \"String search\""
./search.out

echo "The bash file has terminated."
