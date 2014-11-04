#include <stdio.h>
#include <stdlib.h>

#include "complex_cmd.h"

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
	scmd->cmd = str; /* TODO */
}

void simpleCmdFree (simple_cmd *scmd)
{
	free(scmd);
}

void simpleCmdExecute (simple_cmd *scmd)
{
	printf("%s\n", scmd->cmd); /* TODO */
}
