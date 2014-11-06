#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

void trieWalk (trie_t *t, const char *word)
{
	int i;

	if (t->sentinel)
		printf("%s\n", word);

	for (i = 1; i < TRIE_NODE_SIZE; i++)
		if (t->chars[i]) {
			char *current_word = malloc(strlen(word) + 1);
			strncat(current_word, word, strlen(word));
			strncat(current_word, (char*) &i, 1);

			trieWalk(t->chars[i], current_word);
		}
}

void trieComplete (trie_t *t, const char *prefix)
{
	const char* original_prefix = prefix;
	int c;

	while ((c = *prefix++)) {
		if (t->chars[c] == NULL)
			return;

		t = t->chars[c];
	}

	trieWalk (t, original_prefix);
}

int main (void)
{
	DIR *bin_path = opendir("/bin");

	trie_t *t = trieInit();
	trieLoad(t, bin_path);

	trieComplete(t, "l");

	trieFree(t);

	closedir(bin_path);

	return 0;
}
