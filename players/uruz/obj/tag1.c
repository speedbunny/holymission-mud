/* tag for stealing from tokugawa */

inherit "obj/thing";
id(str) {return str=="tag1";}
#include "/players/trout/defs.h"

reset(arg){
	set_weight(0);
	set_can_get(1);
	set_value(0);
	}
