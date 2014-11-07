#ifndef __TRIE_H
#define __TRIE_H

#include <dirent.h>

#define TRIE_NODE_SIZE 128

typedef union trie_t {
	int sentinel;
	union trie_t *chars[TRIE_NODE_SIZE];
} trie_t;

trie_t* trieInit (void);
int trieExists (trie_t*, const char*);
void trieLoad (trie_t*, DIR *path);
void trieFree (trie_t*);

#endif
