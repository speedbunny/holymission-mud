inherit "obj/weapon";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return 1;
	set_name("wakazashi");
	set_alias("short sword");
	set_class(13);
	set_weight(2);
	set_value(1500);
	set_short("Wakazashi");
	set_long("This is a wakazashi, the short short of a samurai. "+
	"It looks like a smaller version of a katana. It is very sharp."+
	" Be careful. \n");
	}
