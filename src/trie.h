#ifndef __TRIE_H
#define __TRIE_H

#define TRIE_NODE_SIZE 128

typedef union trie_t {
	int sentinel;
	union trie_t *chars[TRIE_NODE_SIZE];
} trie_t;

trie_t* trieInit (void);
void trieAdd (trie_t*, char*);
int trieExists (trie_t*, char*);
void trieFree (trie_t*);

#endif
