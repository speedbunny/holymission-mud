inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"
#include "/players/shadowmonk/include/vill_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside Joyous..";
    long_desc=   
	"This is a longer alley then the one west of here, and you "+
	"see more childeren play here. Further east you can see "+
	"some fields on which crops and other veggies are grown. "+
	"The houses stand somewhat apart here.\n";
    smell=   
	"You can smell cooked food and freshly washed clothes.";
    dest_dir=({ 
	VILL+"v003", "west",
	VILL+"v009", "east",
    });
    items=({ 
	"houses",
	    "Small houses, but clean and pretty good to live in.",
	"house",
	    "Small houses, but clean and pretty good to live in.",
    });
    clone_villagers();
    ::reset(arg);
    replace_program("room/room");
}
