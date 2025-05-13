#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
        set_light(1);
        short_desc="East-West road",
        long_desc=
                "The East-West road runs along the north part of the\n"+
                "village. To the north is Tendo's dojo, and to the\n"+
                "south is the High School.\n";
        dest_dir=({
                AROOMS+"road8", "west",
                AROOMS+"roada2", "east",
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