#include <stdlib.h>

#include "complex_cmd.h"

struct simple_cmd* simpleCmdInit (void)
{
	return malloc(sizeof(struct simple_cmd));
}

void complexCmdAppend (complex_cmd ccmd, struct simple_cmd *smcd)
{
	complex_cmd tmp = ccmd;

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = smcd;
}

void complexCmdExecute (complex_cmd ccmd)
{
	/* TODO */
}

void complexCmdFree (complex_cmd ccmd)
{
	if (ccmd->next)
		complexCmdFree(ccmd->next);

	free(ccmd);
}
