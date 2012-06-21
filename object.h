#ifndef AALTO_AS_C_OBJECT_H
#define AALTO_AS_C_OBJECT_H


/* Forward declaration and type definition
 * Struct is defined in the source file
 */
struct Object;
typedef struct Object Object;


/* Creates new object with given tag
 */

Object* objectConstruct(char const* tag);


/* Returns the tag of object.
 * Return value should point to the tag of object.
 * (ie. return value is not deep copied)
 */
char const* objectGetTag(Object const* obj);


/* Frees all memory associated to Object
 */
void objectDestruct(Object* obj);




#endif
