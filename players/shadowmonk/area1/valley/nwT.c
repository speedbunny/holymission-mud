inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Northwest tower..";
    long_desc=   
	"Northwest tower...\n";
    dest_dir=({ 
	VALL+"vl1_0", "east",
	VALL+"vl0_1", "south",
    });
    ::reset(arg);
    replace_program("room/room");
}
