inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"
#include "/players/shadowmonk/include/vill_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside Joyous..";
    long_desc=   
	"Houses stand on both sides of the road. In some of them "+
	"people are working on something, or being just plain lazy. "+
	"You can see that the old man, that is sitting further north "+
	"from here, has about twenty childeren sitting around him. "+
	"He seems to be telling a very exciting story, because they "+
	"are all silent and are listening very concentrated.\n";
    smell=   	
	"You can smell cooked food and freshly washed clothes.";
    dest_dir=({ 
	VILL+"v011", "west",
	VILL+"v004", "east",
    });
    items=({ 
	"houses",
	    "Small houses, but clean and pretty good to live in.",
	"house",
	    "Small houses, but clean and pretty good to live in.",
	"man",
	    "He seems to be well passed eigthy with his long white beard.",
	"childeren",
	    "They are all around the age of eight to twelve, and enjoying "+
	    "the story.",
    });
    clone_villagers();
    ::reset(arg);
    replace_program("room/room");
}
