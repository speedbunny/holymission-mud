inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(-1);
    short_desc=   
	"Inside the pine tree area..";
    long_desc=   
	"You have arrived at a T-crossing in the middle of this dense pine "+
	"tree forest. It splits the road into three ways, north, east and "+
	"west. The paths leading east and west are free of undergrowth, "+
	"but the one leading north is not. It looks like it hasn't been "+
	"for quite some time.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r012", "north",
	ROAD+"r009", "east",
	ROAD+"r007", "west",
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
