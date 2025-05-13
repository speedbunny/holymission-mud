inherit "/players/trout/area/random_guard";
#include "/players/trout/defs.h"


reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Hallway";
	long_desc= "You stand in the great hall of Honno Ji. Paintings and "+
	"pictures fill the walls, telling stories of great battles, and "+
	"fierce warriors. The hallway continues to the east. \n";

	DD= ({ ZZ+"/hall2","east",
		ZZ+"/ward4", "northeast" });
	items= ({ "paintings", "Paintings of Daimyo Tokugawa Ieyasu locked "+
		"in combat with the dreaded Ryu dragon. One of them shows "+
		"Tokugawa defeating Ryu with a jade fan!",
		"pictures", "Ink sketchings of Tokugawa Ieyasu of Mikawa" });
	::reset(arg);
	replace_program("room/room");
	}
