#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "str_functions.h"

/* GENERAL:
 * -----------
 * All the pointer parameters in each of the functions can be NULL, in other
 * words, you should use assert to check all the parameters at the start of
 * each function.
 *
 * Other than this, the functions described here DO NOT need to handle any
 * malformed input.
 */

/* DESCRIPTION:
 * ------------
 * The function rreturns a new string with the characters from the parameter
 * string in opposite casing.
 *
 * For example if the parameter string was: "tRA@nCE" the returned result would
 * be "Tra@Nce".
 *
 * Note that the parameter string is const, in other words, the function does
 * not modify the parameter string, but creates a new dynamically allocated
 * string, in which the result is stored.
 *
 * HINTS:
 * ------------
 * The ctype.h has some useful methods for identifying uppercase and lowercase
 * letters and changing between them.
 *
 * PARAMETERS:
 * ------------
 * const char* str: the source string.
 *
 * RETURNS:
 * ------------
 * A new dynamically allocated string, with the letters in opposite casing
 * than in the parameter string.
 */
char* swap_case(const char* str){
      assert(str);
	  int length = strlen(str);
      char* result = calloc(length + 1, sizeof(char));
	  for (int i = 0; i < length; i++){
	      if (str[i] >= 'a' && str[i] <= 'z'){
		      result[i] = str[i] - ('a' - 'A');
		  }
		  else if (str[i] >= 'A' && str[i] <= 'Z'){
		      result[i] = str[i] + ('a' - 'A');
		  }
		  else {
		      result[i] = str[i];
		  }
	  }
	  return result;
}


/* DESCRIPTION:
 * ------------
 * The function returns a new string with the characters from the parameter
 * string in reverse order.
 *
 * For example if the the parameter string was: "jakosuodin" the returned
 * result would be "nidousokaj".
 * 
 * Note that the parameter string is const, in other words, the function does
 * not modify the parameter string, but creates a new dynamically allocated
 * string, in which the result is stored.
 *
 * PARAMETERS:
 * ------------
 * const char* str: the source string.
 *
 * RETURNS:
 * ------------
 * A new dynamically allocated string, with the letters in reversed order than
 * in the parameter string.
 */
char* reverse(const char* str){
	assert(str);
	int length = strlen(str);
	char* result = calloc(length + 1, sizeof(char));
	for (int i = 0; i < length; i++){
		result[i] = str[length - i - 1];
	}
	return result;
}


/* DESCRIPTION:
 * ------------
 * The function returns a copy of the parameter string with the leading and
 * trailing whitespace characters removed.
 *
 * For example if the parameter string was "   exAmple      " the returned
 * result would be "exAmple".
 *
 * The characters considered as whitespace are (escaped): ' ', '\t', '\n', '\v',
 * '\f' and '\r'.
 *
 * Note that the parameter string is const, in other words, the function does
 * not modify the parameter string, but creates a new dynamically allocated
 * string, in which the result is stored.
 *
 * HINTS:
 * ------------
 * The ctype.h has some useful methods for identifying whitespace characters.
 * 
 * Remember to consider the special case in which all the letters in the string
 * are whitespace characters.
 *
 * PARAMETERS:
 * ------------
 * const char* str: the source string.
 *
 * RETURNS:
 * ------------
 * A new dynamically allocated string, with the leading and trailing whitespace
 * characters removed.
 */
char* strip(const char* str){
   assert(str);
	int length = strlen(str);
	int start = 0;
	int end = 0;
	for (int i = 0; i < length; i++){
		if (!isspace((int) str[i])){
			start = i;
			break;
		}
	}
	end = start;
	for (int i = start; i < length; i++){
		if (!isspace((int) str[i])){
			end = i;
		}
	}
	int result_length = end - start + 1;
	char* result = calloc(result_length + 1, sizeof(char));
	for (int i = 0; i < result_length; i++){
		result[i] = str[start + i];
	}
	return result;

}


/* DESCRIPTION:
 * ------------
 * The function returns a copy of the source string with all the occurrences
 * of the parameter pattern substituted for the sub parameter. The pattern is
 * is just a possible substring of the source string, not a regexp or anything
 * else complicated.
 *
 * The pattern is case sensitive and can be any valid, non-empty, C string.
 * The sub can also be any valid C string, even an empty string (""). 
 *
 * If the pattern isn't found in the source string, the function returns a copy 
 * of the source string.
 *
 * For example if the source string was: "abbaPTRabba", the pattern was 
 * "abba" and the sub parameter was "replaced", the result would be: 
 * "replacedPTRreplaced".
 *
 * Note that all the parameter strings are const, in other words, the function 
 * does not modify any of the parameter strings. The function creates a new 
 * dynamically allocated string, in which the result is stored.
 *
 * HINTS:
 * -----------
 * The string.h has some possibly useful methods for finding substrings and
 * concatenating strings.
 *
 * PARAMETERS:
 * ------------
 * const char* str: the source string.
 * const char* pattern: the pattern which to replace.
 * const char* sub: the replacement string for the found instances of pattern.
 *
 * RETURNS:
 * ------------
 * A dynamically allocated string, with all the occurrences of the parameter
 * pattern substituted with the sub parameter.
 */
char* substitute(const char* str, const char* pattern, const char* sub){
	return 0;
}
