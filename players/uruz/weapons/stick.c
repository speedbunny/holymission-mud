inherit "obj/weapon";
#include "/players/trout/defs.h"

reset(arg) {
	::reset(arg);
	if(arg) return 1;
	set_name("bo staff");
	set_alt_name("bo");
	set_class(2);
	set_short("Bo staff");
	set_long("A wooden bo staff, about 4 feet long. \n");
	set_value(20);
	set_weight(1);
	}
