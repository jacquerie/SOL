#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int interval;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s interval\n", argv[0]);
		return EXIT_FAILURE;
	}

	interval = atoi(argv[1]);

	return EXIT_SUCCESS;
}
