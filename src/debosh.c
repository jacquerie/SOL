#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void deboshBatch (DIR* commandPath, DIR* dataPath, FILE* batchFile)
{
	printf("Running debosh in batch mode.\n");
}

void deboshInteractive (DIR* commandPath, DIR* dataPath)
{
	printf("Running debosh in interactive mode.\n");
}

int main (int argc, char *argv[])
{
	DIR *commandPath;
	DIR *dataPath;
	FILE *batchFile;

	if (argc == 3 || argc == 4) {
		commandPath = opendir(argv[1]);
		dataPath = opendir(argv[2]);

		if (commandPath == NULL || dataPath == NULL)
			goto fatal;

		if (argc == 4) {
			if ((batchFile = fopen(argv[3], "r")) == NULL)
				goto fatal;

			deboshBatch(commandPath, dataPath, batchFile);
		} else {
			deboshInteractive(commandPath, dataPath);
		}
	} else {
		fprintf(stderr, "Usage: %s commandPath dataPath [batchFile]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);

fatal:
	errno = ENOENT;
	exit(EXIT_FAILURE);
}
