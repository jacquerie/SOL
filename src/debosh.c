#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	if (argc == 4) {
		/* Run debosh in batch mode. */
	} else if (argc == 3) {
		/* Run debosh in interactive mode. */
	} else {
		fprintf(stderr, "Usage: %s commandPath dataPath [batchPath]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
