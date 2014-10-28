#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dotnoise.h"
#include "interactive.h"
#include "trie.h"

static trie_t *cmd_trie;
static trie_t *data_trie;

void completion (const char *buffer, dotnoiseCompletions *dc)
{
	if (strchr(buffer, ' ')) {
		/* TODO */
	} else {
		/* TODO */
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

