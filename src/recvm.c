#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "morse_handler.h"
#include "stopwatch.h"

int main (int argc, char *argv[])
{
	int interval, ms; stopwatch last;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s interval\n", argv[0]);
		return EXIT_FAILURE;
	}

	interval = atoi(argv[1]);

	signal(SIGINT, quit);
	signal(SIGUSR1, receive_dot);
	signal(SIGUSR2, receive_dash);

	while (keep_going) {
		if (received_dot) {
			ms = ms_elapsed(&last);
			printf(".\t%d\n", ms);
			received_dot = FALSE;
		} else if (received_dash) {
			ms = ms_elapsed(&last);
			printf("-\t%d\n", ms);
			received_dash = FALSE;
		}
	}

	return EXIT_SUCCESS;
}
