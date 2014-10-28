#ifndef __TRIE_H
#define __TRIE_H

#define TRIE_NODE_SIZE 128

typedef union trie_t {
	int sentinel;
	union trie_t *chars[TRIE_NODE_SIZE];
} trie_t;

typedef void (trieLeafCallback)(const char*);
void trieSetLeafCallback (trieLeafCallback*);

trie_t* trieInit (void);
void trieAdd (trie_t*, const char*);
void trieComplete (trie_t*, const char*);
int trieExists (trie_t*, const char*);
void trieFree (trie_t*);

#endif
