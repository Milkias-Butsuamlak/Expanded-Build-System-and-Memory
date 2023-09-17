/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point to the final Assessment
 *
 * This file contains the main code for the final assesment. 
 * @author Milkias Butsuamlak
 * @date September 1 2023
 *
 */

#include "course1.h"
#include "stats.h"

#define SIZE (40)



/* a simple main() function that calls a function defined in course1.c using a compile time switch*/
int main() {
 #ifdef COURSE1
  course1();
 #endif
unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  

print_array(test,SIZE);
print_statistics(test,SIZE);
sort_array(test,SIZE);
  return 0;
}

