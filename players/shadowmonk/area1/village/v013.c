inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"
#include "/players/shadowmonk/include/vill_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside Joyous..";
    long_desc=   
	"This is a small alley, where there are five houses which are all "+
	"connected to each other. Behind the windows you see people "+
	"sitting in chairs and reading, just working on something "+
	"or playing with their childeren.\n";
    smell=   	
	"You can smell cooked food and freshly washed clothes.";
    dest_dir=({ 
	VILL+"v005", "east",
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
