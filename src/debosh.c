#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "batch.h"
#include "interactive.h"

int main (int argc, char *argv[])
{
	DIR *cmd_path;
	DIR *data_path;
	FILE *batch_file;

	if (argc == 3 || argc == 4) {
		if ((cmd_path = opendir(argv[1])) == NULL) {
			perror(argv[1]);
			exit(EXIT_FAILURE);
		}

		if ((data_path = opendir(argv[2])) == NULL) {
			perror(argv[2]);
			exit(EXIT_FAILURE);
		}

		if (argc == 4) {
			if ((batch_file = fopen(argv[3], "r")) == NULL) {
				perror(argv[3]);
				exit(EXIT_FAILURE);
			}

			deboshBatch(cmd_path, data_path, batch_file);
		} else {
			deboshInteractive(cmd_path, data_path);
		}
	} else {
		fprintf(stderr, "Usage: %s commandPath dataPath [batchFile]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
