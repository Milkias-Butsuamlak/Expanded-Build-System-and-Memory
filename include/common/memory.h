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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>  // To include uint8_t and int32_t types
#include <stddef.h>  // To include size_t type
/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Move a block of memory with possible overlap.
 *
 * This function moves a block of memory from a source location to a destination
 * location, handling overlap. Copy occurs with no data corruption.
 *
 * @param src    Pointer to the source memory location.
 * @param dst    Pointer to the destination memory location.
 * @param length Number of bytes to move.
 *
 * @return       Pointer to the destination memory location (dst).
 */
uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Copy a block of memory.
 *
 * This function copies a block of memory from a source location to a destination
 * location. It does not handle overlap; overlap may corrupt data.
 *
 * @param src    Pointer to the source memory location.
 * @param dst    Pointer to the destination memory location.
 * @param length Number of bytes to copy.
 *
 *
 * @return       Pointer to the destination memory location (dst).
 */
uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Set all locations in a memory block to a specified value.
 *
 * This function sets all locations in a memory block to a specified value.
 *
 * @param src    Pointer to the memory location.
 * @param length Number of bytes to set.
 * @param value  Value to set at each memory location.
 *
 * @return       Pointer to the source memory location (src).
 */
uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value);

/**
 * @brief Zero out all locations in a memory block.
 *
 * This function sets all locations in a memory block to zero.
 *
 * @param src    Pointer to the memory location.
 * @param length Number of bytes to zero out.
 *
 * @return       Pointer to the source memory location (src).
 */
uint8_t *my_memzero(uint8_t *src, size_t length);

/**
 * @brief Reverse the order of bytes in a memory block.
 *
 * This function reverses the order of bytes in a memory block.
 *
 * @param src    Pointer to the memory location.
 * @param length Number of bytes in the memory block.
 *
 * @return       Pointer to the source memory location (src).
 */
uint8_t *my_reverse(uint8_t *src, size_t length);

/**
 * @brief Allocate a dynamic memory block for words.
 *
 * This function allocates a dynamic memory block for a specified number of words.
 *
 * @param length Number of words to allocate.
 *
 * @return       Pointer to the allocated memory if successful, NULL if not successful.
 */
int32_t *reserve_words(size_t length);

/**
 * @brief Free a dynamic memory allocation.
 *
 * This function releases dynamic memory allocated with malloc.
 *
 * @param src    Pointer to the dynamically allocated memory.
 */
void free_words(uint32_t *src);


#endif /* __MEMORY_H__ */
