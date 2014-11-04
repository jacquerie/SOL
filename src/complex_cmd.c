#include <stdlib.h>

#include "complex_cmd.h"

complex_cmd* complexCmdInit (void)
{
	return calloc(1, sizeof(complex_cmd));
}

void complexCmdAppend (complex_cmd *ccmd, simple_cmd *scmd)
{
	complex_cmd *tmp = ccmd;

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

simple_cmd* simpleCmdInit (void)
{
	return calloc(1, sizeof(simple_cmd));
}

void simpleCmdParse (simple_cmd *scmd, char *str)
{
	scmd->cmd = str; /* TODO */
}
