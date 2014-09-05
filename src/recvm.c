#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "morse_buffer.h"
#include "stopwatch.h"

#define WITH_NEWLINE "\n"
#define WITH_SPACE " "

int new_symbol (int, int);
int new_letter (int, int);
int new_word (int, int);

int main (int argc, char *argv[])
{
	char c;
	int first, interval, ms, sig;
	sigset_t set;
	stopwatch last;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s interval\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	interval = atoi(argv[1]);

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigprocmask(SIG_SETMASK, &set, NULL);

	first = TRUE;
	while (TRUE) {
		sigwait(&set, &sig);
		if (sig == SIGINT) {
			buffer_flush(WITH_NEWLINE);
			exit(EXIT_SUCCESS);
		}

		ms = ms_elapsed(&last);
		c = (sig == SIGUSR1) ? DOT : DASH;

		if (first || new_symbol(ms, interval)) {
			buffer_add(c);
		} else if (new_letter(ms, interval)) {
			buffer_flush(NULL);
			buffer_add(c);
		} else if (new_word(ms, interval)) {
			buffer_flush(WITH_SPACE);
			buffer_add(c);
		}

		first = FALSE;
	}
}

int new_symbol (int ms, int interval)
{
	return ms >= interval * BETWEEN_SYMBOLS && ms < interval * BETWEEN_LETTERS;
}

int new_letter (int ms, int interval)
{
	return ms >= interval * BETWEEN_LETTERS && ms < interval * BETWEEN_WORDS;
}

int new_word (int ms, int interval)
{
	return ms >= interval * BETWEEN_WORDS;
}
