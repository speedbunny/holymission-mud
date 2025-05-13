inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"South from the mountain village Joyous..";
    long_desc=   
	"A little further up this road to the north, you can see a little "+
	"village known as Joyous. Looking in the distance beyond the "+
	"village you can see an immense cliffside. The road leads through "+
	"a small area of pine trees, and the top of a huge tower sticking "+
	"out above it.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	VILL+"v002", "north",
	ROAD+"r003", "south",
    });
    items=({ 
	"tower",
	    "You guess it is about 60 feet high, and very old...",
	"village",
	    "You can hear the buzzling sound of happy working people.",
	"joyous",
	    "You can hear the buzzling sound of happy working people.",
	"cliffside",
	    "It is one big vast mass of rock.. and stretches as far as "+
	    "the eye can see.",
    });
    ::reset(arg);
    replace_program("room/room");
}
