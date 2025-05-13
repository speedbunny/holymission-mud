inherit "obj/weapon";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("knives");
	set_short("A pair of sharp knives");
	set_alias("pair");
	set_long("This is a pair of knives, custom crafted for each hand. \n");
	set_class(12);
	set_weight(2);
	set_value(400);
	set_two_handed();
	}
