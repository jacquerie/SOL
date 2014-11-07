#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "bool.h"
#include "pipeline.h"

pipeline* pipelineInit (complex_cmd *ccmd, char *exe_path, char *data_path, trie_t *exe_trie, trie_t *data_trie)
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
	int result = TRUE, i, j;

	complex_cmd *tmp = pipeline->ccmd;
	for (i = 0; i < pipeline->ccmd->length; i++) {
		if (tmp->scmd) {
			if (!trieExists(pipeline->exe_trie, tmp->scmd->exe))
				result = FALSE;

			for (j = 0; j < tmp->scmd->argc; j++)
				if (!trieExists(pipeline->data_trie, tmp->scmd->argv[j]))
					result = FALSE;
		}

		tmp = tmp->next;
	}

	return result;
}

void spawn_proc (int ifd, int ofd, simple_cmd* scmd)
{
	pid_t pid;

	if ((pid = fork()) == 0) {
		if (ifd != STDIN_FILENO) {
			dup2(ifd, STDIN_FILENO);
			close(ifd);
		}

		if (ofd != STDOUT_FILENO) {
			dup2(ofd, STDOUT_FILENO);
			close(ofd);
		}

		execvp(scmd->exe, scmd->argv);
	}
}

void pipelineExecute (pipeline *pipeline)
{
	int i, ifd, fd[2];

	ifd = STDIN_FILENO;

	complex_cmd *tmp = pipeline->ccmd;
	for (i = 0; i < pipeline->ccmd->length - 1; i++) {
		pipe(fd);
		spawn_proc(ifd, fd[1], tmp->scmd);
		close(fd[1]);
		ifd = fd[0];

		tmp = tmp->next;
	}

	if (ifd != STDIN_FILENO)
		dup2(ifd, STDIN_FILENO);

	size_t exe_path_length = strlen(pipeline->exe_path);
	size_t exe_length = strlen(tmp->scmd->exe);
	char *path = malloc(exe_path_length + exe_length + 1 + 1);
	memcpy(path, pipeline->exe_path, exe_path_length);
	path[exe_path_length] = '/';
	memcpy(path + exe_path_length + 1, tmp->scmd->exe, exe_length);
	path[exe_path_length + exe_length + 1] = '\0';

	execv(path, tmp->scmd->argv);
}

void pipelineFree (pipeline *pipeline)
{
	complexCmdFree(pipeline->ccmd);
	trieFree(pipeline->exe_trie);
	trieFree(pipeline->data_trie);

	free(pipeline);
}
