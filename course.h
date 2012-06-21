#ifndef TKK_AS_C_COURSE_H
#define TKK_AS_C_COURSE_H

// This is a header file for the Course ADT, which is used to represent rows in
// a transcript of completed courses. One instance of the ADT stores the name of the course,
// and the grade received.
//
//
// Implement the struct in your .c file. The field used to store
// the name of the course must have type char * - you are not allowed to use
// a static array.

typedef struct Course_s Course;

// Creates a new course with name "courseName" and grade "grade". If courseName
// is NULL or if the grade is negative or zero (<= 0), the function returns NULL.
Course *courseConstruct(const char *courseName, int grade);

// Frees all memory allocated to the Course in the constructor functions Construct and Copy.
void courseDestruct(Course *);

// Returns the name of the course (shallow copy).
const char *courseGetName(Course const *);

// Returns the grade of the course
int courseGetGrade(Course const *);

// Creates a new course which is a deep copy of the course given in the parameter.
// The caller of the function must free the return value when it is not needed anymore.
Course *courseCopy(Course const *);

#endif
