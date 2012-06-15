#include <stdio.h>

#include "pointer_functions.h"

int main(void)
{
    /* Test the increment()-function */
    {
        printf("*** Testing the increment() function\n");
        int value = 2;
        for (size_t i = 0;i < 5;i++)
            increment(&value);
        printf("Value after calls to the increment()-function: %d (expected 7)\n", value);
    }
    
    /* Test the readInteger()-function */
    {
        printf("*** Testing the readInteger() function\n");
        int value;

        if (!readInteger(&value))
            printf("Reading of the value failed.\n");
        else
            printf("Value: %d (expected what you typed)\n", value);
    }
    
    /* Test the limit()-function */
    {
        printf("*** Testing the limit() function\n");
        
        double array[] = {-2.0, -1.0, 0.0, 1.0, 2.0};
        for (size_t i = 0;i < 5;i++)
            limit(array + i, -1.5, 1.5);
        printf("Array after calls to the limit()-function:");
        for (size_t i = 0;i < 5;i++)
            printf(" %.2f", array[i]);
        printf(" (expected -1.5 -1.0 0.0 1.0 1.5)\n");

    }
    
    /* Test the sum()-function */
    {
        printf("*** Testing the sum() function\n");
        double array[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
        double value = 0.0;
        for (size_t i = 0;i < 6;i++)
            sum(&value, &value, &array[i]);
        printf("Sum: %.2f (expected 21)\n", value);
    }
    
    /* Test the max()-function */
    {
        printf("*** Testing the max() function\n");
        int array[] = {4, -1, 2, -3, 5, 4};
        int *value = array;
        for (size_t i = 0;i < 6;i++)
            value = max(value, array+i);
        printf("Maximum value: %d (expected 5)\n", *value);
    }
    
    /* Test the sort2()-function */
    {
        printf("*** Testing the sort2() function\n");
        double array[] = {6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
        for (size_t i = 0;i < 6;i++)
            for (size_t j = 0;j < 5;j++)
                sort2(array + j, array + j + 1);
        printf("Array after calls to the sort2()-function:");
        for (size_t i = 0;i < 6;i++)
            printf(" %.2f", array[i]);
        printf(" (1.0 2.0 3.0 4.0 5.0 6.0)\n");
    }
}
