inherit "/players/trout/area/random_guard";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Hallway";
	long_desc="You are standing in the great hall of Honno Ji. Paintings "+
	"pictures fill the walls, telling stories of great battles, and "+
	"fierce warriors. The hallway contiunes west. \n";
	DD= ({ ZZ+"/hall2", "west",
		ZZ+"/ward4", "northwest" });
	items= ({ "pictures", "An ink sketching of Akira Matsumai",
		"paintings", "Depicts the battle of Ashbury, where he faced "+
		"the infamous Musashi" });
	::reset(arg);
	replace_program("room/room");
	}
