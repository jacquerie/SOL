#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "complex_cmd.h"

simple_cmd* simpleCmdInit (void);
void simpleCmdParse(simple_cmd*, char*);
void simpleCmdFree (simple_cmd*);
void simpleCmdExecute (simple_cmd*);

complex_cmd* complexCmdInit (void)
{
	return calloc(1, sizeof(complex_cmd));
}

void complexCmdAppend (complex_cmd *ccmd, char *str)
{
	complex_cmd *tmp = ccmd;
	simple_cmd *scmd = simpleCmdInit();

	simpleCmdParse(scmd, str);

	while (tmp->scmd && tmp->next)
		tmp = tmp->next;

	if (tmp->scmd) {
		complex_cmd *new = complexCmdInit();
		new->scmd = scmd;
		tmp->next = new;
	} else {
		tmp->scmd = scmd;
	}
}

void complexCmdExecute (complex_cmd *ccmd)
{
	complex_cmd *tmp = ccmd;

	while (tmp->scmd && tmp->next) {
		simpleCmdExecute(tmp->scmd);
		tmp = tmp->next;
	}

	if (tmp->scmd)
		simpleCmdExecute(tmp->scmd);
}

void complexCmdFree (complex_cmd *ccmd)
{
	complex_cmd *tmp;

	while ((tmp = ccmd)) {
		ccmd = ccmd->next;

		if (tmp->scmd)
			simpleCmdFree(tmp->scmd);

		free(tmp);
	}
}

simple_cmd* simpleCmdInit (void)
{
	return calloc(1, sizeof(simple_cmd));
}

void simpleCmdParse (simple_cmd *scmd, char *str)
{
	char *cmd, *cpy, *data, *tmp;
	size_t cmd_length, data_length, length = strlen(str);

	cpy = malloc(length + 1);
	memcpy(cpy, str, length);
	cpy[length] = '\0';

	tmp = cpy;
	strsep(&cpy, " ");

	cmd_length = strlen(tmp);
	cmd = malloc(cmd_length + 1);
	memcpy(cmd, tmp, cmd_length);
	cmd[cmd_length] = '\0';

	data_length = strlen(cpy);
	data = malloc(data_length + 1);
	memcpy(data, cpy, data_length);
	data[data_length] = '\0';

	scmd->cmd = cmd;
	scmd->data = data;
}

void simpleCmdFree (simple_cmd *scmd)
{
	free(scmd->cmd);
	free(scmd->data);

	free(scmd);
}

void simpleCmdExecute (simple_cmd *scmd)
{
	printf("%s\t%s\n", scmd->cmd, scmd->data); /* TODO */
}
