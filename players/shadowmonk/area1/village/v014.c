inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"
#include "/players/shadowmonk/include/vill_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside Joyous..";
    long_desc=   
	"Some local shops are gathered here. You can see a baker, "+
	"butcher and a petshop. They look all rather full with "+
	"villagers, so unless you like to wait hours for what you "+
	"want, stay out of them. Loads of childeren are "+
	"playing here, waiting for their moms to return.\n";
    smell=   	
	"You can smell fresh baked bread.";
    dest_dir=({ 
	VILL+"v015", "east",
	VILL+"v005", "west",
    });
    items=({ 
	"shops",
	  "Small little shops, but good enough for Joyous..",
	"shop",
	  "Small little shops, but good enough for Joyous..",
	"baker",
	  "Small little shops, but good enough for Joyous..",
	"butcher",
	  "Small little shops, but good enough for Joyous..",
	"petshop",
	  "Small little shops, but good enough for Joyous..",
    });
    clone_villagers();
    ::reset(arg);
    replace_program("room/room");
}
