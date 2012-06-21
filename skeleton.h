#ifndef AALTO_AS_C_SKELETON_H
#define AALTO_AS_C_SKELETON_H

#include "joint.h"
#include <stddef.h>


typedef struct {
  char* name;
  struct Joint** jointArray;
  size_t numJoints;
} Skeleton;


// Creates new skeleton with given name and size
// Name should be deep copied
// Allocates space for given number of joints to jointArray
// Fills the array with NULL values
Skeleton createSkeleton(const char* name, size_t numJoints);


// Prints the name of the skeleton to the first row
// Prints all the members of jointArray in individual lines in format (without the < and >):
// <Joint name> <joint parent>
// For empty elements in array prints "No joint attached"
void printJoints(const Skeleton skeleton);

// Adds the joint to the given index of skeleton
// Changes te parent of the joint to given value
void addJoint(const Skeleton skeleton, size_t index, struct Joint* joint, size_t parent);

// frees all memory allocated to the skeleton struct
void destroySkeleton(Skeleton skeleton);

#endif
