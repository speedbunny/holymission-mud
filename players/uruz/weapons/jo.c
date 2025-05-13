inherit "obj/weapon";
#include "/players/trout/defs.h"

reset(arg) {
	::reset(arg);
	if(arg) return 1;
	set_name("jo staves");
	set_alias("staves");
	set_alt_name("pair");
	set_class(9);
	set_short("A pair of jo staves");
	set_long("This is a pair of jo staves. Each staff is a smaller "+
	"version of a bo staff, and can be held with one hand. When two are "+
	"used together skillfully, it can make for a formitable weapon. \n");
	set_value(200);
	set_weight(2);
	set_two_handed();
	}
