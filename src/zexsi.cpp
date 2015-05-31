#include "zexsi.h"
#include "serv.h"
#include <iostream>
#include <stdlib.h>


using namespace std;
using namespace zex;

int main()
{
	pl("zexsi/");
	pl(ZEX_VER);
	p(" started");


	int zs = zex_serv();
	if (zs > 0)
	{
		p("zexsi: err");
		return 1;
	}
	else if (zs == ZEX_RET_FRMCLIENT)	/* client proccess end */
	{
		exit(0);
		return 0;
	}
	else
	{
		p("zexsi end");
	}

	return 0;
}
