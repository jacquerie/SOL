#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void deboshBatch (DIR* commandPath, DIR* dataPath, FILE* batchFile)
{
	struct dirent *ent;

	while ((ent = readdir(commandPath)) != NULL)
		printf("%s\n", ent->d_name);
}

void deboshInteractive (DIR* commandPath, DIR* dataPath)
{
	struct dirent *ent;

	while ((ent = readdir(dataPath)) != NULL)
		printf("%s\n", ent->d_name);
}

int main (int argc, char *argv[])
{
	if (argc == 3 || argc == 4) {
		DIR *commandPath = opendir(argv[1]);
		DIR *dataPath = opendir(argv[2]);

		if (argc == 4) {
			FILE *batchFile = fopen(argv[3], "r");

			/* Run debosh in batch mode. */
			deboshBatch(commandPath, dataPath, batchFile);
		} else {
			/* Run debosh in interactive mode. */
			deboshInteractive(commandPath, dataPath);
		}
	} else {
		fprintf(stderr, "Usage: %s commandPath dataPath [batchFile]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
