#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dotnoise.h"
#include "interactive.h"
#include "trie.h"

static trie_t *cmd_trie;
static trie_t *data_trie;

void trieWalk (trie_t *t, dotnoiseCompletions *dc, const char *buffer, const char *prefix)
{
	int i;
	size_t buffer_length = strlen(buffer);

	if (t->sentinel) {
		size_t prefix_length = strlen(prefix);
		char *next_buffer = calloc(1, prefix_length + buffer_length + 1);

		memcpy(next_buffer, prefix, prefix_length);
		memcpy(next_buffer + prefix_length, buffer, buffer_length);
		next_buffer[prefix_length + buffer_length] = '\0';

		dotnoiseAddCompletion(next_buffer, dc);
	}

	for (i = 1; i < TRIE_NODE_SIZE; i++)
		if (t->chars[i]) {
			char *next_buffer = calloc(1, buffer_length + 1 + 1);

			memcpy(next_buffer, buffer, buffer_length);
			next_buffer[buffer_length] = (char) i;
			next_buffer[buffer_length + 1] = '\0';

			trieWalk(t->chars[i], dc, next_buffer, prefix);
		}
}

void trieComplete (trie_t *t, dotnoiseCompletions *dc, const char *buffer, const char *prefix)
{
	const char *original_buffer = buffer;
	int c;

	while ((c = *buffer++)) {
		if (t->chars[c] == NULL)
			return;

		t = t->chars[c];
	}

	trieWalk(t, dc, original_buffer, prefix);
}

void completion (const char *buffer, dotnoiseCompletions *dc)
{
	char *last_space = strrchr(buffer, ' ');

	if (last_space) {
		size_t prefix_length = last_space - buffer + 1;
		char *prefix = calloc(1, prefix_length + 1);

		memcpy(prefix, buffer, prefix_length);
		prefix[prefix_length] = '\0';

		trieComplete(data_trie, dc, last_space + 1, prefix);
	} else {
		trieComplete(cmd_trie, dc, buffer, "");
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
