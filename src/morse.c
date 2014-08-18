#include <ctype.h>
#include <math.h>
#include <string.h>

#include "morse.h"

int morse_to_index (const char* str)
{
	int i, length = strlen(str), result = 0;

	for (i = 0; i < length; i++)
		if (str[length - i - 1] == '-')
			result += pow(2, i);

	result += pow(2, i);

	return result;
}

const char* char_to_morse (char c)
{
	if (islower(c))
		c += ('A' - 'a');

	return CHAR_TO_MORSE[(int) c];
}

const char* morse_to_char (const char* str)
{
	return MORSE_TO_CHAR[morse_to_index(str)];
}

