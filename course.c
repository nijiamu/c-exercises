#include "course.h"
#include <stdio.h>

// Creates a new course with name "courseName" and grade "grade". If courseName
// is NULL or if the grade is negative or zero (<= 0), the function returns NULL.
Course *courseConstruct(const char *courseName, int grade) {
	return NULL;
}

// Frees all memory allocated to the Course in the constructor functions Construct and Copy.
void courseDestruct(Course * course) {
}

// Returns the name of the course (shallow copy).
const char *courseGetName(Course const * course) {
	return NULL;
}

// Returns the grade of the course
int courseGetGrade(Course const * course) {
	return 0;
}

// Creates a new course which is a deep copy of the course given in the parameter.
// The caller of the function must free the return value when it is not needed anymore.
Course *courseCopy(Course const * course) {
	return NULL;
}
