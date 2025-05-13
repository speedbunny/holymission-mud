inherit "/players/trout/area/random_guard";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Hallway";
	long_desc="You are standing in the great hall of Honno Ji. Paintings "+		"and pictures fill the walls, telling stories of great battles, and "+
	"fierce warriors. This long hawllway continues to the west and east. "+
	"A door lies to the south. \n";
	DD= ({ ZZ+"/hall1", "west",
		ZZ+"/hall3", "east",
		ZZ+"/recept", "south",
		ZZ+"/ward4", "north" });
	items= ({ "pictures", "Ink sketching of Oda Nobunga",
		"paintings", "Depict the battle of Honno Ji, where Oda "+

		"Nobunga's greatest general led the mutiny to defeat Oda" });
	::reset(arg);
	replace_program("room/room");
	}
