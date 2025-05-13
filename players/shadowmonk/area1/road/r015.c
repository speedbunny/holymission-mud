inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"On a path leading to the cliffside..";
    long_desc=   
	"You are at the very base of the cliffside right now. Looking "+
	"up only gives you a neck-ache, as the cliffside if just too "+
	"high. You notice a small cave at the end of the path. Back "+
	"south you can see the forest.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r016", "north",
	ROAD+"r014", "south",
    });
    items=({ 
	"forest",
	    "The forest seems very dark inside, which makes it an "+
	    "eerie place.",
	"cliffside",
	    "One big mass of rocks, but you cannot see how high it goes.",
	"cave",
	    "A mann-sized cave at the base of the cliffside.",
    });
    ::reset(arg);
    replace_program("room/room");
}
