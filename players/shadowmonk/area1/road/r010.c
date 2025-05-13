inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(0);
    short_desc=   
	"Inside the pine tree area..";
    long_desc=   
	"This is the east edge of this small pine tree forest. You see "+
	"bright light pouring in just a little further east, where this "+
	"path leaves the forest. The trees and undergrowth are of a "+
	"lighter green then in the other parts of the forest.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r011", "east",
	ROAD+"r009", "west",
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
