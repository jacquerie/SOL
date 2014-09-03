#include <unistd.h>

#include "morse.h"
#include "morse_buffer.h"

void buffer_add (char c)
{
	buffer[_index] = c;
	_index++;
}

void buffer_flush (char *separator)
{
	buffer[_index] = '\0';
	_index = 0;

	write(1, decode(buffer), 1);
	if (separator)
		write(1, separator, 1);
}
