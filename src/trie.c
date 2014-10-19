#include <stdlib.h>

#include "bool.h"
#include "trie.h"

inline trie_t* trie_init (void)
{
	return calloc(1, sizeof(trie_t));
}

void trie_add (trie_t* t, char* word)
{
	int c;

	while ((c = *word++)) {
		if (t->chars[c] == NULL)
			t->chars[c] = trie_init();
		t = t->chars[c];
	}

	t->sentinel = TRUE;
}

int trie_exists (trie_t* t, char* word)
{
	int c;

	while ((c = *word++)) {
		if (t->chars[c] == NULL)
			return 0;
		t = t->chars[c];
	}

	return t->sentinel;
}

void trie_free (trie_t *t)
{
	int i;

	for (i = 1; i < TRIE_SIZE; i++)
		if (t->chars[i] != NULL)
			trie_free(t->chars[i]);

	free(t);
}

