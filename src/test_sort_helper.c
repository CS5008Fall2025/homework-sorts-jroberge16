


#include <stdio.h>  // Include file for standard input/output
#include <stdlib.h> // so we can use atoi()
#include "sort_helper.h"



int test_swap(void){
    printf("\tTesting Swap Function\n");
    printf("\t\tTesting Basic Swap: ");
    int a = 5;
    int b = 10;
    swap(&a, &b);

    if (a == 10 && b == 5){
        printf("Basic Swap Worked ✅\n");
        return 1;
    } else {
        printf("Basic Swap Failed ❌\n");
        return 0;
    }



}


int main(void){
    int passing = 0;
    // swap
    printf("🧪 Running Sort Helper Tests 🧪\n");
    passing += test_swap();
}