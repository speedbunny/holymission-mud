#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
        set_light(1);
        short_desc="East-West road",
        long_desc=
                "The East-West road runs along the north part of the\n"+
                "village. To the north is a side street, and to the\n"+
                "south is a mountain.\n";
        dest_dir=({
                AROOMS+"roada2", "west",
                AROOMS+"roada4", "east",
                AROOMS+"roadd1","north",
                 });
        items=({ 
            "air","It is quite dusty on this street",
            "road","The road is well-travelled",
	     "dojo","The dojo is straight North",
	     "school","A quaint little school beckons you to enter",
              });
        ::reset(arg);
	 replace_program("room/room");
}