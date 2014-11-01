#ifndef __COMPLEX_CMD_H
#define __COMPLEX_CMD_H

typedef struct simple_cmd {
	char *cmd;
	char **data;
	struct simple_cmd *next;
} simple_cmd;

typedef simple_cmd *complex_cmd;

complex_cmd complexCmdInit (void);
void complexCmdAppend (simple_cmd);
void complexCmdExecute (complex_cmd);
void complexCmdFree (complex_cmd);

#endif
