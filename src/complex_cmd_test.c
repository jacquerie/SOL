#include "complex_cmd.h"

int main (void)
{
	complex_cmd *ccmd = complexCmdInit();

	complexCmdAppend(ccmd, "foo");
	complexCmdAppend(ccmd, "bar");
	complexCmdAppend(ccmd, "baz");

	complexCmdExecute(ccmd);

	complexCmdFree(ccmd);

	return 0;
}
