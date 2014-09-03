#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "morse_buffer.h"
#include "stopwatch.h"

int main (int argc, char *argv[])
{
	char c;
	int first, interval, ms, sig;
	stopwatch last;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s interval\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	interval = atoi(argv[1]);

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigprocmask(SIG_SETMASK, &set, NULL);

	first = TRUE;
	while (TRUE) {
		sigwait(&set, &sig);
		if (sig == SIGINT) {
			buffer_flush("\n");
			exit(EXIT_SUCCESS);
		}

		ms = ms_elapsed(&last);
		c = (sig == SIGUSR1) ? '.' : '-';

		if (first || (ms >= interval * BETWEEN_SYMBOLS && ms < interval * BETWEEN_LETTERS)) {
			buffer_add(c);
		} else if (ms >= interval * BETWEEN_LETTERS && ms < interval * BETWEEN_WORDS) {
			buffer_flush(NULL);
			buffer_add(c);
		} else if (ms >= interval * BETWEEN_WORDS) {
			buffer_flush(" ");
			buffer_add(c);
		}

		first = FALSE;
	}
}
