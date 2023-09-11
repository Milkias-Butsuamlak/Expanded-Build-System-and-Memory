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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdint.h>
#include <stdlib.h> // Include the standard library for memory allocation functions

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}



uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length) {
    // Check for a valid input.
    if (src == NULL || dst == NULL || length == 0) {
        return NULL;
    }
   // Check for overlap.
    if (dst >= src && dst < src + length) {
        // Destination overlaps with source, so we need to copy backward to avoid data corruption.
        uint8_t *end_src = src + length - 1;
        uint8_t *end_dst = dst + length - 1;   
	while (length--) {
            *(end_dst--) = *(end_src--);
        }
        } 
    else {
        // No overlap, copy forward.
        while (length--) {
            *(dst++) = *(src++);
        }
    }

    return dst;
}


uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length) {
    // Check for a valid input.
    if (src == NULL || dst == NULL || length == 0) {
        return NULL;
    }

    // Perform the memory copy using pointer arithmetic.
    while (length--) {
        *(dst++) = *(src++);
    }

    return dst;
}



uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value) {
    // Check for a valid input.
    if (src == NULL || length == 0) {
        return NULL;
    }

    // Perform the memory set using pointer arithmetic.
    while (length--) {
        *(src++) = value;
    }

    return src; // Return a pointer to the source (src).
}



uint8_t *my_memzero(uint8_t *src, size_t length) {
    // Check for a valid input.
    if (src == NULL || length == 0) {
        return NULL;
    }

    // Perform the memory zeroing using pointer arithmetic.
    while (length--) {
        *(src++) = 0; // Set the value at the memory location pointed to by src to 0.
    }

    return src; // Return a pointer to the source (src).
}



uint8_t *my_reverse(uint8_t *src, size_t length) {
    // Check for a valid input.
    if (src == NULL || length == 0) {
        return NULL;
    }

    uint8_t *start = src; // Pointer to the start of the memory block
    uint8_t *end = src + length - 1; // Pointer to the end of the memory block

    while (start < end) {
        // Swap the values pointed to by start and end pointers
        uint8_t temp = *start;
        *start = *end;
        *end = temp;
	// Move the pointers towards each other
        start++;
        end--;
    }

    return src; // Return a pointer to the source (src).
}



int32_t *reserve_words(size_t length) {
    // Use malloc to allocate memory for the specified number of words
    int32_t *ptr = (int32_t *)malloc(length * sizeof(int32_t));

    // Check if memory allocation was successful
    if (ptr == NULL) {
        // Allocation failed, return NULL
        return NULL;
    }

    // Allocation was successful, return a pointer to the allocated memory
    return ptr;
}



void free_words(int32_t *src) {
    // Check if src is not a NULL pointer
    if (src != NULL) {
        // Free the allocated memory
        free(src);
    }
}
