#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dotnoise.h"
#include "interactive.h"
#include "trie.h"

static trie_t *cmd_trie;
static trie_t *data_trie;

void trieWalk (trie_t *t, dotnoiseCompletions *dc, const char *buffer)
{
	int i;

	if (t->sentinel)
		dotnoiseAddCompletion(buffer, dc);

	for (i = 1; i < TRIE_NODE_SIZE; i++)
		if (t->chars[i]) {
			size_t length = strlen(buffer);
			char *next_buffer = malloc(length + 1 + 1);

			strncpy(next_buffer, buffer, length);
			next_buffer[length] = (char) i;
			next_buffer[length + 1] = '\0';

			trieWalk(t->chars[i], dc, next_buffer);
		}
}

void trieComplete (trie_t *t, dotnoiseCompletions *dc, const char *buffer)
{
	const char *original_buffer = buffer;
	int c;

	while ((c = *buffer++)) {
		if (t->chars[c] == NULL)
			return;

		t = t->chars[c];
	}

	trieWalk(t, dc, original_buffer);
}

void completion (const char *buffer, dotnoiseCompletions *dc)
{
	if (strchr(buffer, ' ')) {
		/* TODO */
	} else {
		trieComplete(cmd_trie, dc, buffer);
	}
}

void deboshInteractive (DIR* cmd_path, DIR* data_path)
{
	char *line;
	struct dirent *ent;

	cmd_trie = trieInit();
	while ((ent = readdir(cmd_path)))
		trieAdd(cmd_trie, ent->d_name);

	data_trie = trieInit();
	while ((ent = readdir(data_path)))
		trieAdd(data_trie, ent->d_name);

	dotnoiseSetCompletionCallback(completion);

	while ((line = dotnoise("> ")))
		free(line);

	trieFree(cmd_trie);
	trieFree(data_trie);
}
