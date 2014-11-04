#include "complex_cmd.h"

int main (void)
{
	complex_cmd *ccmd = complexCmdInit();

	simple_cmd *foo = simpleCmdInit();
	simple_cmd *bar = simpleCmdInit();
	simple_cmd *baz = simpleCmdInit();

	simpleCmdParse(foo, "foo");
	simpleCmdParse(bar, "bar");
	simpleCmdParse(baz, "baz");

	complexCmdAppend(ccmd, foo);
	complexCmdAppend(ccmd, bar);
	complexCmdAppend(ccmd, baz);

	complexCmdExecute(ccmd);

	complexCmdFree(ccmd);

	return 0;
}
