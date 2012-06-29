#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("USAGE: %s [PATTERN] [FILE]...\n", argv[0]);
		return 0;
	}
	char* filename = argv[2];

	struct stat st;
	stat(filename, &st);
	size_t filesize = st.st_size;

	FILE *fp = fopen(filename, "r");
	
	char *line = calloc(filesize, sizeof(char));
	while (fgets(line, filesize, fp) != NULL) {
		printf("%s", line);
	}
	
	free(line);
	fclose(fp);
    return 0;
}
