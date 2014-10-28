#include <stdio.h>

#include "trie.h"

void leaf (const char* word)
{
	printf("%s\n", word);
}

int main (void)
{
	trie_t *t = trieInit();

	trieSetLeafCallback(leaf);

	trieAdd(t, "foo");
	trieAdd(t, "bar");
	trieAdd(t, "foobar");

	trieComplete(t, "f");

	trieFree(t);

	return 0;
}
