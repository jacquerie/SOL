#include <stdlib.h>
#include <string.h>

#include "bool.h"
#include "trie.h"

static trieLeafCallback *leafCallback = NULL;

void trieSetLeafCallback (trieLeafCallback *func)
{
	leafCallback = func;
}

void trieWalk (trie_t *t, const char *word);

inline trie_t* trieInit (void)
{
	return calloc(1, sizeof(trie_t));
}

void trieAdd (trie_t *t, const char *word)
{
	int c;

	while ((c = *word++)) {
		if (t->chars[c] == NULL)
			t->chars[c] = trieInit();

		t = t->chars[c];
	}

	t->sentinel = TRUE;
}

void trieComplete (trie_t *t, const char *prefix)
{
	const char *original_prefix = prefix;
	int c;

	while ((c = *prefix++)) {
		if (t->chars[c] == NULL)
			return;

		t = t->chars[c];
	}

	trieWalk(t, original_prefix);
}

int trieExists (trie_t *t, const char *word)
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
		if (t->chars[i])
			trieFree(t->chars[i]);

	free(t);
}

void trieWalk (trie_t *t, const char *word)
{
	char *current_word = strdup(word);
	int c;

	if (t->sentinel)
		leafCallback(current_word);

	for (c = 1; c < TRIE_NODE_SIZE; c++) {
		if (t->chars[c]) {
			current_word = realloc(current_word, strlen(current_word) + 1);
			strncat(current_word, (char*) &c, 1);

			trieWalk(t->chars[c], current_word);
		}
	}

	free(current_word);
}
