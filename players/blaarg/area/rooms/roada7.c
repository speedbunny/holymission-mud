#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
        set_light(1);
        short_desc="East-West road",
        long_desc=
                "The East-West road runs along the north part of the\n"+
                "village. To the north is Kunoh's house, and to the\n"+
                "south is a mountain.\n";
        dest_dir=({
                AROOMS+"roada6", "west",
                AROOMS+"roada8", "east",
                 });
        items=({ 
            "air","It is quite dusty on this street",
            "road","The road is well-travelled",
	     "house","Kunoh's house is in a state of disrepair, but still "+
			"in good shape.\n",
	     "mountain","The mountain overshadows the rest of the village, "+
			  "it is too high to climb.\n",
              });
        ::reset(arg);
	 replace_program("room/room");
}
