#include "/players/blaarg/defs.h"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
        set_light(1);
        short_desc="Side Street",
        long_desc=
                "This side street runs south. To the west and south\n"+ 
                "is a mountain, and to the east is the forest.\n";
        dest_dir=({
                AROOMS+"roade2", "north",
                 });
        items=({ 
           "air","It is quite dusty on this street",
           "road","The road is well-travelled",
	    "mountain","The mountain overshadows the rest of the village, "+
			  "it is too high to climb.\n",
	    "forest","The forest is too thick to pass through",
              });
        ::reset(arg);
	 replace_program("room/room");
}