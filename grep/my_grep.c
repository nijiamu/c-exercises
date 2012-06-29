#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void grep_file(char* pattern, char* filename) {
	struct stat st;
	stat(filename, &st);
	size_t filesize = st.st_size;

	FILE *fp = fopen(filename, "r");
    
	char *line = calloc(filesize, sizeof(char));
	int linenumber = 0;
	while (fgets(line, filesize, fp) != NULL) {
		linenumber++;
		char *found = strstr(line, pattern);
		if (found != NULL){
			printf("%s:%d:%s", filename, linenumber, line);
		}
	}

	free(line);
	fclose(fp);
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("USAGE: %s [PATTERN] [FILE]...\n", argv[0]);
		return 0;
	}
	char* pattern = argv[1];
	
    for (int i = 2; i < argc; i++){
	    char* filename = argv[i];
	    grep_file(pattern, filename);
	}
	
    return 0;
}
