#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "morse.h"
#include "msleep.h"

void send_letter (char, pid_t, int);
void end_word (int);

int main (int argc, char *argv[])
{
	char c;
	int interval;
	pid_t recvm_pid;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s PID interval\n", argv[0]);
		return EXIT_FAILURE;
	}

	recvm_pid = atoi(argv[1]);
	interval = atoi(argv[2]);

	while (scanf("%c", &c) != EOF) {
		if (c == ' ' || c == '\n') {
			end_word(interval);
			continue;
		}

		send_letter(c, recvm_pid, interval);
	}

	return EXIT_SUCCESS;
}

void send_letter (char c, pid_t pid, int interval)
{
	const char *s = char_to_morse(c);
	int i, length = strlen(s);

	for (i = 0; i < length; i++) {
		if (s[i] == '.') {
			kill(pid, SIGUSR1);
		} else if (s[i] == '-') {
			kill(pid, SIGUSR2);
		}

		msleep(interval);
	}

	msleep(3 * interval);
}

void end_word (int interval)
{
	msleep(6 * interval);
}
