inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"South west from the mountain village Joyous..";
    long_desc=   
	"A little further up this mountain you can see a little "+
	"village known as Joyous. Looking in the distance beyond "+
	"the village you can see an immense cliffside. \n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	ROAD+"r002", "east",
	"/room/church", "church",
    });
    items=({ 
	"village",
	    "It is surrounded by a palisade.",
	"joyous",
	    "It is surrounded by a palisade.",
	"cliffside",
	    "It is a 1000 feet high.",
    });
    ::reset(arg);
    replace_program("room/room");
}
