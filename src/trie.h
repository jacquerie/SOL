#ifndef __TRIE_H
#define __TRIE_H

#define TREE_SIZE 128
static const int TRIE_SIZE = TREE_SIZE;

typedef union trie_t {
	int sentinel;
	union trie_t *chars[TREE_SIZE];
} trie_t;

trie_t* trie_init (void);
void trie_add (trie_t*, char*);
int trie_exists (trie_t*, char*);
void trie_free (trie_t*);

#endif
