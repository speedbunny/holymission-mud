inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"
#include "/players/shadowmonk/include/vill_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside Joyous..";
    long_desc=   
	"North from here you can see the palisade surrounding the village, "+
	"and behind that the inmense cliffside. Fields with crops run from "+
	"here to the palisade, and you see men and woman work in them. "+
	"Some childerent are being warned not to play in the fields. You "+
	"can see the small backyards of the houses here on the edge of the "+
	"fiels. The church is just to the southeast of here.\n";
    smell=   
	"You can smell fresh healthy digustingly green veggies.";
    dest_dir=({ 
	VILL+"v014", "east",
	VILL+"v004", "south",
	VILL+"v013", "west",
    });
    items=({ 
	"houses",
	    "Small houses, but clean and pretty good to live in.",
	"house",
	    "Small houses, but clean and pretty good to live in.",
	"fields",
	    "Filled with all kind of green veggies.",
	"palisade",
	    "It leads all around the village and some guards are walking "+
	    "their rounds on it.",
	"church",
	    "It doesnt seem to be a big church, and from here you can't "+
	    "see any details.",
    });
    clone_villagers();
    ::reset(arg);
    replace_program("room/room");
}
