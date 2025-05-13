inherit "obj/weapon";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("katana");
	set_alias("sword");
	set_long("A long, sharp katana. It has been finely crafted, and "+
	"articulately designed. This is the work of a master swordsmith! \n");
	set_class(18);
	set_weight(3);
	set_value(4500);
	}
