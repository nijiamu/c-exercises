#include "joint.h"
#include <stdlib.h>
#include <string.h>

// initializes the joint with given name and sets parent to -1
// name should be deep copied
void initializeJoint(struct Joint* joint, const char* name){
   memcpy(&joint->name, name, sizeof(joint->name)); 
   (* joint).parent = -1;
}

// Returns the name of the joint
const char* getJointName(const struct Joint* joint){
   char* jointName = (* joint).name;
   return jointName;
}

// Sets the parent of joint
// (This will be used in skeleton)
void setJointParent(struct Joint* joint, size_t parent){
   (* joint).parent = parent;
}

// Return the parent of the joint
size_t getJointParent(struct Joint* joint){
  return (* joint).parent;
}

// frees all memory allocated to the joint
void destroyJoint(struct Joint* joint){
   free(joint);
}
