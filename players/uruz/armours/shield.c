inherit "/obj/armour";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	set_name("shield");
	set_short("shield");
	set_ac(1);
	set_weight(1);
	set_value(0);
	}
