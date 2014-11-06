#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#include "bool.h"
#include "trie.h"

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

void trieLoad (trie_t *t, DIR *path)
{
	struct dirent *ent;

	while ((ent = readdir(path)))
		if (!strncmp(ent->d_name, ".", 1) ||
		    !strncmp(ent->d_name, "..", 2)) {
			/* Skip . and .. */
		} else {
			trieAdd(t, ent->d_name);
		}
}

void trieFree (trie_t *t)
{
	int i;

	for (i = 1; i < TRIE_NODE_SIZE; i++)
		if (t->chars[i])
			trieFree(t->chars[i]);

	free(t);
}
