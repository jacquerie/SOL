#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "complex_cmd.h"

simple_cmd* simpleCmdInit (void);
void simpleCmdParse (simple_cmd*, char*);
void simpleCmdFree (simple_cmd*);

complex_cmd* complexCmdInit (void)
{
	complex_cmd *result = calloc(1, sizeof(complex_cmd));

	result->length = 0;

	return result;
}

void complexCmdAppend (complex_cmd *ccmd, char *str)
{
	int i;
	simple_cmd *scmd;
	complex_cmd *tmp;

	if (strlen(str) == 0)
		return;

	scmd = simpleCmdInit();
	simpleCmdParse(scmd, str);

	tmp = ccmd;
	for (i = 0; i < ccmd->length - 1; i++)
		tmp = tmp->next;

	if (tmp->scmd) {
		complex_cmd *new = complexCmdInit();

		new->scmd = scmd;
		tmp->next = new;

		ccmd->length++;
	} else {
		tmp->scmd = scmd;

		ccmd->length = 1;
	}
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
	char *cpy, *token, *exe, *arg;
	size_t i = 0, argc = 0, length = strlen(str), exe_length, arg_length;

	cpy = malloc(length + 1);
	memcpy(cpy, str, length);
	cpy[length] = '\0';

	token = strtok(cpy, " ");
	while (token) {
		argc++;

		token = strtok(NULL, " ");
	}

	scmd->argc = argc;
	scmd->argv = malloc(argc * sizeof(char*));
	scmd->argv[scmd->argc] = NULL;

	memcpy(cpy, str, length);
	cpy[length] = '\0';

	token = strtok(cpy, " ");

	exe_length = arg_length = strlen(token);
	exe = malloc(exe_length + 1);
	memcpy(exe, token, exe_length);
	exe[exe_length] = '\0';
	scmd->exe = exe;

	arg = malloc(arg_length + 1);
	memcpy(arg, token, arg_length);
	arg[arg_length] = '\0';
	scmd->argv[i] = arg;
	i++;

	token = strtok(NULL, " ");
	while (token) {
		arg_length = strlen(token);
		arg = malloc(arg_length + 1);
		memcpy(arg, token, arg_length);
		arg[arg_length] = '\0';

		scmd->argv[i] = arg;
		i++;

		token = strtok(NULL, " ");
	}

	free(cpy);
}

void simpleCmdFree (simple_cmd *scmd)
{
	size_t i;

	free(scmd->exe);
	for (i = 0; i < scmd->argc; i++)
		free(scmd->argv[i]);
	free(scmd->argv);

	free(scmd);
}
