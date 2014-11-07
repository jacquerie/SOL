#ifndef __COMPLEX_CMD_H
#define __COMPLEX_CMD_H

#include <stddef.h>

typedef struct simple_cmd {
	char *exe;
	char **argv;
	size_t argc;
} simple_cmd;

typedef struct complex_cmd {
	struct simple_cmd *scmd;
	struct complex_cmd *next;
	int length;
} complex_cmd;

complex_cmd* complexCmdInit (void);
void complexCmdAppend (complex_cmd*, char*);
void complexCmdFree (complex_cmd*);

#endif
