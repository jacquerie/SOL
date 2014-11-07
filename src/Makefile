CFLAGS=-Wall -pedantic -g
EXE=debosh complex_cmd_test dotnoise_test pipeline_test trie_test

all: $(EXE)

clean:
	rm -f $(EXE)

test:
	./debosh /usr/bin . valid.debosh

debosh: batch.c complex_cmd.c debosh.c dotnoise.c interactive.c trie.c pipeline.c

complex_cmd_test: complex_cmd_test.c complex_cmd.c

dotnoise_test: dotnoise_test.c dotnoise.c

pipeline_test: pipeline_test.c pipeline.c complex_cmd.c trie.c

trie_test: trie_test.c trie.c

.PHONY: all clean test

