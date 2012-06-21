#ifndef TKK_AS_C_TRANSCRIPT_H
#define TKK_AS_C_TRANSCRIPT_H

#include "course.h"

typedef struct Transcript_s Transcript;


// This function creates a new transcript for student (the name is given in "studentName")
// A Transcript contains the name of the owner of the transcript (whose transcript it is),
// and an array of completed courses (represented by the Course ADT).
//
// Define the struct in the .c file, but note: the array of completed courses must be
// dynamic - you are not allowed to use arrays of static size.
//
// Initially the student has no completed courses.
Transcript *tsConstruct(const char *studentName);

// This function frees all memory allocated by the abstract data type.
void tsDestruct(Transcript *);

// This function returns the name of the student (whose transcript this is)
// The string is not copied, the function just returns the pointer.
const char *tsGetName(Transcript const*);
// This function returns the average grade of the completed courses.
double tsAverageGrade(Transcript const *t);

// This function assigns a copy of the course array "courses" to the transcript.
// The old course array in the transcript and memory reserved by it are freed before
// assigning the new array.
//
// "courses" is a pointer to the first element of an array of Course pointers.
// The last element of the array is NULL. Elements of the array have been allocated using the
// Course ADT.
void tsSetCourseArray(Transcript *t, Course **courses);

// This function prints to the standard output all completed courses separated by newline.
// The format is:
// <Course name>:<Grade>
// For example:
// AS-0.1101 Basic Course in C Programming:4
void tsPrint(Transcript const *);

// Creates a deep copy of the transcript.
Transcript *tsCopy(Transcript const *);


#endif
