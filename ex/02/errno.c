#include <errno.h>
#include <stdio.h>

int main (void)
{
	errno = EINTR;
	perror("EINTR");

	errno = EPERM;
	perror("EPERM");

	errno = EBUSY;
	perror("EBUSY");

	return 0;
}
