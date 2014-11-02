#ifndef __COMPLEX_CMD_H
#define __COMPLEX_CMD_H

typedef struct simple_cmd {
	char *cmd;
	char **data;
	struct simple_cmd *next;
} simple_cmd;

typedef struct simple_cmd *complex_cmd;

struct simple_cmd* simpleCmdInit (void);
void complexCmdAppend (complex_cmd, struct simple_cmd*);
void complexCmdExecute (complex_cmd);
void complexCmdFree (complex_cmd);

#endif
