#include <stdlib.h>

#include "bool.h"
#include "trie.h"

inline trie_t* trieInit (void)
{
	return calloc(1, sizeof(trie_t));
}

void trieAdd (trie_t *t, char *word)
{
	int c;

	while ((c = *word++)) {
		if (t->chars[c] == NULL)
			t->chars[c] = trieInit();
		t = t->chars[c];
	}

	t->sentinel = TRUE;
}

int trieExists (trie_t *t, char *word)
{
	int c;

	while ((c = *word++)) {
		if (t->chars[c] == NULL)
			return FALSE;
		t = t->chars[c];
	}

	return t->sentinel;
}

void trieFree (trie_t *t)
{
	int i;

	for (i = 1; i < TRIE_NODE_SIZE; i++)
		if (t->chars[i] != NULL)
			trieFree(t->chars[i]);

	free(t);
}

