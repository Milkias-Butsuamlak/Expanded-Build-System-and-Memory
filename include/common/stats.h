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
 * @file stats.h
 * @brief header file for function declaration
 *
 * <Add Extended Description Here>
 *
 * @author Milkias Butsumalak
 * @date 16/5/2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
unsigned char print_statistics (unsigned char *data, unsigned int size);

/**
 * @brief prints complete stat details
 *
 * A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param data  the array of numbers to be inputted
 * @param size   size of the array
 * 
 * @return minimum, maximum, mean, and median of the given array
 */


unsigned char print_array (unsigned char *data, unsigned int size);

/**
 * @brief  Given an array of data and a length, prints the array to the screen

 * @param data  the array of numbers to be inputted
 * @param size   size of the array
 * 
 * @return the full array
 */


unsigned char find_median (unsigned char *data, unsigned int size);


/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param data  the array of numbers to be inputted
 * @param size   size of the array
 * 
 * @return the median number
 */


unsigned char find_mean (unsigned char *data, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the mean or average value
 *
 * @param data  the array of numbers to be inputted
 * @param size   size of the array
 * 
 * @return the mean number
 */



unsigned char find_maximum (unsigned char *data, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the largest number of the given numbers in the array
 *
 * @param data  the array of numbers to be inputted
 * @param size   size of the array
 * 
 * @return the largest number
 */



unsigned char find_minimum (unsigned char *data, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the smallest number of the given numbers in the array
 *
 * @param data  the array of numbers to be inputted
 * @param size   size of the array
 * 
 * @return the smallest number
 */


unsigned char sort_array(unsigned char *data, unsigned int size);

/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest.  (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 * @param data  the array of numbers to be inputted
 * @param size   size of the array
 * 
 * @return the aranged array of numbers
 */


#endif /* __STATS_H__ */
