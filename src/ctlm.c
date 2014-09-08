#include <stdio.h>
#include <stdlib.h>

#include "experiment.h"

int main (int argc, char *argv[])
{
	int error, mid, min, max;
	int interval, test_cases;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s interval test_cases\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	interval = atoi(argv[1]);
	test_cases = atoi(argv[2]);

	min = 1;
	max = interval;

	error = TRUE;
	while (error) {
		error = experiment(max, test_cases);

		if (error) {
			min = max;
			max *= 2;
		}
	}

	while (min < max) {
		mid = min + (max - min)/2;
		error = experiment(mid, test_cases);

		if (error) {
			min = mid;
		} else {
			max = mid;
		}
	}

	exit(EXIT_SUCCESS);
}
