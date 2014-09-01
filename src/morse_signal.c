#include <signal.h>
#include <string.h>
#include <unistd.h>

#include "constants.h"
#include "morse.h"
#include "morse_signal.h"
#include "millisleep.h"

void send_symbol (char c, pid_t pid)
{
	if (c == '.')
		kill(pid, SIGUSR1);
	else if (c == '-')
		kill(pid, SIGUSR2);
}

void end_symbol (int interval)
{
	millisleep(interval * BETWEEN_SYMBOLS);
}

void send_letter (char c, pid_t pid, int interval)
{
	int i; const char *str = encode(c);

	if (str == NULL)
		return;

	for (i = 0; i < strlen(str) - 1; i++) {
		send_symbol(str[i], pid);
		end_symbol(interval);
	}

	send_symbol(str[i], pid);
}

void end_letter (int interval)
{
	millisleep(interval * BETWEEN_LETTERS);
}

void end_word (int interval)
{
	millisleep(interval * BETWEEN_WORDS);
}

void end_message (pid_t pid)
{
	kill(pid, SIGINT);
}
