#include <stdio.h>
#include <stdlib.h>

#include "dotnoise.h"

void completion (const char *buffer, dotnoiseCompletions *dc)
{
	if (buffer[0] == 'f') {
		dotnoiseAddCompletion("foo", dc);
		dotnoiseAddCompletion("foobar", dc);
	}
}

int main (void)
{
	char *line;

	dotnoiseSetCompletionCallback(completion);

	while ((line = dotnoise("> ")) != NULL) {
		printf("echo: '%s'\n", line);

		free(line);
	}

	return 0;
}
