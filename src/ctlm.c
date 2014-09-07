#include <stdio.h>
#include <stdlib.h>

#include "random_msg.h"

#define MIN_MSG_LEN 16
#define MAX_MSG_LEN 8192

int main (int argc, char *argv[])
{
	char* msg;
	int i, interval, test_cases;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s interval test_cases\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	interval = atoi(argv[1]);
	test_cases = atoi(argv[2]);

	for (i = 0; i < test_cases; i++) {
		msg = random_msg(MIN_MSG_LEN, MAX_MSG_LEN);
		printf("%s\n", msg);
		free(msg);
	}

	exit(EXIT_SUCCESS);
}
