#include "pointer_functions.h"

#include <stdio.h>

/* IMPORTANT:
 * ------------
 * All the pointer values in all of the functions below may be NULL.
 * In other words, for each pointer parameter there should be an assert
 * in your function implementation.
 *
 */

/* DESCRIPTION:
 * ------------
 * Reads an integer (scanf format %d) to the target pointer.
 *
 * PARAMETERS:
 * ------------
 * int* val: pointer to where the address will be stored.
 * 
 * RETURNS:
 * ------------
 * The return value of the scanf()-function 
 */
int readInteger(int *val) {
	return 0;
}


/* DESCRIPTION:
 * ------------
 * Increments the value by one.
 *
 * PARAMETERS:
 * ------------
 * int* value: pointer to the value to increment
 *
 * RETURNS:
 * ------------
 * Nothing.
 */
void increment(int *value) {
}

/* DESCRIPTION:
 * ------------
 * Limits the value to the range [low, high].
 *
 * In other words if the value is smaller than the lower bound the value will
 * be set to the lower bound. If the value is higher than the higher bound the
 * value will be set to the higher bound. Otherwise the value stays the same.
 *
 * PARAMETERS:
 * ------------
 * double* value: pointer to the value to limit
 * double low: lower bound
 * double high: higher bound
 *
 * RETURNS:
 * ------------
 * Nothing.
 */
void limit(double *value, double low, double high) {
}

/* DESCRIPTION:
 * ------------
 * Calculates the sum of the two values and stores it to the target pointer.
 *
 * PARAMETERS:
 * ------------
 * double* target: pointer to where the sum is stored.
 * const double* sum1: first operand
 * const double* sum2: second operand
 *
 * RETURNS:
 * ------------
 * Nothing.
 */
void sum(double *target, const double *sum1, const double *sum2) {
}

/* DESCRIPTION:
 * ------------
 * Returns the pointer which points to the larger value
 * if the values are equal, either of the two pointers is returned.
 *
 * PARAMETERS:
 * ------------
 * int* ptr1: pointer to the first value.
 * int* ptr2: pointer to the second value.
 *
 * RETURNS:
 * ------------
 * Pointer to the larger value.
 */
int* max(int *ptr1, int *ptr2) {
	return 0;
}

/* DESCRIPTION:
 * ------------
 * Sorts two values so that the first pointer contains the smaller value
 * and the second pointer contains the larger value.
 *
 * PARAMETERS:
 * ------------
 * double* ptr1: pointer to the first value
 * double* ptr2: pointer to the second value
 *
 * RETURNS:
 * ------------
 * Nothing.
 */
void sort2(double *ptr1, double *ptr2) {
}
