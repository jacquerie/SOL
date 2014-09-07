#include <stdlib.h>
#include <time.h>

#include "random_msg.h"

char ALLOWED_CHARS[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', '0', '1', '2', '3', '4', '5',
	'6', '7', '8', '9', '.', ',', ':', '?',
	'=', '-', '(', ')', '"', '\'', '/', '_',
	'@', '!'
};

int ALLOWED_LEN = 50;

int random_int (int from, int to)
{
	return rand() % (to - from) + from;
}

char random_char (void)
{
	return ALLOWED_CHARS[random_int(0, ALLOWED_LEN)];
}

char* random_msg (int from, int to)
{
	char* msg;
	int i, length;

	srand(time(NULL));
	length = random_int(from, to);
	msg = (char*) malloc(length * sizeof(char));

	for (i = 0; i < length; i++)
		msg[i] = random_char();

	return msg;
}
