#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s nome_file\n", argv[0]);
		return EXIT_FAILURE;
	}

	return 0;
}
