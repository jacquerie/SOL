CFLAGS=-Wall -pedantic -g

all: debosh dotnoise_test trie_test

clean:
	rm -f debosh dotnoise_test trie_test

debosh: batch.c debosh.c dotnoise.c interactive.c trie.c

complex_cmd_test: complex_cmd_test.c complex_cmd.c

dotnoise_test: dotnoise_test.c dotnoise.c

trie_test: trie_test.c trie.c

.PHONY: all clean

