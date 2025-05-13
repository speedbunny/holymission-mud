inherit "room/room";
#include "/players/shadowmonk/include/defs.h"

void reset( int arg ) {
    set_light(1);
    short_desc = 
        "You entered a dream lair..\n";
    long_desc = 
        "TEST ROOM FOR WORKROOM!\n";
    dest_dir = ({
	"/room/church", 
            "church",
	"/room/shop", 
            "shop",
	"/room/adv_guild", 
            "adv_guild",
	"/players/sauron/mentor/room/menteeRoom", 
            "mentee",
        HOME+"area1/village/v001",
            "vil",
        HOME+"area1/village/r001",
            "road",
        HOME+"area1/village/vl4_8",
            "val",
    });
    ::reset(arg);
    replace_program("room/room");
}
