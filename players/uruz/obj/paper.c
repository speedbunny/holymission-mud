inherit "obj/thing";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg)return;
	set_name("piece of paper");
	set_alias("paper");
	set_alt_name("piece");
	set_can_get(1);
	set_weight(0);
	set_long("There is some writting on it, try reading it! \n");
	set_read("For a good time, visit Usegi Joe's. Just tell'em "+
		"Usegi sent you! \n");
	set_value(15);
	}
