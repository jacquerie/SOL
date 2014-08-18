#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "constants.h"
#include "morse_signal.h"

int main (int argc, char *argv[])
{
	char c; int first, interval; pid_t pid;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s pid interval\n", argv[0]);
		return EXIT_FAILURE;
	}

	pid = atoi(argv[1]);
	interval = atoi(argv[2]);

	first = TRUE;
	while (scanf("%c", &c) != EOF) {
		if (first) {
			send_letter(c, pid, interval);
			first = FALSE;
		} else if (c == ' ') {
			end_word(interval);
			first = TRUE;
		} else {
			end_letter(interval);
			send_letter(c, pid, interval);
		}
	}

	return EXIT_SUCCESS;
}

