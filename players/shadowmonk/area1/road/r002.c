inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"South west from the mountain village Joyous..";
    long_desc=   
	"Being a little closer to the village now, you can see movement "+
	"just above the palisade. The moving objects reflect light into "+
	"your direction now and then, and you recognise them as spearpoints "+
	"of patrolling guards. Just upahead east, the road splits up to "+
	"Joyous, and further east.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r003", "east",
	ROAD+"r001", "west",
    });
    items=({ 
	"village",
	    "It is surrounded by a palisade.",
	"joyous",
	    "It is surrounded by a palisade.",
	"road",
	    "It leads to Joyous, and further east.. maybe to the cliffside.",
    });
    ::reset(arg);
    replace_program("room/room");
}
