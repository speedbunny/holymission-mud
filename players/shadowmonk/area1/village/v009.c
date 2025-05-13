inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"
#include "/players/shadowmonk/include/vill_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside Joyous..";
    long_desc=   
	"The fields lead all the way to the palisade. Some villagers "+
	"are working in it, giving the plants water or taking out "+
	"weeds. Looking north you see that the fields run all along "+
	"the east side of the village. From north to south all along "+
	"the palisade.\n";
    smell=   	
	"You can smell fresh healthy digustingly green veggies.";
    dest_dir=({ 
	VILL+"v015", "north",
	VILL+"v008", "west",
    });
    items=({ 
	"fields",
	    "Filled with all kind of green veggies.",
	"palisade",
	    "It leads all around the village and some guards are walking "+
	    "their rounds on it.",
    });
    clone_villagers();
    ::reset(arg);
    replace_program("room/room");
}
