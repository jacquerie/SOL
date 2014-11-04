#ifndef __COMPLEX_CMD_H
#define __COMPLEX_CMD_H

typedef struct simple_cmd {
	char *cmd;
	char *data;
} simple_cmd;

typedef struct complex_cmd {
	struct simple_cmd *scmd;
	struct complex_cmd *next;
} complex_cmd;

complex_cmd* complexCmdInit (void);
void complexCmdAppend (complex_cmd*, simple_cmd*);
void complexCmdFree (complex_cmd*);

simple_cmd* simpleCmdInit (void);
void simpleCmdParse(simple_cmd*, char*);
void simpleCmdFree (simple_cmd*);

#endif
