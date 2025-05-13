inherit "obj/weapon";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("katana");
	set_alias("sword");
	set_long("A long, sharp katana, with some words written on the hilt."+
	" \n");
	set_class(14);
	set_weight(3);
	set_value(1000);
	set_read("It reads, 'Honno Ji' .");
	}
