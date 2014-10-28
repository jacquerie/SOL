CFLAGS=-Wall -pedantic -g

all: dotnoise_test trie_test

clean:
	rm -f debosh dotnoise_test trie_test

debosh: debosh.c

dotnoise_test: dotnoise_test.c dotnoise.c

trie_test: trie_test.c trie.c

.PHONY: all clean

