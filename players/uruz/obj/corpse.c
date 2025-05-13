inherit "obj/thing";
#include "/players/trout/defs.h"

reset(tick){
	::reset(tick);
	if(tick) return;
	set_can_get(0);
	set_name("corpse");
	switch(RAN(2)){
		case 0:
			set_long("This is a corpse of a Fighting Tong member."+
			" He looks as is he was cut to pieces. His white gi "+
			"is stained red all over. \n");
			break;
		case 1:
			set_long("This is a corpse of a Wyng Kong member. "+
			"His black outfit is stained red. It looks like he "+
			"finally got what he deserved! \n");
			break;
			}
	}
