#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constants.h"
#include "experiment.h"
#include "random_msg.h"

#define MEAN_SYM_CHAR 6
#define MAX_MSG_MSEC  60000
#define MIN_MSG_LEN   16
#define MAX_MSG_LEN   8192

int experiment (int interval, int test_cases)
{
	int error, i;

	if (MEAN_SYM_CHAR * interval * MIN_MSG_LEN >= MAX_MSG_MSEC)
		return TRUE;

	error = FALSE;
	for (i = 0; i < test_cases; i++)
		if (single_experiment(interval))
			error = TRUE;

	return error;
}

int single_experiment (int interval)
{
	char *msg;
	int error, length;

	srand(time(NULL));
	length = random_int(MIN_MSG_LEN, MAX_MSG_LEN);
	if (MEAN_SYM_CHAR * interval * length >= MAX_MSG_MSEC)
		return single_experiment(interval);

	msg = random_msg(length);

	error = FALSE;

	return error;
}
