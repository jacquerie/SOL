#include "complex_cmd.h"

int main (void)
{
	complex_cmd *ccmd = complexCmdInit();

	complexCmdAppend(ccmd, "foo");
	complexCmdAppend(ccmd, "bar");
	complexCmdAppend(ccmd, "baz");

	complexCmdFree(ccmd);

	return 0;
}
