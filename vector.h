#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

/* DESCRIPTION:
 * ------------
 * The function constructs a vector that contains s values, all initialized
 * with value val. For example if the parameter s was 2 and val was 0, the
 * function would return a vector with two values, both initialized to 0.
 *
 * The function should have an assert in place to check that the size of
 * the vector is greater than 0.
 *
 * The memory of the vector must be dynamically allocated with a call to
 * malloc.
 *
 * PARAMETERS:
 * ------------
 * size_t s: size of the vector.
 * double val: initial value of the vector's elements.
 *
 * RETURNS:
 * ------------
 * A new dynamically allocated vector with s elements all initialized to val.
 */
double* vectorConstruct(size_t s, double val);


/* DESCRIPTION:
 * ------------
 * The function frees all resources associated with the parameter vector.
 *
 * Since free(NULL) is legal, the vec parameter should NOT be asserted as not
 * NULL.
 *
 * PARAMETERS:
 * ------------
 * double* vec: the vector to be destructed.
 *
 * RETURNS:
 * ------------
 * Nothing.
 */
void vectorDestruct(double* vec);


/* DESCRIPTION:
 * ------------
 * The function calculates dot product between the parameter vectors v1 and v2,
 * both containing s elements.
 *
 * A dot product is calculated simply by multiplying the correspoding entries in
 * the vectors and then summing those products:
 *
 * result = v1[0]*v2[0] + v1[1]*v2[1] + ...
 *
 * The function should check that neither of the parameter vectors is NULL by
 * using assert.
 *
 * PARAMETERS:
 * ------------
 * double const* v1: a vector containing s elements.
 * double const* v2: a vector containing s elements.
 * size_t s: number of elements in the parameter vectors.
 *
 * RETURNS:
 * ------------
 * The dot product of the parameter vectors.
 */
double dotProduct(double const* v1, double const* v2, size_t s);


/* DESCRIPTION:
 * ------------
 * The function calculates the sum of the parameter vectors v1 and v2, both
 * containing s elements. The memory for the result must be dynamically
 * allocated.
 *
 * The sum between the two vectors is simply calculated by adding the
 * corresponding values of the two vectors and using the sums as the values of
 * the new vector:
 *
 * result[i] = v1[i] + v2[i]
 *
 * The function should check that neither of the parameter vectors is NULL by
 * using assert.
 *
 * PARAMETERS:
 * ------------
 * double const* v1: a vector containing s elements.
 * double const* v2: a vector containing s elements.
 * size_t s: number of elements in the parameter vectors. 
 *
 * RETURNS:
 * ------------
 * A dynamically allocated vector, containing the sum of the two parameter 
 * vectors.
 */
double* vectorSum(double const* v1, double const* v2, size_t s);


/* DESCRIPTION:
 * ------------
 * The function appends all the elements of v2 (size s2) to the end of v1.
 *
 * The memory allocated for v1 must be reallocated to fit the new elements and
 * the new address and size are returned via the pointer parameters v1 and s1
 * as pass-by-pointer.
 *
 * Pass-by-pointer means, that the function doesn't use return to return the
 * values, but stores the results to the address pointed to by a parameter
 * pointer.
 *
 * All the parameter pointer values should be asserted as not NULL.
 *
 * PARAMETERS:
 * ------------
 * double** v1: a vector containing s1 elements.
 * size_t* s1: the number of elements in v1.
 * double const* v2: a vector containing s2 elements.
 * size_t s2: the number of elements in v2.
 *
 * RETURNS:
 * ------------
 * Nothing.
 */
void vectorAppend(double** v1, size_t* s1, double const* v2, size_t s2);

#endif
