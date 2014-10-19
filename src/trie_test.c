#include <stdio.h>
#include <stdlib.h>

#include "trie.h"

int main (void)
{
	trie_t* t = trie_init();

	/* Add some words in the trie. */
	trie_add(t, "foo");
	trie_add(t, "bar");
	trie_add(t, "foobar");

	/* Check for the existence of a word. */
	printf("'foo' is in the trie: %s\n",    trie_exists(t, "foo")    ? "yes" : "no");
	printf("'foob' is in the trie: %s\n",   trie_exists(t, "foob")   ? "yes" : "no");
	printf("'foobar' is in the trie: %s\n", trie_exists(t, "foobar") ? "yes" : "no");
	printf("'bar' is in the trie: %s\n",    trie_exists(t, "bar")    ? "yes" : "no");
	printf("'cars' is in the trie: %s\n\n", trie_exists(t, "cars")   ? "yes" : "no");

	/* Cleanup. */
	trie_free(t);

	exit(EXIT_SUCCESS);
}
