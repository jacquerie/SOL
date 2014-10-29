#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

void trieWalk (trie_t *t, const char *word)
{
	char *current_word = strdup(word);
	int i;

	if (t->sentinel)
		printf("%s\n", current_word);

	for (i = 1; i < TRIE_NODE_SIZE; i++)
		if (t->chars[i]) {
			current_word = realloc(current_word, strlen(current_word) + 1);
			strncat(current_word, (char*) &i, 1);

			trieWalk(t->chars[i], current_word);
		}

	free(current_word);
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
	trie_t *t = trieInit();

	trieAdd(t, "foo");
	trieAdd(t, "bar");
	trieAdd(t, "foobar");

	trieComplete(t, "f");

	trieFree(t);

	return 0;
}
