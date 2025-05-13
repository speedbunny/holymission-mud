inherit "obj/weapon";
#include "/players/trout/defs.h"

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("kama");
	set_short("Kama");
	set_long("A kama is a small wooden handle, with a curved blade "+
	"attached to the end at a 90 degree angle. It is a common "+
	"farming tool. \n");
	set_class(8);
	set_weight(1);
	set_value(400);
	}
