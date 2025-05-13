#include "/players/ted/defs.h"

inherit "room/room";

object earth_dragon;

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_light(0);
	short_desc = "Hot Volcanic Cave";
	long_desc =
	"A large pool of molten lava froths and bubbles in\n"+
	"one corner of this cave.\n";
	dest_dir = ({
	  HOT + "red_drag","west"
	});
	items = ({
	  "lava","A pool of molten lava, you can feel the heat from here",
	  "pool","A pool of molten lava, you can feel the heat from here"
	});
    }
    if(!present("earth dragon")) {
	earth_dragon = clone_object("players/ted/monsters/earth_dragon");
	move_object(earth_dragon, this_object());
	call_other("players/ted/random_magic","make_item",earth_dragon,17);
	call_other("players/ted/random_treasure","make_item",earth_dragon,17);
    }
}
