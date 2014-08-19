#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "constants.h"
#include "morse_handler.h"
#include "stopwatch.h"

int main (int argc, char *argv[])
{
	char c; int interval, ms; stopwatch last;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s interval\n", argv[0]);
		return EXIT_FAILURE;
	}

	interval = atoi(argv[1]);

	signal(SIGINT, quit);
	signal(SIGUSR1, receive_dot);
	signal(SIGUSR2, receive_dash);

	while (keep_going) {
		if (received_dash || received_dot) {
			ms = ms_elapsed(&last);
			c = received_dash ? '-' : '.';

			write(1, &c, 1);

			received_dash = FALSE;
			received_dot = FALSE;
		}
	}

	return EXIT_SUCCESS;
}
