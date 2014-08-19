#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int interval, test_cases;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s interval test_cases\n", argv[0]);
		return EXIT_FAILURE;
	}

	interval = atoi(argv[1]);
	test_cases = atoi(argv[2]);

	return EXIT_SUCCESS;
}
