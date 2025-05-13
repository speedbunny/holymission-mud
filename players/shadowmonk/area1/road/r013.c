inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(0);
    short_desc=   
	"Inside the pine tree area..";
    long_desc=   
	"This is the north edge of this small pine tree forest. You see "+
	"bright light pouring in just a little further north, where this "+
	"path leaves the forest. The cliffside is clearly visible from "+
	"here although you cannot see how high it runs, as the canopy "+
	"blocks your vision.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r014", "north",
	ROAD+"r012", "south",
    });
    items=({ 
	"undergrowth",
	    "You see lots of old leaves and old branches.",
	"forest",
	    "The darkness makes it an eerie place.",
	"trees",
	    "High, healthy pine trees.",
	"cliffside",
	    "One big mass of rocks.",
    });
    ::reset(arg);
    replace_program("room/room");
}
