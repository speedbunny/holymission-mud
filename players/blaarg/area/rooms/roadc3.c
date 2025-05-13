#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
        set_light(1);
        short_desc="Side street",
        long_desc=
                "This side street runs North. To the east is the Tendo\n"+ 
                "Dojo and to the west is a mountain.\n";
        dest_dir=({
                AROOMS+"roadc2", "south",
                AROOMS+"roadc4","north",
                 });
        items=({ 
           "air","It is quite dusty on this street",
           "road","The road is well-travelled",
	    "dojo","The dojo looms to the east",
	    "mountain","The mountain overshadows the rest of the village, "+
			  "it is too high to climb.\n",
              });
        ::reset(arg);
	 replace_program("room/room");
}