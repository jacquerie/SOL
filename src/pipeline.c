#include <stdio.h>
#include <stdlib.h>

#include "bool.h"
#include "pipeline.h"

pipeline* pipelineInit (complex_cmd *ccmd, DIR *exe_path, DIR *data_path, trie_t *exe_trie, trie_t *data_trie)
{
	pipeline *result = calloc(1, sizeof(struct pipeline));

	result->ccmd = ccmd;
	result->exe_path = exe_path;
	result->data_path = data_path;
	result->exe_trie = exe_trie;
	result->data_trie = data_trie;

	return result;
}

int pipelineCheck (pipeline *pipeline)
{
	int result = TRUE;
	complex_cmd *tmp = pipeline->ccmd;

	while (tmp->next && tmp->scmd)
		if (!trieExists(pipeline->exe_trie, tmp->scmd->exe))
			return FALSE;

	if (tmp->scmd)
		if (!trieExists(pipeline->exe_trie, tmp->scmd->exe))
			return FALSE;

	return result;
}

void pipelineExecute (pipeline *pipeline)
{
	/* TODO */
}

void pipelineFree (pipeline *pipeline)
{
	complexCmdFree(pipeline->ccmd);
	trieFree(pipeline->exe_trie);
	trieFree(pipeline->data_trie);

	closedir(pipeline->exe_path);
	closedir(pipeline->data_path);

	free(pipeline);
}
