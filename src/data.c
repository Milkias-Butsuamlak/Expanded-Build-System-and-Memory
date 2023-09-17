/**
 * @file data.c
 * @brief codes used for some basic data manupilation
 *
 * This file contains the data manupilation function codes used for the conversion from integer 
 **to ASCII and vice-versa for the final assesment.   
 * @author Milkias Butsuamlak
 * @date September 1 2023
 *
 */

/***********************************************************
 Function Definitions
***********************************************************/

#include <stdint.h>

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base) {
    // Check for valid base (2 to 16)
    if (base < 2 || base > 16) {
        return 0; // Unsupported base, return 0.
    }

    uint8_t *originalPtr = ptr; // Store the original pointer for calculating string length

    // Handle negative numbers
     if (data < 0) {
        *(ptr++) = '-';
        data = -data;
    }

    // Helper array to map digits for bases greater than 10
    char digits[] = "0123456789ABCDEF";

    // Initialize variables for conversion
    uint32_t remainder = 0;
    //uint8_t digit = 0;
    uint8_t length = 0;

    // Special case for zero
    if (data == 0) {
        *(ptr++) = '0';
        length++;
    }

    // Perform the conversion
    while (data > 0) {
        remainder = data % base;
        *(ptr++) = digits[remainder];
        data /= base;
        length++;
    }

    // Null-terminate the string
    *(ptr) = '\0';

    // Reverse the string to get the correct order
    uint8_t *start = originalPtr;
    uint8_t *end = ptr - 1;
    while (start < end) {
        uint8_t temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return length;
}



int32_t my_atoi(uint8_t *ptr, uint8_t numDigits, uint32_t base) {
    // Check for valid base (2 to 16)
    if (base < 2 || base > 16) {
        return 0; // Unsupported base, return 0.
    }

    int32_t result = 0;
    int32_t sign = 1;

    // Handle negative numbers
    if (*ptr == '-') {
        sign = -1;
        ptr++;
    }

    // Helper array to map digits for bases greater than 10
    char digits[] = "0123456789ABCDEF";

    // Perform the conversion
    while (numDigits--) {
        char currentChar = *ptr;
        int32_t value = -1; // Initialize as invalid
       // Convert the current character to its numeric value
        for (int32_t i = 0; i < base; i++) {
            if (currentChar == digits[i]) {
                value = i;
                break;
            }
        }

        if (value == -1) {
            break; // Invalid character encountered
        }

        result = result * base + value;
        ptr++;
    }

    return result * sign;
}

