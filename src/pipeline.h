#ifndef __PIPELINE_H
#define __PIPELINE_H

#include <dirent.h>

#include "complex_cmd.h"
#include "trie.h"

typedef struct pipeline {
	complex_cmd *ccmd;
	DIR *exe_path;
	DIR *data_path;
	trie_t *exe_trie;
	trie_t *data_trie;
} pipeline;

pipeline* pipelineInit (complex_cmd*, DIR*, DIR*, trie_t*, trie_t*);
int pipelineCheck (pipeline*);
void pipelineExecute (pipeline*);
void pipelineFree (pipeline*);

#endif
