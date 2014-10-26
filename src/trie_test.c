#include <stdio.h>

#include "trie.h"

int main (void)
{
	trie_t* t = trie_init();

	/* Add some words in the trie. */
	trie_add(t, "foo");
	trie_add(t, "bar");
	trie_add(t, "foobar");

	/* Cleanup. */
	trie_free(t);

	return 0;
}
