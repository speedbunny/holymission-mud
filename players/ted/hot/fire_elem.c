#include "/players/ted/defs.h"

inherit "room/room";

object elemental;

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_light(1);
	short_desc = "Burning waste";
	long_desc =
	"There is nothing but sand dunes baking in the heat as\n"+
	"far as the eye can see.\n";
	dest_dir = ({
	  HOT + "fire","west"
	});
    }
    if(!present("fire elemental")) {
	elemental = clone_object("players/ted/monsters/fire_elemental");
	move_object(elemental, this_object());
	call_other("players/ted/random_armor","make_item",elemental,10);
    }
}
