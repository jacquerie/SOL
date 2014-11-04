#include "complex_cmd.h"

int main (void)
{
	complex_cmd *ccmd = complexCmdInit();
	simple_cmd *scmd = simpleCmdInit();

	simpleCmdParse(scmd, "foo bar baz");
	complexCmdAppend(ccmd, scmd);

	complexCmdFree(ccmd);

	return 0;
}
