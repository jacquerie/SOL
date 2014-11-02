#include "complex_cmd.h"

int main (void)
{
	complex_cmd foo;
	struct simple_cmd *bar, *baz;

	foo = simpleCmdInit();
	bar = simpleCmdInit();
	baz = simpleCmdInit();

	complexCmdAppend(foo, bar);
	complexCmdAppend(foo, baz);

	complexCmdFree(foo);

	return 0;
}
