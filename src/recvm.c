#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "constants.h"
#include "morse.h"
#include "stopwatch.h"

int main (int argc, char *argv[])
{
	char buffer[8] = {0}, c;
	int first_symbol, i = 0, interval, ms, sig;
	stopwatch last;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s interval\n", argv[0]);
		return EXIT_FAILURE;
	}

	interval = atoi(argv[1]);

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigprocmask(SIG_SETMASK, &set, NULL);

	first_symbol = TRUE;
	while (TRUE) {
		sigwait(&set, &sig);
		if (sig == SIGINT) {
			buffer[i] = '\0';
			write(1, decode(buffer), 1);
			write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}

		ms = ms_elapsed(&last);
		c = (sig == SIGUSR1) ? '.' : '-';

		if (first_symbol || (ms >= interval * BETWEEN_SYMBOLS && ms < interval * BETWEEN_LETTERS)) {
			buffer[i] = c;
			i++;
		} else if (ms >= interval * BETWEEN_LETTERS && ms < interval * BETWEEN_WORDS) {
			buffer[i] = '\0';
			write(1, decode(buffer), 1);
			i = 0;
			buffer[i] = c;
			i++;
		} else if (ms >= interval * BETWEEN_WORDS) {
			buffer[i] = '\0';
			write(1, decode(buffer), 1);
			write(1, " ", 1);
			i = 0;
			buffer[i] = c;
			i++;
		}

		first_symbol = FALSE;
	}
}
