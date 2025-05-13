inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"South from the mountain village Joyous..";
    long_desc=   
	"This is the highest point of the road. It splits here, leading "+
	"north to Joyous, and downwards east. In the distance you see a "+
	"small area of trees, and past that you see a high tower. When the "+
	"sun shines on the tower, it reflects all the light and becomes a "+
	"bright pillar radiating light. Looking north you can see the main "+
	"gate of Joyous. It seems to be guarded by two guards.\n";
    smell=
	"The fresh air makes you feel strong and healthy.";
    dest_dir=({ 
	VILL+"v001", "north",
	ROAD+"r004", "east",
	ROAD+"r002", "west",
    });
    items=({ 
	"village",
	    "It is surrounded by a palisade.",
	"joyous",
	    "It is surrounded by a palisade.",
	"trees",
	    "You can't quite make out what kind they are yet.",
	"tower",
	    "It must have been made of some kind of reflecting material.",
    });
    ::reset(arg);
    replace_program("room/room");
}
