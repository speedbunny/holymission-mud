#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
        set_light(1);
        short_desc="Side Street",
        long_desc=
                "This side street runs north. To the west is the\n"+ 
                "Tendo Dojo, and to the east and north is a mountain.\n";
        dest_dir=({
                AROOMS+"roadd3", "south",
                 });
        items=({ 
           "air","It is quite dusty on this street",
           "road","The road is well-travelled",
	    "dojo","The dojo looms to the west",
	    "mountain","The mountain overshadows the rest of the village, "+
			  "it is too high to climb.\n",
              });
        ::reset(arg);
	 replace_program("room/room");
}