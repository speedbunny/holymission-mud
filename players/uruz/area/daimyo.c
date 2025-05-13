inherit "room/room";

#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Daimyo's Chambers";
	long_desc="This is the personal chambers of Daimyo Tokugawa Ieyasu. "+
	"This room is huge, and exquisitely furnished. ONe one side of the "+
	"room is a lavish bed. It is divided from the rest of the room by "+

	"thick, dark drapes, suspended from the ceiling. There is an "+	
	"array of chairs, couches, and tables at the far end. The objects "+

	"in this room alone are worth a small fortune! \n";
	DD= ({ ZZ+"/throne", "west",
		ZZ+"/guard2", "south" });
	clone_list = ({1, 2, "guard", MM+"/guard2", 0 });
	::reset(arg);
	replace_program("room/room");
	}
