#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
       set_light(1);
	short_desc="North Road",
       long_desc=
		"This is the road leading north into the village.\n"+
		"the road is enclosed on either side by\n"+
		"a thick forest.\n";
	items=({
		"road", "The dirt road is well packed",
		"forest", "The forest is too thick to see through",
		"village", "The small village starts to the north, "+
			    "after the forest ends.\n",
        	});
	dest_dir=({
	    AROOMS+"entry", "south",
	    AROOMS+"road2", "north",
		 });
       property = ({
                    "no_steal",
                   });
       smell = "The scent of pines is almost overwhelming.";
	::reset(arg);
       replace_program("room/room");
}
