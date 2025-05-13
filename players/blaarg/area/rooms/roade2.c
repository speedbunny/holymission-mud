#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
        set_light(1);
        short_desc="Side Street",
        long_desc=
                "This side street runs south. To the west is a mountain,\n"+
                "and to the east is Moose's house.\n";
        dest_dir=({
                AROOMS+"roade3", "south",
                AROOMS+"roade1", "north",
                 });
        items=({ 
           "air","It is quite dusty on this street",
           "road","The road is well-travelled",
	    "mountain","The mountain overshadows the rest of the village, "+
			  "it is too high to climb.\n",
	    "house","Moose's house squats to the east",
              });
        ::reset(arg);
	 replace_program("room/room");
}