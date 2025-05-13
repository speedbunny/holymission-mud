inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"
#include "/players/shadowmonk/include/vill_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside Joyous..";
    long_desc=   
	"This is the northeastern part of Joyous and you have a "+
	"perfect view on the fields on which the villagers of Joyous "+
	"grow there veggies. You see some guards walking their rounds "+
	"on the palisade. The fields run all along the palisade.\n";
    smell=   	
	"You can smell fresh healthy digustingly green veggies.";
    dest_dir=({ 
	VILL+"v009", "south",
	VILL+"v014", "west",
    });
    items=({ 
	"fields",
	  "Filled with all kind of green veggies.",
	"palisade",
	  "It leads all around the village and some guards are walking their rounds on it.",
    });
    clone_villagers();
    ::reset(arg);
    replace_program("room/room");
}
