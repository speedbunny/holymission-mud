inherit "obj/thing";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg)return;
	set_name("birthday gift");
	set_alias("gift");
	set_can_get(1);
	set_weight(0);
	set_long("It's a birthday gift, all wrapped in paper and bows! "+
	"On top there is a card that says: 'open me!\n");
	set_value(15);
	}
init(){
	::init();
	AA("_open", "open");
	}
int _open(string arg){
	if(arg=="gift" || arg=="birthday gift"){
		write("You open up the birthday gift and a large Trout jumps "+
		"out!\n");
		MO(CO(YY+"/obj/trout.c"), TO());
		return 1;
		}
	return 1;
	}
