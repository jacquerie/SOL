#include <string.h>
#include <sys/time.h>

#include "constants.h"
#include "stopwatch.h"

int ms_elapsed (stopwatch* last)
{
	struct timeval now;
	gettimeofday(&now, NULL);

	int result = (now.tv_sec * MS_IN_SEC + now.tv_usec / US_IN_MSEC) -
		(last->tv_sec * MS_IN_SEC + last->tv_usec / US_IN_MSEC);

	last->tv_sec = now.tv_sec;
	last->tv_usec = now.tv_usec;

	return result;
}
