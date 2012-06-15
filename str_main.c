#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "str_functions.h"

char* allocate_str(const char* str) {
    char* ret = calloc(strlen(str) + 1, sizeof(char));
    return strcpy(ret, str);
}

void print_results(const char* str1, const char* str2) {
    printf("%s == %s -> ", str1, str2);
    if (!strcmp(str1, str2))
        printf("OK\n");
    else
        printf("FAILED\n");
}

int main(void) {
    char *str, *ret, *correct;

    printf("*** Testing your swap_case function\n");
        str = allocate_str("SWap  @  THIs!");
        ret = swap_case(str);
        correct = "swAP  @  thiS!";

        print_results(correct, ret);
        free(str);
        free(ret);

    printf("*** Testing your reverse function\n");
        str = allocate_str("desreveR eB dluohS gnirtS sihT");
        ret = reverse(str);
        correct = "This String Should Be Reversed";

        print_results(correct, ret);
        free(str);
        free(ret);

    printf("*** Testing your strip function\n");
        str = allocate_str(" \t\v\f\rWhite spaces are evil\n\n   ");
        ret = strip(str);
        correct = "White spaces are evil";

        print_results(correct, ret);
        free(str);
        free(ret);

    printf("*** Testing your substitute function\n");
        str = allocate_str("abbaptrabba");
        char* pattern = allocate_str("abba");
        char* sub = allocate_str("SubstituteD");
        ret = substitute(str, pattern, sub);
        correct = "SubstituteDptrSubstituteD";

        print_results(correct, ret);
        free(str);
        free(ret);
        free(pattern);
        free(sub);

    return 0;
}
