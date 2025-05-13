#include "/players/ted/defs.h"

inherit "room/room";

object salamander;

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_light(1);
	short_desc = "Burning Desert";
	long_desc =
	"There is nothing but sand dunes baking in the sun\n"+
	"for as far as the eye can see.\n";
	dest_dir = ({
	  HOT + "fire","north",
	});
    }
    if(!present("salamander")) {
	salamander = clone_object("players/ted/monsters/salamander");
	move_object(salamander, this_object());
	call_other("players/ted/random_treasure","make_item",salamander,10);
	call_other("players/ted/random_armor","make_item",salamander,15);
    }
}
