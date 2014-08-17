#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#include "constants.h"

volatile sig_atomic_t keep_going = TRUE;

void quit (int sig)
{
	keep_going = FALSE;
}

void receive_dot (int sig)
{
	write(1, "SIGUSR1\n", 8);
}

void receive_dash (int sig)
{
	write(1, "SIGUSR2\n", 8);
}

int main (int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s interval\n", argv[0]);
		return EXIT_FAILURE;
	}

	printf("%d\n", getpid());

	signal(SIGINT, quit);
	signal(SIGUSR1, receive_dot);
	signal(SIGUSR2, receive_dash);

	while (keep_going)
		;

	return EXIT_SUCCESS;
}
