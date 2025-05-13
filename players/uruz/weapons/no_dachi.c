inherit "obj/weapon";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("no-dachi");
	set_alias("no dachi");
	set_alt_name("sword");
	set_long("This weapon is very similair to a katana, except that it "+
	"is significantly larger than the katana. This weapon was often "+
	"used by samurai warriors in large battles. \n");
        set_class(19);
	set_weight(5);
	set_two_handed();
	set_value(3000);
	}
init(){
	::init();
	AA("_take", "get");
	AA("_take", "take");
	}
_take(str)
	{ if(str=="no-dachi")
	   { if(present("owari", ENV()))
		{ write("You cannot get it with owari here! \n");
		  TP()->MO("no-dachi", ENV());
		  return 1; }
	   }
	}
