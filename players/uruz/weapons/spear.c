inherit "obj/weapon";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("spear");
	set_class(10);
	set_weight(3);
	set_value(300);
	set_long("A large wooden spear, with a very sharp edge. \n");
	}
