inherit "room/room";
#include "/obj/door.h"
#include "/players/trout/defs.h"
object obj_1, obj_2;
object guard2, key;
int i;

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Honno Ji Gate";
	long_desc="This is the gate to Honno Ji. The temple is surrounded "+
	"by a high stone wall. The 12 foot iron gate is usually heavily "+
	"guarded. This appears to be the only way in. \n";

	DD= ({ ZZ+"/mroad3", "north",
		ZZ+"/ward4", "south" });

	items= ({ "gate", "It looks pretty solid",
		"wall", "A tall stone wall",

		"Honno Ji", "The temple towers above you, coming gradually "+
		"to a point" });
	MAKE_DOORS("/players/trout/area/gate", "south", "/players/trout/area/ward4", "north", "iron", "gate", "This tall, iron gate looks very strong. \n", 1, 1, 1);
       CL ({ 1, 3, "guard", MM+"/guard1", 0,
	     2, 1, "captain", MM+"/guard2", 0,
	    -2, 1, "key", YY+"/obj/key2", 0 });
	::reset(arg);
	replace_program("room/room");
	}
