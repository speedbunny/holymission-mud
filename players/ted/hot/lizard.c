#include "/players/ted/defs.h"

inherit "room/room";

object lizard;

reset(arg) {
    int i;
    ::reset(arg);
    if(!arg) {
	set_light(1);
	short_desc = "Burning waste";
	long_desc =
	"There is nothing but sand dunes baking in the sun\n"+
	"for as far as the eye can see.\n";
	dest_dir = ({
	  HOT + "fire","east",
	});
    }
    if(!present("fire lizard")) {
	i = 0;
	while(i < 4) {
	    i ++;
	    lizard = clone_object("players/ted/monsters/fire_lizard");
	    move_object(lizard, this_object());
	    call_other("players/ted/random_treasure","make_item",lizard,8);
	}
    }
}
