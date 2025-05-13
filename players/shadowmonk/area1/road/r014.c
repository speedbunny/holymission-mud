inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"On a path leading to the cliffside..";
    long_desc=   
	"This path leads north to the cliffside and south to a small pine "+
	"tree forest. The cliffside is immense. As you look up you get "+
	"dizzy, as it seems that the cliffsides height has no end and is "+
	"towering out above you.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r015", "north",
	ROAD+"r013", "south",
    });
    items=({ 
	"forest",
	    "The forest seems very dark inside, which makes it an "+
	    "eerie place.",
	"cliffside",
	    "One big mass of rocks, but you cannot see how high it goes.",
    });
    ::reset(arg);
    replace_program("room/room");
}
