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
 * @file stats.c
 * @brief sorce file for doing some basic statstics on a given array used for the final assesment using compile time switch enabled with a VERBOSE flag in the make file
 *
 *
 *
 * @author Milkias Butsumalak
 * @date 1/9/2023
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

print_array(test,SIZE);
print_statistics(test,SIZE);
sort_array(test,SIZE);



 


}

/* Add other Implementation File Code Here */

 unsigned char print_statistics (unsigned char *data, unsigned int size) {
	 // Calculate and print the statistics
    unsigned char minimum = find_minimum(data, size);
    unsigned char maximum = find_maximum(data, size);
    unsigned char mean = find_mean(data, size);
    unsigned char median = find_median(data, size);

    printf("Statistics:\n");
    printf("Minimum: %d\n", minimum);
    printf("Maximum: %d\n", maximum);
    printf("Mean: %d\n", mean);
    printf("Median: %d\n", median);

    return median; // Return the median value
 }



 unsigned char print_array (unsigned char *data, unsigned int size) {
	//print the array elements based on a compile time switch
#ifdef VERBOSE
	PRINTF("Array elements:\n");
	for (unsigned int i = 0; i < size; i++) {
        	PRINTF("%d ", data[i]);
   	 }
    	PRINTF("\n");
#else
	//nothing will be printed
#endif
    	return 0; 
 }
	


 unsigned char find_median (unsigned char *data, unsigned int size){
 	 // Sort the array
    sort_array(data, size);

    // Calculate the median value
    unsigned int middle = size / 2;
    unsigned char median = data[middle];

    return median;
 }




 unsigned char find_mean (unsigned char *data, unsigned int size){
	//calculate the sum
	unsigned int sum = 0;
    	for (unsigned int i = 0; i < size; i++) {
        	sum += data[i];
   	 }
	
    	// Calculate the mean value
   	 unsigned char mean = sum / size;

    	return mean;
 }



 unsigned char find_maximum (unsigned char *data, unsigned int size){
	//finding largest from array
	unsigned char max=data[0];
	for(unsigned int i=1;i<size;i++) {
		if (data[i] > max) {
			max=data[i];
		 }
		
	}
	return max;

 }


 unsigned char find_minimum (unsigned char *data, unsigned int size){
	//finding smallest from array
	unsigned char min=data[0];
	for(unsigned int i=1;i<size;i++) {
		if (data[i] < min) {
			min=data[i];
		 }
		
	}
	return min;

 }


unsigned char sort_array (unsigned char *data, unsigned int size){
	//sort the array in ascending order
	// Placeholder implementation: Bubble sort
    for (unsigned int i = 0; i < size - 1; i++) {
        for (unsigned int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                // Swap the elements
                unsigned char temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
   printf("sorted Array elements:\n");
	for (unsigned int i = 0; i < size; i++) {
        	printf("%d ", data[i]);
   	 }
    	printf("\n");


    return 0; // Return 0 as a placeholder
 }

