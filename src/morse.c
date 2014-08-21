#include <ctype.h>
#include <stdlib.h>

#include "morse.h"

int morse_to_index (const char* str)
{
	unsigned char sum = 0, bit;

	for (bit = 1; bit; bit <<= 1) {
		switch (*str++) {
		case 0:
			return sum | bit;
		default:
			return 0;
		case '-':
			sum |= bit;
			/* FALLTHROUGH */
		case '.':
			break;
		}
	}

	return 0;
}

const char* encode (char c)
{
	if (islower(c))
		c += ('A' - 'a');

	return CHAR_TO_MORSE[(int) c];
}

const char* decode (const char* str)
{
	return MORSE_TO_CHAR[morse_to_index(str)];
}

