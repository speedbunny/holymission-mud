#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
        set_light(1);
        short_desc="East-West road",
        long_desc=
                "The East-West road runs along the north part of the\n"+
                "village. To the north is a public bath, and to the\n"+
                "south is a mountain.\n";
        dest_dir=({
                AROOMS+"roada3", "west",
                AROOMS+"roada5", "east",
                AROOMS+"bath1", "north",
                 });
        items=({ 
            "air","It is quite dusty on this street",
            "road","The road is well-travelled",
	     "bath","The public bath is colored green, and the doors are "+
		     "open to everyone.\n",
	     "mountain","The mountain overshadows the rest of the village, "+
			  "it is too high to climb.\n",
              });
        ::reset(arg);
	 replace_program("room/room");
}
