#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
        set_light(1);
        short_desc="East-West road",
        long_desc=
                "The East-West road runs along the north part of the\n"+
                "village. To the north is a mountain, and to the\n"+
                "south is a side street.\n";
        dest_dir=({
                AROOMS+"roadb5", "west",
                AROOMS+"roadb3", "east",
                AROOMS+"roade1", "south",
                 });
        items=({ 
           "air","It is quite dusty on this street",
           "road","The road is well-travelled",
	    "mountain","The mountain overshadows the rest of the village, "+
			  "it is too high to climb.\n",
	    "street","The side street runs next to the dojo",
	    "dojo","The dojo looms to the north",
              });
	 ::reset(arg);
        replace_program("/room/room");
}