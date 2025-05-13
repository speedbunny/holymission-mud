inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"
#include "/players/shadowmonk/include/vill_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside Joyous..";
    long_desc=   
	"You find yourself now inside the town of Joyous. You can "+
	"hear laughter coming from some of the houses and you see "+
	"kids playing on the street. The atmosphere is pleasent in "+
	"this mountain village. Some goats are grazing the grass. "+
	"A little further north you see the main crossing and a church.\n";
    smell=   
	"You can smell cooked food and freshly washed clothes.";
    dest_dir=({ 
	VILL+"v004", "north",
	VILL+"v008", "east",
	VILL+"v002", "south",
	VILL+"v007", "west",
    });
    items=({ 
	"houses",
	    "Small houses, but clean and pretty good to live in.",
	"house",
	    "Small houses, but clean and pretty good to live in.",
	"church",
	    "It doesnt seem to big church, and from here you can't see any "+
	    "details.",
    });
    clone_villagers();
    ::reset(arg);
    replace_program("room/room");
}
