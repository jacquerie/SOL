#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

#include "pipeline.h"

int main (void)
{
	complex_cmd *ccmd;
	char *exe_path = "/usr/bin";
	char *data_path = "/var/log";
	DIR *exe_dir, *data_dir;
	trie_t *exe_trie, *data_trie;
	pipeline *pipeline;

	ccmd = complexCmdInit();
	complexCmdAppend(ccmd, "last");
	complexCmdAppend(ccmd, "sort");

	if ((exe_dir = opendir(exe_path)) == NULL) {
		perror(exe_path);
		exit(EXIT_FAILURE);
	}

	exe_trie = trieInit();
	trieLoad(exe_trie, exe_dir);

	if ((data_dir = opendir(data_path)) == NULL) {
		perror(data_path);
		exit(EXIT_FAILURE);
	}

	data_trie = trieInit();
	trieLoad(data_trie, data_dir);

	pipeline = pipelineInit(ccmd, exe_path, data_path, exe_trie, data_trie);

	if (pipelineCheck(pipeline))
		pipelineExecute(pipeline);

	pipelineFree(pipeline);

	closedir(exe_dir);
	closedir(data_dir);

	return 0;
}
