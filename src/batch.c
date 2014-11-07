#include <dirent.h>
#include <stdio.h>
#include <string.h>

#include "batch.h"
#include "complex_cmd.h"
#include "pipeline.h"
#include "trie.h"

#define BATCH_MAX_LINE 4096

static trie_t *exe_trie;
static trie_t *data_trie;

void deboshBatch (DIR* exe_path, DIR* data_path, FILE* batch_file)
{
	char line[BATCH_MAX_LINE];
	struct complex_cmd *ccmd;
	struct pipeline *pipeline;

	exe_trie = trieInit();
	trieLoad(exe_trie, exe_path);

	data_trie = trieInit();
	trieLoad(data_trie, data_path);

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

	pipeline = pipelineInit(ccmd, exe_path, data_path, exe_trie, data_trie);

	if (pipelineCheck(pipeline))
		pipelineExecute(pipeline);
	else
		printf("INVALID\n");

	pipelineFree(pipeline);

	fclose(batch_file);
}

