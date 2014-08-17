#ifndef _MORSE_H
#define _MORSE_H

#include <ctype.h>
#include <math.h>
#include <string.h>

static const char* CHAR_TO_MORSE[128] = {
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, "-.-.--", ".-..-.", NULL, NULL, NULL, NULL, ".----.",
	"-.--.", "-.--.-", NULL, NULL, "--..--", "-....-", ".-.-.-", "-..-.",
	"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
	"---..", "----.", "---...", NULL, NULL, "-...-", NULL, "..--..",
	".--.-.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
	"....",	"..", ".---", "-.-", ".-..", "--", "-.", "---",
	".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
	"-..-", "-.--", "--..", NULL, NULL, NULL, NULL, "..--.-",
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};

static const char* MORSE_TO_CHAR[128] = {
	NULL, NULL, "E", "T", "I", "A", "N", "M",
	"S", "U", "R", "W", "D", "K", "G", "O",
	"H", "V", "F", NULL, "L", NULL, "P", "J",
	"B", "X", "C", "Y", "Z", "Q", NULL, NULL,
	"5", "4", NULL, "3", NULL, NULL, NULL, "2",
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, "1",
	"6", "=", "/", NULL, NULL, NULL, "(", NULL,
	"7", NULL, NULL, NULL, "8", NULL, "9", "0",
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, "?", "_", NULL, NULL,
	NULL, NULL, "\"", NULL, NULL, ".", NULL, NULL,
	NULL, NULL, "@", NULL, NULL, NULL, "'", NULL,
	NULL, "-", NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, "!", NULL, ")", NULL, NULL,
	NULL, NULL, NULL, ",", NULL, NULL, NULL, NULL,
	":", NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

int morse_to_index (const char* str)
{
	int i, length = strlen(str), result = 0;

	for (i = 0; i < length; i++) {
		if (str[length - i - 1] == '-') {
			result += pow(2, i);
		}
	}

	result += pow(2, i);

	return result;
}

const char* char_to_morse (char c)
{
	if (islower(c))
		c += ('A' - 'a');

	return CHAR_TO_MORSE[c];
}

const char* morse_to_char (const char* str)
{
	return MORSE_TO_CHAR[morse_to_index(str)];
}

#endif

