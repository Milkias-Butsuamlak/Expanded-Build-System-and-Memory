/**
 * @file data.h
 * 
 *
 * This is the header file for the data.c (data manupilation function codes) for the final assesment. 
 * @author Milkias Butsuamlak
 * @date September 1 2023
 *
 */


#ifndef __DATA_H
#define __DATA_H

#include <stdint.h>

/**
 * @brief Convert an integer to an ASCII string representation.
 *
 * This function converts a signed 32-bit integer to an ASCII string with a specified base.
 *
 * @param data   The integer to convert.
 * @param ptr    Pointer to the destination buffer for the ASCII string.
 * @param base   The base for the conversion (2 to 16).
 *
 * @return       The length of the converted data (including a possible negative sign).
 */
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);

/**
 * @brief Convert an ASCII string to an integer.
 *
 * This function converts an ASCII string representation of an integer to a signed 32-bit integer.
 *
 * @param ptr    Pointer to the source ASCII string.
 * @param digits The number of digits in the character set.
 * @param base   The base for the conversion (2 to 16).
 *
 * @return       The converted 32-bit signed integer.
 */
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H */
