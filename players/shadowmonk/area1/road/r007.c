inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(-1);
    short_desc=   
	"Inside the pine tree area..";
    long_desc=   
	"Everywhere you look you see green. This forest is so incredibly "+
	"dense and the darkness so overwhelming. Peering into your "+
	"surrounding is useless, as all the light of your ligtsource is "+
	"being absorbed. The small path your walking is free of any "+
	"undergrowth, as it winds itself through the forest. The feeling "+
	"of being watched has increased.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r008", "east",
	ROAD+"r006", "west",
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
