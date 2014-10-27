#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

void trie_walk (trie_t *t, char *word)
{
	char *current_word = strdup(word);
	int c;

	if (t->sentinel)
		printf("%s\n", word);

	for (c = 1; c < TRIE_SIZE; c++) {
		if (t->chars[c]) {
			current_word = realloc(current_word, strlen(current_word + 1));
			strncat(current_word, (char*) &c, 1);

			trie_walk(t->chars[c], current_word);
		}
	}

	free(current_word);
}

void trie_complete (trie_t *t, char *prefix)
{
	char *original_prefix = prefix;
	int c;

	while ((c = *prefix++)) {
		if (t->chars[c] == NULL)
			return;
		t = t->chars[c];
	}

	trie_walk(t, original_prefix);
}

int main (void)
{
	trie_t* t = trie_init();

	/* Add some words in the trie. */
	trie_add(t, "foo");
	trie_add(t, "bar");
	trie_add(t, "foobar");

	/* Print all words that start with the given prefix. */
	trie_complete(t, "foo");

	/* Cleanup. */
	trie_free(t);

	return 0;
}
