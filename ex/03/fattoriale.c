#include <stdio.h>

#define FATTORIALE(N) \
for (_result = 1, _i = 1; _i <= N; _i++) \
{ \
	_result *= _i; \
} \
printf("%d\n", _result);


int main (void)
{
	int _i, _result;

	FATTORIALE(5);
	FATTORIALE(4+1);
	/* FATTORIALE(FATTORIALE(2 + 1)); */

	return 0;
}

