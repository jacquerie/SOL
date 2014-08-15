#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char* name;
	char* surname;
	char* id;
} student;

int main (int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s nome_file\n", argv[0]);
		return EXIT_FAILURE;
	}

	FILE *input = fopen(argv[1], "r");
	if (errno == ENOENT) {
		perror(argv[1]);
		return EXIT_FAILURE;
	}

	char name[256], surname[256], id[8];
	while (fscanf(input, "%[^:]:%[^:]:%[^:\n]\n", name, surname, id) != EOF) {
	}

	fclose(input);

	return EXIT_SUCCESS;
}
