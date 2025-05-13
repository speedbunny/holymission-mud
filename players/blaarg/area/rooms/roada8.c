#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
        set_light(1);
        short_desc="East-West road",
        long_desc=
                "The East-West road runs along the north part of the\n"+
                "village. To the north, south and east lies an impassible\n"+
                "mountain.\n";
        dest_dir=({
                AROOMS+"roada7", "west",
                 });
        items=({ 
           "air","It is quite dusty on this street",
           "road","The road is well-travelled",
	    "mountain","The mountain overshadows the rest of the village, "+
			  "it is too high to climb.\n",
              });
        ::reset(arg);
	 replace_program("room/room");
}