#include "stack.h"
#include <stdio.h>

/* Returns a pointer to the newly created empty Stack
 */
Stack* createStack() {
	return NULL;
}


/* Frees all memory associated with the Stack
 */
void destructStack(Stack* s) {
}


/* Pushes given object to the top of the stack.
 * Returns an autoincrementing id for the element
 * that was put to stack. Id's start from zero.
 * (ie. The first object pushed to stack will get
 * id 0, second object 1, etc.)
 */
size_t push(Stack* s, Object const* si) {
	return 0;
}


/* Pops the topmost object from the stack
 * and stores it's pointer to given parameter.
 * Returns the id of item popped from the stack.
 * If stack is empty, the function assigns NULL
 * value to the given Object pointer and returns
 * -1. 
 *
 * (When assigned to size_t -1 represents an
 * invalid value. Actually, -1 casted to size_t
 * will yield the largest possible value that
 * can be represented with the data type. In
 * hexadecimal the representation would be some-
 * thing like 0xFFFFFFFF. With signed numbers
 * this would mean in the two's complement
 * representation -1, but when assigned to
 * unsigned integer type it is interpreted
 * biggest number.
 * Nice to know, but in this exercise it is
 * enough to just return -1 if the stack is empty.)
 */
size_t pop(Stack* s, Object const ** obj) {
	return 0;
}


/* Clears the stack by removing every object from it.
 * Does not reset the id counting mechanism.
 */
void clearStack(Stack* s) {
}


/* Returns the number of elements in the stack
 */
size_t getSize(Stack const* s) {
	return 0;
}


/* Clones the stack.
 * This means that new stack should have all the same
 * information as in original stack.
 */
Stack* cloneStack(Stack* s) {
	return NULL;
}


/* Merges the contents of FROM-stack on top of the
 * TO-stack. The operation should not destruct the
 * FROM stack. it should just move all it's elements
 * to the TO stack.
 * Example:
 * Before                   After
 *
 *                          2
 *                          8
 *                          5
 *  7                       7
 *  3      2                3
 *  6      8                6
 *  1      5                1
 *  TO    FROM              TO    FROM
 */
void mergeStacks(Stack* to, Stack* from) {
}
