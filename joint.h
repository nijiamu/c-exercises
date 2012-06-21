#ifndef AALTO_AS_C_JOINT_H
#define AALTO_AS_C_JOINT_H

// For size_t
#include <stddef.h>

struct Joint {
  char* name;
  size_t parent;
};


// initializes the joint with given name and sets parent to -1
// name should be deep copied
void initializeJoint(struct Joint* joint, const char* name);

// Returns the name of the joint
const char* getJointName(const struct Joint* joint);

// Sets the parent of joint
// (This will be used in skeleton)
void setJointParent(struct Joint* joint, size_t parent);

// Return the parent of the joint
size_t getJointParent(struct Joint* joint);

// frees all memory allocated to the joint
void destroyJoint(struct Joint* joint);

#endif
