#include "course.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// This is a header file for the Course ADT, which is used to represent rows in
// a transcript of completed courses. One instance of the ADT stores the name of the course,
// and the grade received.
//
//
// Implement the struct in your .c file. The field used to store
// the name of the course must have type char * - you are not allowed to use
// a static array.

struct Course_s {
	char* name;
	int grade;
};

char* stringCopy(const char* src) {
	assert(src);
	char* dest = calloc(strlen(src) + 1, sizeof(char));
	strcpy(dest, src);
	return dest;
}

// Creates a new course with name "courseName" and grade "grade". If courseName
// is NULL or if the grade is negative or zero (<= 0), the function returns NULL.
Course* courseConstruct(const char* courseName, int grade) {
	if (courseName == NULL || grade <= 0) {
		return NULL;
	}
	Course* c = calloc(1, sizeof(Course));
	c->name = stringCopy(courseName);
	c->grade = grade;
	return c;
}

// Frees all memory allocated to the Course in the constructor functions Construct and Copy.
void courseDestruct(Course* course) {
	assert(course);
	free(course->name);
	free(course);
}

// Returns the name of the course (shallow copy).
const char *courseGetName(const Course* course) {
	assert(course);
	return course->name;
}

// Returns the grade of the course
int courseGetGrade(const Course* course) {
	assert(course);
	return course->grade;
}

// Creates a new course which is a deep copy of the course given in the parameter.
// The caller of the function must free the return value when it is not needed anymore.
Course* courseCopy(const Course* course) {
	assert(course);
	Course* dest = calloc(1, sizeof(Course));
	dest->name = stringCopy(course->name);
	dest->grade = course->grade;
	return dest;
}
