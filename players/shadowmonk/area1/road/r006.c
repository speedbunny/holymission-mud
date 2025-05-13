inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(-1);
    short_desc=   
	"Inside the pine tree area..";
    long_desc=   
	"Even though you're in the outer parts of this small forest, you get "+
	"engulfed by darkness. The forest is incredibly dense, and a small "+
	"path leads through the undergrowed east further into the small "+
	"forest, and west to the mountain village of Joyous. You can hear "+
	"the sounds of several animals around you, and you have the distinct "+
	"feeling you are being watched.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r007", "east",
	ROAD+"r005", "west",
    });
    items=({ 
	"undergrowed",
	    "You see lots of old leaves and old branches.",
	"forest",
	    "The darkness makes it an eerie place.",
	"trees",
	    "High, healthy pine trees.",
    });
    ::reset(arg);
    replace_program("room/room");
}
