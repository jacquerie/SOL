#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random_msg.h"

#define MIN_MSG_LEN 16
#define MAX_MSG_LEN 8192

int main (int argc, char *argv[])
{
	char* msg;
	int i, interval, length, test_cases;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s interval test_cases\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	interval = atoi(argv[1]);
	test_cases = atoi(argv[2]);

	srand(time(NULL));
	for (i = 0; i < test_cases; i++) {
		length = random_int(MIN_MSG_LEN, MAX_MSG_LEN);
		msg = random_msg(length);
		printf("%s\n", msg);
	}

	exit(EXIT_SUCCESS);
}
