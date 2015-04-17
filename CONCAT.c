#include "CONCAT.h"

/**
 * This converts decimals to binary.
 * @param decimal, The decimal to convert.
 * @return binary, The binary form of the decimal.
 */
int decimal_to_binary(int decimal)
/* Function to convert decimal to binary.*/
{
    int b = 1;
    int binary = 0;
    while (decimal!=0)
    {
        int a = decimal % 2;
        decimal /= 2;
        binary += a * b;
        b *= 10;
    }
    return binary;
}
