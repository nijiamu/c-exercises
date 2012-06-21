#include "joint.h"
#include "skeleton.h"
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* stringCopy2(const char* src) {
	assert(src);
	char* dest = calloc(strlen(src) + 1, sizeof(char));
	strcpy(dest, src);
	return dest;
}

// Creates new skeleton with given name and size
// Name should be deep copied
// Allocates space for given number of joints to jointArray
// Fills the array with NULL values
Skeleton createSkeleton(const char* name, size_t numJoints) {
	assert(name);
	Skeleton skeleton;
	skeleton.name = stringCopy2(name);
	skeleton.numJoints = numJoints;
	skeleton.jointArray = calloc(numJoints, sizeof(struct Joint*));
	return skeleton;
}

// Prints the name of the skeleton to the first row
// Prints all the members of jointArray in individual lines in format (without the < and >):
// <Joint name> <joint parent>
// For empty elements in array prints "No joint attached"
void printJoints(const Skeleton skeleton) {
	printf("%s\n", skeleton.name);
	for (size_t i = 0; i < skeleton.numJoints; i++) {
		struct Joint* joint = skeleton.jointArray[i];
		if (joint != NULL) {
			printf("%s %d\n", joint->name, (int) joint->parent);
		} else {
			printf("No joint attached\n");
		}
	}
}

// Adds the joint to the given index of skeleton
// Changes te parent of the joint to given value
void addJoint(const Skeleton skeleton, size_t index, struct Joint* joint, size_t parent) {
	assert(joint);
	skeleton.jointArray[index] = joint;
	joint->parent = parent;
}

// frees all memory allocated to the skeleton struct
void destroySkeleton(Skeleton skeleton) {
	free(skeleton.name);
	for (size_t i = 0; i < skeleton.numJoints; i++) {
		destroyJoint(skeleton.jointArray[i]);
	}
	free(skeleton.jointArray);
}
