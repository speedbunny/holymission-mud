/* Tag for attacking fighting tong */
inherit "obj/thing";
id(str) {return str=="tag2";}
#include "/players/trout/defs.h"

reset(arg){
	set_weight(0);
	set_can_get(1);
	set_value(0);
	write("The Fighting Tong just added "+TP()->query_real_name()+" to "+
		"their list of enemies! \n");
	}
