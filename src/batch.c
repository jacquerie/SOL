#include <dirent.h>
#include <stdio.h>
#include <string.h>

#include "batch.h"
#include "complex_cmd.h"
#include "trie.h"

#define BATCH_MAX_LINE 4096

static trie_t *exe_trie;
static trie_t *data_trie;

void deboshBatch (DIR* exe_path, DIR* data_path, FILE* batch_file)
{
	char line[BATCH_MAX_LINE];
	struct complex_cmd *ccmd;
	struct dirent *ent;

	exe_trie = trieInit();
	while ((ent = readdir(exe_path)))
		trieAdd(exe_trie, ent->d_name);

	data_trie = trieInit();
	while ((ent = readdir(data_path)))
		trieAdd(data_trie, ent->d_name);

	ccmd = complexCmdInit();
	while ((fgets(line, BATCH_MAX_LINE, batch_file))) {
		if (strncmp(line, ".", 1)) {
			/* Trim the trailing '\n'. */
			size_t length = strlen(line);
			line[length - 1] = '\0';

			complexCmdAppend(ccmd, line);
		} else {
			break;
		}
	}

	complexCmdFree(ccmd);
	trieFree(exe_trie);
	trieFree(data_trie);

	closedir(exe_path);
	closedir(data_path);
	fclose(batch_file);
}

