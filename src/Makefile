CFLAGS=-Wall -pedantic -g

all: debosh complex_cmd_test dotnoise_test pipeline_test trie_test

clean:
	rm -f debosh complex_cmd_test dotnoise_test pipeline_test trie_test

debosh: batch.c complex_cmd.c debosh.c dotnoise.c interactive.c trie.c

complex_cmd_test: complex_cmd_test.c complex_cmd.c

dotnoise_test: dotnoise_test.c dotnoise.c

pipeline_test: pipeline_test.c pipeline.c

trie_test: trie_test.c trie.c

.PHONY: all clean

