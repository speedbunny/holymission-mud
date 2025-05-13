inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(0);
    short_desc=   
	"Inside the pine tree area..";
    long_desc=   
	"This is the path leading north to the cliffside. Nothing is "+
	"visible of that right now, and all you see are the trees and "+
	"undergrowth of this pine tree forest. This path seems unused for "+
	"quite some time, as it is almost totally covered by undergrowth.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r013", "north",
	ROAD+"r008", "south",
    });
    items=({ 
	"undergrowth",
	    "You see lots of old leaves and old branches.",
	"forest",
	    "The darkness makes it an eerie place.",
	"trees",
	    "High, healthy pine trees.",
    });
    ::reset(arg);
    replace_program("room/room");
}
