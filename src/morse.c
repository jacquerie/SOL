#include <stdio.h>
#include <stdlib.h>

#include "morse.h"

int main (void)
{
	int i;

	for (i = 0; i < 128; i++) {
		if (CHAR_TO_MORSE[i]) {
			printf("%8s\t%c\t%s\n",
				char_to_morse(i),
				i,
				morse_to_char(char_to_morse(i)));
		}
	}

	return EXIT_SUCCESS;
}

