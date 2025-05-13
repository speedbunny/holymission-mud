inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"
#include "/players/shadowmonk/include/vill_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside Joyous..";
    long_desc=   
	"This is the main crossing of Joyous. It is a shame you "+
	"missed the market which was yesterday. The church is "+
	"east of here and connects directly to the market place. "+
	"An small road leads to the west, and at the end you see "+
	"an old man sitting with lots of childeren around him. All "+
	"the childeren seem to listen very concentrated to the old man.\n";
    smell=   
	"You can smell cooked food and freshly washed clothes.";
    dest_dir=({ 
	VILL+"v010", "west",
	VILL+"v005", "north",
	VILL+"v012", "east",
	VILL+"v003", "south",
    });
    items=({ 
	"houses",
	    "Small houses, but clean and pretty good to live in.",
	"house",
	    "Small houses, but clean and pretty good to live in.",
	"church",
	    "It doesnt seem to big church, you can see some dragon statues "+
	    "on it.",
    });
    clone_villagers();
    ::reset(arg);
    replace_program("room/room");
}
