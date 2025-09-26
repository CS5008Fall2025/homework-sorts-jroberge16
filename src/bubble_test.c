// Compile with: gcc -Wall merge_test.c -o merge_test.out
// Windows: change .out to .exe
// Run with: ./merge_test.out
// this is used during the team activity for module 05

#include <stdio.h>  // Include file for standard input/output
#include <stdlib.h> // so we can use atoi()
#include <time.h>   // so we can use time_t and clock_gettime()

#include "sorts.h"

// =============== Main Functions ===============
int main(int argc, char *argv[])
{

    // Some test data sets.
    int dataset1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int dataset2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int dataset3[] = {0, 3, 2, 1, 4, 7, 6, 5, 8, 9, 10};
    int dataset4[] = {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int dataset5[] = {100, 201, 52, 3223, 24, 55, 623, 75, 8523, -9, 150};
    int dataset6[] = {-1, 1, 2, -3, 4, 5, -6, 7, 8, -9, 10};
    int dataset7[] = {};
    int dataset8[] = {1};


    int print = 1;

    // Sort our integer array
    bubbleSortIntegers(dataset1, 11, print);
    bubbleSortIntegers(dataset2, 11, print);
    bubbleSortIntegers(dataset3, 11, print);
    bubbleSortIntegers(dataset4, 11, print);
    bubbleSortIntegers(dataset5, 11, print);
    bubbleSortIntegers(dataset6, 11, print);
    bubbleSortIntegers(dataset7, 0, print);
    bubbleSortIntegers(dataset8, 1, print);

    return 0;
}