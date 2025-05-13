
inherit "room/room";
#include "/players/trout/defs.h"


reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Daisensei Horiuchi Owari's Room";
	long_desc="This is the personal quarters of the head of this dojo. "+
	"A bed is placed against the eastern wall. Above the fireplace is "+
	"a 6 foot no-dachi. Chests line the west wall. Dansensei is a term "+

	"of great respect for a teacher at 10th black belt or higher. Beware!"+
	"\n ";
	DD= ({ ZZ+"/dojo4.c", "south" });
	items= ({ "bed", "A simple bed. Nice sheets though",
		"fireplace", "A stone fireplace heats the room",
		"chest", "An iron chest containing Horiuchi's personal items"
		});
	CL ({1, 1, "owari", MM+"/owari", 0,
	     });
	::reset(arg);
	MO(CO(WW+"/no_dachi"), TO());
	replace_program("room/room");
	}
