inherit "obj/weapon";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("fang");
	set_short("Iron Fang");
	set_long("A short iron pipe formed with a piercing tooth at the end"+
	". \n");
	set_class(4);
	set_weight(1);
	set_value(100);
	}
