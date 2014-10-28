#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

void trieWalk (trie_t *t, char *word)
{
	char *current_word = strdup(word);
	int c;

	if (t->sentinel)
		printf("%s\n", word);

	for (c = 1; c < TRIE_NODE_SIZE; c++) {
		if (t->chars[c]) {
			current_word = realloc(current_word, strlen(current_word) + 1);
			strncat(current_word, (char*) &c, 1);

			trieWalk(t->chars[c], current_word);
		}
	}

	free(current_word);
}

void trieComplete (trie_t *t, char *prefix)
{
	char *original_prefix = prefix;
	int c;

	while ((c = *prefix++)) {
		if (t->chars[c] == NULL)
			return;
		t = t->chars[c];
	}

	trieWalk(t, original_prefix);
}

int main (void)
{
	trie_t *t = trieInit();

	/* Add some words in the trie. */
	trieAdd(t, "foo");
	trieAdd(t, "bar");
	trieAdd(t, "foobar");

	/* Print all words that start with the given prefix. */
	trieComplete(t, "f");

	/* Cleanup. */
	trieFree(t);

	return 0;
}
