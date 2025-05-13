#include "/players/ted/defs.h"

inherit "room/room";
object dragon, gem;

init() {
    ::init();
    add_action("east"); add_verb("east");
}

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_light(1);
	short_desc = "Volcanic Cave";
	long_desc =
	"This is a large cave where part of the volcano\n"+
	"cracked. It is very hot, sweat begins to form\n"+
	"on your brow. A strange sound can be heard comming\n"+
	"from an opening to the east.\n";
	dest_dir = ({
	  HOT + "volcano","west",
	  HOT + "earth_drag","east",
	});
    }
    if(!present("red dragon")) {
	dragon = clone_object("players/ted/monsters/red_dragon");
	move_object(dragon, this_object());
	call_other("players/ted/random_treasure","make_item",dragon,15);
	call_other("players/ted/random_magic","make_item",dragon,15);
    }
}

east() {
    if(present("red dragon")) {
	write("The dragon blocks your way.\n");
	return 1;
    }
}
