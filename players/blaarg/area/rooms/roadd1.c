#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
        set_light(1);
        short_desc="Side Street",
        long_desc=
                "This side street runs north. To the south is East-West\n"+
                "road, to the west is the Tendo Dojo, and to the east is\n"+
                "the Public Bath.\n";
        dest_dir=({
                AROOMS+"roada3", "south",
                AROOMS+"bath1", "east",
                AROOMS+"roadd2","north",
                 });
        items=({ 
           "air","It is quite dusty on this street",
           "road","The road is well-travelled",
	    "dojo","The dojo looms to the west",
	    "bath","The public bath looks warm and inviting",
              });
        ::reset(arg);
	 replace_program("room/room");
}