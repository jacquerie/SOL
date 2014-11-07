#include <stdio.h>

#include "pipeline.h"

int main (void)
{
	complex_cmd *ccmd;
	DIR *exe_path = opendir("/usr/bin");
	DIR *data_path = opendir("/var");
	trie_t *exe_trie, *data_trie;
	pipeline *pipeline;

	ccmd = complexCmdInit();
	complexCmdAppend(ccmd, "last");
	complexCmdAppend(ccmd, "sort");

	exe_trie = trieInit();
	trieLoad(exe_trie, exe_path);

	data_trie = trieInit();
	trieLoad(data_trie, data_path);

	pipeline = pipelineInit(ccmd, exe_path, data_path, exe_trie, data_trie);

	if (pipelineCheck(pipeline))
		pipelineExecute(pipeline);

	pipelineFree(pipeline);

	return 0;
}
