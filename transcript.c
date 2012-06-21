#include "course.h"
#include "transcript.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Transcript_s {
	char* name;
	Course** courses;
};

char* stringCopy(const char* src);

// This function creates a new transcript for student (the name is given in "studentName")
// A Transcript contains the name of the owner of the transcript (whose transcript it is),
// and an array of completed courses (represented by the Course ADT).
//
// Define the struct in the .c file, but note: the array of completed courses must be
// dynamic - you are not allowed to use arrays of static size.
//
// Initially the student has no completed courses.
Transcript* tsConstruct(const char* studentName) {
	assert(studentName);
	Transcript* ts = calloc(1, sizeof(Transcript));
	ts->name = stringCopy(studentName);
	ts->courses = calloc(1, sizeof(Course*));
	return ts;
}

void freeCourses(Course** courses) {
	for (Course** c = courses; *c != NULL; c++) {
		courseDestruct(*c);
	}
	free(courses);
}

int coursesCount(Course** courses) {
	int count = 0;
	while (*courses++) {
		count++;
	}
	return count;
}

// This function frees all memory allocated by the abstract data type.
void tsDestruct(Transcript* ts) {
	assert(ts);
	free(ts->name);
	freeCourses(ts->courses);
	free(ts);
}

// This function returns the name of the student (whose transcript this is)
// The string is not copied, the function just returns the pointer.
const char *tsGetName(Transcript const* ts) {
	assert(ts);
	return ts->name;
}

// This function returns the average grade of the completed courses.
double tsAverageGrade(Transcript const* ts) {
	assert(ts);
	double sum = 0.0;
	int count = 0;
	for (int i = 0; ts->courses[i] != NULL; i++) {
		sum += courseGetGrade(ts->courses[i]);
		count++;
	}
	return sum / count;
}

// This function assigns a copy of the course array "courses" to the transcript.
// The old course array in the transcript and memory reserved by it are freed before
// assigning the new array.
//
// "courses" is a pointer to the first element of an array of Course pointers.
// The last element of the array is NULL. Elements of the array have been allocated using the
// Course ADT.
void tsSetCourseArray(Transcript* ts, Course** courses) {
	assert(ts);
	assert(courses);
	freeCourses(ts->courses);
	ts->courses = calloc(coursesCount(courses) + 1, sizeof(Course*));
	for (int i = 0; courses[i] != NULL; i++) {
		ts->courses[i] = courseCopy(courses[i]);
	}
}

// This function prints to the standard output all completed courses separated by newline.
// The format is:
// <Course name>:<Grade>
// For example:
// AS-0.1101 Basic Course in C Programming:4
void tsPrint(const Transcript* ts) {
	assert(ts);
	for (Course** courses = ts->courses; *courses != NULL; courses++) {
		Course* course = *courses;
		printf("%s:%d\n", courseGetName(course), courseGetGrade(course));
	}
}

// Creates a deep copy of the transcript.
Transcript* tsCopy(const Transcript* src) {
	assert(src);
	Transcript* dest = tsConstruct(src->name);
	tsSetCourseArray(dest, src->courses);
	return dest;
}
