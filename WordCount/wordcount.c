#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Usage: WordCount [parameter] [input_file_name]\n");
		return 1;
	}

	FILE *file;
	fopen_s(&file, argv[2], "r");
	if (file == NULL) {
		printf("Error opening file\n");
		return 1;
	}

	char parameter[3];
	strcpy(parameter, argv[1]);

	int characterCount = 0;
	int wordCount = 0;
	int inWord = 0;
	char c;

	while ((c = fgetc(file)) != EOF) {
		characterCount++;
		if (c == ' ' || c == '\n' || c == '\t' || c == ',') {
			inWord = 0;
		}
		else {
			if (!inWord) {
				wordCount++;
				inWord = 1;
			}
		}
	}

	fclose(file);

	if (strcmp(parameter, "-c") == 0) {
		printf("×Ö·ûÊý£º%d\n", characterCount);
	}
	else if (strcmp(parameter, "-w") == 0) {
		printf("µ¥´ÊÊý£º%d\n", wordCount);
	}
	else {
		printf("Invalid parameter\n");
		return 1;
	}

	return 0;
}