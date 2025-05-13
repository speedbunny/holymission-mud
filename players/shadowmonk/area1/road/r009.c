inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(0);
    short_desc=   
	"Inside the pine tree area..";
    long_desc=   
	"You find yourself on the winding path leading to the tower that "+
	"you saw before. When the wind blows hard through the forest, and "+
	"the canopy shakes heavily, sharp light flashes peer through it.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r010", "east",
	ROAD+"r008", "west",
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
