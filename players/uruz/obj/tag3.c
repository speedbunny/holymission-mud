/* tag for attacking wyng kong */
inherit "obj/thing";
id(str) {return str=="tag3";}
#include "/players/trout/defs.h"

reset(arg){
	set_weight(0);
	set_can_get(1);
	set_value(0);
	write("The Wyng Kong just added "+TP()->query_real_name()+" to their "+
		"hit list! \n");
	}
