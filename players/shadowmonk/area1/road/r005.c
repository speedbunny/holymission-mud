inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"West from the pine tree area..";
    long_desc=   
	"You're just west of the pine tree area. It looks really dark "+
	"inside it. The pine trees are very healthy and high, and the small"+
	" forest is very dense. Only the very top of the tower is still "+
	"visible above the canopy of the pine tree forest. West from here "+
	"you still can see the palisade of Joyous. As the road leads further"+
	" downwards the further east you go, the cliffside becomes more "+
	"immense too.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r006", "east",
	ROAD+"r004", "west",
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
