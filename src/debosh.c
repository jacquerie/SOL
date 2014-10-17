#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	if (argc == 4) {
	} else if (argc == 3) {
	} else {
		fprintf(stderr, "Usage: %s commandPath dataPath [batchPath]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
