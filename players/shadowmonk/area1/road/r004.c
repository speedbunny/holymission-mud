inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"South east from the mountain village Joyous..";
    long_desc=   
	"The road goes downwards here, and leads into an small area of "+
	"trees a little further east. Being pretty high up in the "+
	"mountains, the trees are pine trees. As far as you can tell from "+
	"here, they look very healthy and are pretty high. The upper part "+
	"of the tower is still visible, and the reflected light hurts your "+
	"eyes when you look directly at the tower.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r005", "east",
	ROAD+"r003", "west",
    });
    items=({ 
	"village",
	    "It is surrounded by a palisade.",
	"joyous",
	    "It is surrounded by a palisade.",
	"trees",
	    "It is a small area of dense healthy pine trees.",
	"tower",
	    "It must have been made of some kind of reflecting material.",
    });
    ::reset(arg);
    replace_program("room/room");
}
