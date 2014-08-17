#include <time.h>
#include <unistd.h>

#include "msleep.h"

int msleep (unsigned long ms)
{
	struct timespec req;
	req.tv_sec = ms / 1000;
	req.tv_nsec = (ms % 1000) * 1000000L;

	return nanosleep(&req, NULL);
}

