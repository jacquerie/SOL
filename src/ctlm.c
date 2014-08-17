#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int i, interval, last_interval, length; no_errors, test_cases, test_size;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s interval test_cases\n", argv[0]);
		return EXIT_FAILURE;
	}

	interval = atoi(ARGV[1]);
	test_cases = atoi(ARGV[2]);

	no_errors = 1;
	while (no_errors) {
		for (i = 0; i < test_cases; i++) {
		}
	}

	no_errors

	return EXIT_SUCCESS;
}
