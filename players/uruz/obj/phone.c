inherit "obj/thing";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg)return;
	set_name("cell phone");
	set_alias("phone");
	set_can_get(1);
	set_weight(0);
	set_long("It's a brand new cell phone! Now you can call up "+
	"trout anytime!\n");
	set_value(0); /*now no one will want to steal it!*/
	}
