#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#include "constants.h"

volatile sig_atomic_t keep_going = TRUE;

static int interval;
static struct timeval last_signal;

void quit (int sig)
{
	keep_going = FALSE;
}

void receive_dot (int sig)
{
	struct timeval this_signal;
	gettimeofday(&this_signal, NULL);

	int difference = (this_signal.tv_sec * 1000 + this_signal.tv_usec / 1000) -
		(last_signal.tv_sec * 1000 + last_signal.tv_usec / 1000);

	if (difference > 6 * interval) {
		write(1, "New word\n", 9);
	}

	last_signal.tv_sec = this_signal.tv_sec;
	last_signal.tv_usec = this_signal.tv_usec;
}

void receive_dash (int sig)
{
	struct timeval this_signal;
	gettimeofday(&this_signal, NULL);

	int difference = (this_signal.tv_sec * 1000 + this_signal.tv_usec / 1000) -
		(last_signal.tv_sec * 1000 + last_signal.tv_usec / 1000);

	if (difference > 6 * interval) {
		write(1, "New word\n", 9);
	}

	last_signal.tv_sec = this_signal.tv_sec;
	last_signal.tv_usec = this_signal.tv_usec;
}

int main (int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s interval\n", argv[0]);
		return EXIT_FAILURE;
	}

	interval = atoi(argv[1]);

	printf("%d\n", getpid());

	signal(SIGINT, quit);
	signal(SIGUSR1, receive_dot);
	signal(SIGUSR2, receive_dash);

	while (keep_going)
		;

	return EXIT_SUCCESS;
}
