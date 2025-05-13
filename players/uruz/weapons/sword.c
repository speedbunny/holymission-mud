inherit "obj/weapon";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("long sword");
	set_alias("sword");
	set_long("A ordinary looking long sword, with a long silk sash tied "+
	"to the hilt. \n");
	set_class(11);
	set_weight(3);
	set_value(300);
	}
