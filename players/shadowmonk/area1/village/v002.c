inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    if (arg) return;

    set_light(1);
    short_desc= 	
	"You are standing in front of a palisade..";
    long_desc= 	
	"The palisade in front of you, looks impassable. It is "+
	"about 10 feet high and surrounds the entire village. "+
	"You see an occasional movement just above the palisade "+
	"which you recognise as the spear of a guardsman walking "+
	"his rounds. The gate is open and right in front of you. "+
	"Two guardsman stand guard and you can ask for admission "+
	"to the village.\n";
    smell=
	"You can smell cooked food and freshly washed clothes.";
    dest_dir=({ 
	VILL+"v003", "north",
	VILL+"v001", "south",
    });
    items=({ 
	"palisade",
	    "Although it looks old, it is very well build and stirdy",
	"gate",
	    "The iron gate is lifted and open.",
    });
    clone_list = ({ 
	 1, 2, "guard", MONS+"guard", 0,
    });
    ::reset(arg);
    replace_program("room/room");
}
