#include <signal.h>
#include <string.h>
#include <unistd.h>

#include "constants.h"
#include "morse.h"
#include "morse_signal.h"
#include "msleep.h"

void send_symbol (char c, pid_t pid)
{
	if (c == '.')
		kill(pid, SIGUSR1);
	else if (c == '-')
		kill(pid, SIGUSR2);
}

void send_letter (char c, pid_t pid, int interval)
{
	int i; const char *s = char_to_morse(c);

	if (s == NULL)
		return;

	for (i = 0; i < strlen(s) - 1; i++) {
		send_symbol(s[i], pid);
		msleep(interval * BETWEEN_SYMBOLS);
	}

	send_symbol(s[i], pid);
	msleep(interval * BETWEEN_LETTERS);
}

void end_word (int interval)
{
	msleep(interval * BETWEEN_WORDS);
}
