inherit "/obj/weapon";
#include "/players/trout/defs.h"

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("tui-fa");
	set_short("Tui-Fa");
	set_long("A type of wooden billyclub with flat sides, and handle. \n");
	set_class(3);
	set_weight(1);
	set_value(50);
	}
