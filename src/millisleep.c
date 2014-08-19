#include <time.h>
#include <unistd.h>

#include "constants.h"
#include "millisleep.h"

int millisleep (int ms)
{
	struct timespec req;
	req.tv_sec = ms / MS_IN_SEC;
	req.tv_nsec = (ms % MS_IN_SEC) * NS_IN_MSEC;

	return nanosleep(&req, NULL);
}

