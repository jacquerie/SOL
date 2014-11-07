#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "batch.h"
#include "interactive.h"

int main (int argc, char *argv[])
{
	FILE *batch_file;

	if (argc == 4) {
		if ((batch_file = fopen(argv[3], "r")) == NULL) {
			perror(argv[3]);
			exit(EXIT_FAILURE);
		}

		deboshBatch(argv[1], argv[2], batch_file);
	} else if (argc == 3) {
		deboshInteractive(argv[1], argv[2]);
	} else {
		fprintf(stderr, "Usage: %s exePath dataPath [batchFile]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
