#include "transcript.h"
#include "course.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  // courses is an array of 3 course pointers.
  Course *courses[3];

  courses[0] = courseConstruct("AS-0.1101 Basic Course in C Programming", 5);
  courses[1] = courseConstruct("AS-0.1102 C/C++ Programming", 6);
  courses[2] = NULL;

  Transcript *t = tsConstruct("Antti");


  tsSetCourseArray(t, courses);
  // Antti has now 2 completed courses

  // Let's do it again. After this, Antti should still have 2 completed courses
  // because the set function erased the old courses.
  tsSetCourseArray(t, courses);

  // Should print both courses
  tsPrint(t);

  // Copy the transcript
  Transcript *t2 = tsCopy(t);

  // ...and destroy it right away.
  tsDestruct(t2);
  
  // Free all memory

  tsDestruct(t);
  courseDestruct(courses[0]);
  courseDestruct(courses[1]);

  // We should have freed all allocated memory here.
  
}
