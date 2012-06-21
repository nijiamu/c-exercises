#include "joint.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* stringCopy(const char* src) {
	assert(src);
	char* dest = calloc(strlen(src) + 1, sizeof(char));
	strcpy(dest, src);
	return dest;
}

// initializes the joint with given name and sets parent to -1
// name should be deep copied
void initializeJoint(struct Joint* joint, const char* name){
	assert(joint);
	joint->name = stringCopy(name);
	joint->parent = -1;
}

// Returns the name of the joint
const char* getJointName(const struct Joint* joint){
	assert(joint);
	return joint->name;
}

// Sets the parent of joint
// (This will be used in skeleton)
void setJointParent(struct Joint* joint, size_t parent){
	assert(joint);
	joint->parent = parent;
}

// Return the parent of the joint
size_t getJointParent(struct Joint* joint){
	assert(joint);
	return joint->parent;
}

// frees all memory allocated to the joint
void destroyJoint(struct Joint* joint){
	if (joint == NULL) {
		return;
	}
	free(joint->name);
	free(joint);
}
