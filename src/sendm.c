#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "constants.h"
#include "morse_signal.h"

int main (int argc, char *argv[])
{
	char c;
	int interval, new_word;
	pid_t pid;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s pid interval\n", argv[0]);
		return EXIT_FAILURE;
	}

	pid = atoi(argv[1]);
	interval = atoi(argv[2]);

	new_word = TRUE;
	while (scanf("%c", &c) != EOF) {
		if (new_word) {
			send_letter(c, pid, interval);
			new_word = FALSE;
		} else if (c == ' ') {
			end_word(interval);
			new_word = TRUE;
		} else {
			end_letter(interval);
			send_letter(c, pid, interval);
		}
	}
	end_message(pid);

	return EXIT_SUCCESS;
}

